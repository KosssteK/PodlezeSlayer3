#include "NetworkManager.h"
#include "player/PlayerManager.h"
#include <iostream>
#include <string>
#include "config/Properties.h"


NetworkManager::NetworkManager()
{
	if (enet_initialize() != 0)
	{
		fprintf(stderr, "An error occurred while initializing ENet.\n");
	}
	atexit(enet_deinitialize);
}

void NetworkManager::init(sf::RenderWindow & window)
{
	client = enet_host_create(NULL /* create a client host */,
		1 /* only allow 1 outgoing connection */,
		2 /* allow up 2 channels to be used, 0 and 1 */,
		0 /* assume any amount of incoming bandwidth */,
		0 /* assume any amount of outgoing bandwidth */
	);
	if (client == NULL)
	{
		fprintf(stderr,
			"An error occurred while trying to create an ENet client host.\n");
		exit(EXIT_FAILURE);
	}

	enet_address_set_host(&address, Properties::getSingleton().getServerIP());
	address.port = Properties::getSingleton().getServerPort();

	peer = enet_host_connect(client, &address, 2, 0);
	if (peer == NULL)
	{
		fprintf(stderr,
			"No available peers for initiating an ENet connection.\n");
		exit(EXIT_FAILURE);
	}
	connectID = peer->connectID;
	std::cout << connectID << std::endl;


	if (enet_host_service(client, &event, Properties::getSingleton().getConnectTime()) > 0 &&
		event.type == ENET_EVENT_TYPE_CONNECT)
	{
		puts("Connection to some.server.net:1234 succeeded.");
	}else{
		/* Either the 5 seconds are up or a disconnect event was */
		/* received. Reset the peer in the event the 5 seconds   */
		/* had run out without any significant event.            */
		enet_peer_reset(peer);
		puts("Connection to some.server.net:1234 failed.");
	}
}

void NetworkManager::update(sf::RenderWindow & window)
{
	if (enet_host_service(client, &event, 20) >= 0)
	{
		//printf("A new client connected from %x:%u.\n");
		switch (event.type)
		{
		case ENET_EVENT_TYPE_RECEIVE:
			recivedData = reinterpret_cast<char*>(event.packet->data);
			//std::cout << " <---->  Recived " << recivedData << std::endl;
			if (recivedData[0] == 'N') {
				recivedData.erase(0, 2);
				registerNewPlayer(recivedData);
			}
			if (recivedData[0] == 'U') {
				recivedData.erase(0, 2);
				updateGameState(recivedData);
			}
			recivedData.clear();
			/* Clean up the packet now that we're done using it. */
			enet_packet_destroy(event.packet);
			break;

		}
	}
}

void NetworkManager::draw(sf::RenderWindow & window)
{
}

void NetworkManager::registerNewPlayer(std::string& data)
{
	int playerCount = getNextElement(data);
	for (int i = 0; i < playerCount; i++) {

		int currentID = getNextElement(data);
		if (connectID != currentID) {
			PlayerManager::getSingleton().registerNewPlayer(currentID, i);
		}
		else {
			PlayerManager::getSingleton().setPlayerPosition(sf::Vector2f(Properties::getSingleton().getStartingPosition(i, 0), Properties::getSingleton().getStartingPosition(i, 1)));
			std::cout << "----->> the same player!" << std::endl;
		}
	}
}

void NetworkManager::updateGameState(std::string data) 
{
	unsigned long enemyID = getNextElement(data);
	if (enemyID != connectID) {
		int directionX = (int)getNextElement(data);
		int directionY = (int)getNextElement(data);
		sf::Vector2f enemyPosition(directionX, directionY);

		PlayerManager::getSingleton().getEnemy(enemyID).updatePosition(enemyPosition);
		float rotation = (int)getNextElement(data);
		PlayerManager::getSingleton().getEnemy(enemyID).setRotation(rotation);
	}
	
}

void NetworkManager::sendUpdatedData(sf::Vector2f vetor, float rotation)
{
	std::string packetData;

	packetData += "U:" + std::to_string(connectID) + ":" + std::to_string(vetor.x) + ":" + std::to_string(vetor.y) + ":" + std::to_string(rotation);

	ENetPacket * packet = enet_packet_create(packetData.c_str(),
		strlen(packetData.c_str()) + 1,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	enet_host_flush(client);
}

unsigned long NetworkManager::getNextElement(std::string & data)
{
	int semicolonIndex = data.find(":");
	std::string cutString = data.substr(0, semicolonIndex);
	unsigned long finalValue = std::stoul(cutString);
	data.erase(0, data.find(":") + 1);
	return finalValue;
}



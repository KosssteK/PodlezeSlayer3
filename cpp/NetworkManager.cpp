#include "NetworkManager.h"
#include <iostream>
#include <string>


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

	enet_address_set_host(&address, "localhost");
	address.port = 1234;

	peer = enet_host_connect(client, &address, 2, 0);
	if (peer == NULL)
	{
		fprintf(stderr,
			"No available peers for initiating an ENet connection.\n");
		exit(EXIT_FAILURE);
	}
	if (enet_host_service(client, &event, 5000) > 0 &&
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
	//std::string tekst;
	//std::getline(std::cin, tekst);
	////const char* msg = "data: " + (char*)tekst;
	//ENetPacket * packet = enet_packet_create(tekst.c_str(),
	//	strlen(tekst.c_str()) + 1,
	//	ENET_PACKET_FLAG_RELIABLE);
	//enet_peer_send(peer, 0, packet);
	//enet_host_flush(client);


	if (enet_host_service(client, &event, 10) >= 0)
	{
		//printf("A new client connected from %x:%u.\n");
		switch (event.type)
		{
		case ENET_EVENT_TYPE_RECEIVE:
			//std::cout << "A packet of length " << event.packet->dataLength <<
			//	" containing " << event.packet->data <<
			//	" was received from " << *((int*)event.peer->data) <<
			//	" on channel " << event.channelID <<
			//	"." << std::endl;
			std::cout << "recived " << event.packet->data << std::endl;
			/* Clean up the packet now that we're done using it. */
			enet_packet_destroy(event.packet);

			break;

		}
	}
}

void NetworkManager::draw(sf::RenderWindow & window)
{
}

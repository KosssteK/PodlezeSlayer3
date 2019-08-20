#pragma once
#include <SFML/Graphics.hpp>
#include <enet/enet.h>

class NetworkManager
{
	ENetHost * client;
	ENetAddress address;
	ENetEvent event;
	ENetPeer *peer;
	unsigned long connectID;
	std::string recivedData;

	NetworkManager();
	NetworkManager(const NetworkManager &);
public:
	static NetworkManager & getSingleton()
	{
		static NetworkManager singleton;
		return singleton;
	}
	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void disconnect();

	void registerNewPlayer(std::string& data);
	void updateGameState(std::string data);
	void sendUpdatedData(sf::Vector2f playerPosition, float rotation, unsigned long enemyID);

	unsigned long getPlayerID();

private:
	unsigned long getNextElement(std::string& data);
	std::string getNextStringElement(std::string& data);
};
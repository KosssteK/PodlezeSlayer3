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

	void registerNewPlayer(std::string& data);
	void updateGameState(std::string data);
	void sendUpdatedData(sf::Vector2f playerPosition);


private:
	unsigned long getNextElement(std::string& data);
};
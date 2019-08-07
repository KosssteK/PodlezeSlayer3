#pragma once
#include <SFML/Graphics.hpp>
#include <enet/enet.h>

class NetworkManager
{
	ENetHost * client;
	ENetAddress address;
	ENetEvent event;
	ENetPeer *peer;

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
};
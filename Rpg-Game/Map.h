#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map
{
private:
	sf::Texture tileSheetTexture;

	Tile* tiles;

	int totalTiles;

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;

	int mapNumbers[6] = {
		1, 1, 1,
		24, 26, 29
	};

	sf::Sprite mapSprites[6];

public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};


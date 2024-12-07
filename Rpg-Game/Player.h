#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"

class Player
{
private:
	sf::Texture texture;
	
	std::vector<Bullet> bullets;
	float maxFireRate;
	float fireRateTimer;
	float playerSpeed;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	Player();
	~Player();

	void Initialize();
	void Load(); 
	void Update(float deltatTime, Skeleton& skeleton, sf::Vector2f& mousePos);
	void Draw(sf::RenderWindow& window);
};


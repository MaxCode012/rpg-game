#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{

}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        std::cout << "Success";
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(400, 100));

        int xIndex = 8;
        int yIndex = 3;

        sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
    }

    else {
        std::cout << "Fail";
    }
}

void Skeleton::Update()
{

}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
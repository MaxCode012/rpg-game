#include "Player.h"
#include "Math.h"
#include <iostream>

void Player::Initialize()
{
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Success";
        sprite.setTexture(texture);

        int xIndex = 0;
        int yIndex = 0;

        sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
    }
    else {
        std::cout << "Fail";
    }
}

void Player::Update(Skeleton& skeleton)
{
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0, -1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 1));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        sf::RectangleShape newBullet(sf::Vector2f(50, 25));
        bullets.push_back(newBullet);

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDir = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDir = Math::NormalizeVector(bulletDir);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDir * bulletSpeed);

    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }

}

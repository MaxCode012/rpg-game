#include "Player.h"
#include "Math.h"
#include <iostream>

Player::Player() : bulletSpeed(0.5f), playerSpeed(1.0f)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
    
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Success";
        sprite.setTexture(texture);

        int xIndex = 0;
        int yIndex = 0;

        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, 64, 64));

        sprite.scale(sf::Vector2f(3, 3));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else {
        std::cout << "Fail";
    }
}

void Player::Update(float deltaTime, Skeleton& skeleton)
{
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);

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
        bullets[i].setPosition(bullets[i].getPosition() + bulletDir * bulletSpeed * deltaTime);

    }
    boundingRectangle.setPosition(sprite.getPosition());

    if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
    {
        std::cout << "cOllision" << std::endl;
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }

}

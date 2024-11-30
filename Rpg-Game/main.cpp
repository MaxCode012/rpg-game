#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector) {
    float m = std::sqrt(vector.x* vector.x + vector.y + vector.y);
    
    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;
}

int main()
{
    //---------------------------------- INITIALIZE -----------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 720), "RPG Game", sf::Style::Default, settings);
    //---------------------------------- INITIALIZE -----------------------
    
    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.5f;

    //---------------------------------- LOAD -----------------------

    //---------------------------------- Enemy -----------------------

    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    if (enemyTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
            std::cout << "Success";
            enemySprite.setTexture(enemyTexture);
            enemySprite.setPosition(sf::Vector2f(400, 100));

            int xIndex = 8;
            int yIndex = 3;

            enemySprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
            enemySprite.scale(sf::Vector2f(3, 3));
    }
    
    else {
        std::cout << "Fail";
    }
    //---------------------------------- Enemy -----------------------

    //---------------------------------- Player -----------------------

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Success";
        playerSprite.setTexture(playerTexture);

        int xIndex = 0;
        int yIndex = 0;

        playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        playerSprite.scale(sf::Vector2f(3, 3));
    }
    else {
        std::cout << "Fail";
    }
    //---------------------------------- Player -----------------------

    //---------------------------------- LOAD -----------------------


    while (window.isOpen()) {

        //---------------------------------- UPDATE -----------------------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed())
                window.close();
        }

        //bullet.setPosition(bullet.getPosition() + bulletDir * bulletSpeed);

        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
        {
            sf::RectangleShape newBullet(sf::Vector2f(50, 25));
            bullets.push_back(newBullet);

            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f bulletDir = enemySprite.getPosition() - bullets[i].getPosition();
            bulletDir = NormalizeVector(bulletDir);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDir * bulletSpeed);
    
        }
    
        //---------------------------------- UPDATE -----------------------

        window.clear(sf::Color::Black);

        window.draw(playerSprite);
        window.draw(enemySprite);
        
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }

        window.display();
    }

    return 0;
}
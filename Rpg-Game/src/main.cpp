#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.h"
#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"

#include "MapLoader.h"

int main()
{
    //---------------------------------- INITIALIZE -----------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 720), "RPG Game", sf::Style::Default, settings);
    window.setFramerateLimit(240);
    //---------------------------------- INITIALIZE -----------------------
    
    
    FrameRate frameRate;
    Map map;
    Player player;
    Skeleton skeleton;

    MapLoader mapLoader;
    mapLoader.Load("Assets/Maps/Level 1.txt");
    
    //---------------------------------- INITIALIZE -----------------------

    frameRate.Initialize();
    map.Initialize();
    player.Initialize();
    skeleton.Initialize();
    
    //---------------------------------- INITIALIZE -----------------------


    //---------------------------------- LOAD -----------------------
    
    frameRate.Load();
    map.Load();
    player.Load();
    skeleton.Load();

    //---------------------------------- LOAD -----------------------

        sf::Clock clock;

    while (window.isOpen()) {

        //---------------------------------- UPDATE -----------------------
        
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds() /1000.0f;
        

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed())
                window.close();
        }

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        
        frameRate.Update(deltaTime);
        map.Update(deltaTime);
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton, mousePos);
    
        //---------------------------------- UPDATE -----------------------

        window.clear(sf::Color::Black);
        map.Draw(window);
        player.Draw(window);
        skeleton.Draw(window);
        frameRate.Draw(window);

        window.display();

    }

    return 0;
}
//============================================================================
// Name        : Ou_est_le_beurre.cpp
// Author      : Johannes Hofmann (coolster Bruder)
//============================================================================

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/Game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(globals::WIDTH, globals::HEIGHT), "Ou est le beurre?");
    window.setFramerateLimit(globals::FPS);
    Game game;

    // delta_t + clock
    sf::Clock clock;
    float delta_t = 0;          // TODO change to sf::Time

    while (window.isOpen())
    {
    	// get delta_t
    	delta_t = clock.restart().asSeconds();

        // TODO input

        game.setKeyReleased(sf::Keyboard::Unknown);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased)
            {
            	game.setKeyReleased(event.key.code);
            }
        }

        // update
        game.update(delta_t);


        // draw
        game.draw(window);

    }

    return 0;
}

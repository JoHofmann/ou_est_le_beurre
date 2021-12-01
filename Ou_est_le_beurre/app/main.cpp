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
    Game game;

    while (window.isOpen())
    {
        // TODO input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // update
        game.update(0);


        // draw
        game.draw(window);

    }

    return 0;
}

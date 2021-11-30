//
// Created by paddy on 30.11.21.
//

#ifndef OUESTLEBEURRE_GAME_HPP
#define OUESTLEBEURRE_GAME_HPP

#include <SFML/Graphics.hpp>
#include "ou_est_le_beurre/globals.hpp"
#include <string>

class Game {
public:
    // public functions
    Game();
    ~Game();

    void update(float);
    void draw(sf::RenderWindow &);

private:
    // textrue
    sf::Texture t_player;
    sf::Sprite player;

};


#endif //OUESTLEBEURRE_GAME_HPP

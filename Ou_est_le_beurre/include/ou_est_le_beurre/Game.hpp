//
// Created by paddy on 30.11.21.
//

#ifndef OUESTLEBEURRE_GAME_HPP
#define OUESTLEBEURRE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/Player.hpp"


class Game {
public:
    // public functions
    Game();
    ~Game();

    void update(float);
    void draw(sf::RenderWindow &);

private:
    // player
    Player player;

};


#endif //OUESTLEBEURRE_GAME_HPP

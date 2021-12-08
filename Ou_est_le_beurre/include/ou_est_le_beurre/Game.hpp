//
// Created by paddy on 30.11.21.
//

#ifndef OUESTLEBEURRE_GAME_HPP
#define OUESTLEBEURRE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/Player.hpp"
#include "ou_est_le_beurre/Textbox.hpp"
#include "ou_est_le_beurre/GameObject.hpp"


class Game {
public:
    // public functions
    Game();
    ~Game();

    void update(float);
    void draw(sf::RenderWindow &);

private:

    // pointer on GameObjects
    std::shared_ptr<Player> pPlayer;
    std::shared_ptr<Textbox> pTextbox;

    // GameObject Vector
    std::vector<std::shared_ptr<GameObject>> gameObjects;
};


#endif //OUESTLEBEURRE_GAME_HPP

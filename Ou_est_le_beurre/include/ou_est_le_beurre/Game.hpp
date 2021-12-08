//
// Created by paddy on 30.11.21.
//

#ifndef OUESTLEBEURRE_GAME_HPP
#define OUESTLEBEURRE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/Player.hpp"
#include "ou_est_le_beurre/Textbox.hpp"
#include "ou_est_le_beurre/State.hpp"


class Game {
public:
    // public functions
    Game();
    ~Game();

    void update(float);
    void draw(sf::RenderWindow &);

    // *** Getter and Setter ***
    const Textbox &getTextbox() const;

private:
    // player
    Player player;
    Textbox textbox;

    // state machine
    void updateStateMachine(float);
    std::vector<State *> states;
    std::vector<State *>::iterator stateIterator;

};


#endif //OUESTLEBEURRE_GAME_HPP

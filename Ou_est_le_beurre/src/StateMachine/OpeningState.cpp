//
// Created by paddy on 20.12.21.
//

#include "ou_est_le_beurre/OpeningState.hpp"


OpeningState::OpeningState(Game const *game) : State(game){
    pTextbox = game->getPTextbox();
    // TODO initialize scene
    // TODO momy at door
    // TODO lock player control
}

bool OpeningState::goalReached() {
    return false;
}

void OpeningState::processState() {
    // TODO fade in scene
    // TODO show intro text

}
sf::RectangleShape transitionRectangle{ sf::Vector2f(100, 100) };
sf::Uint8 transitionRectangleAlphaChannel = 0;

enum class superiorBool { Uninitialized, True, False };
superiorBool someBool = superiorBool::True;

sf::Clock transitionClock;

void transition()
{
    transitionRectangle.setFillColor(sf::Color(0, 0, 0, transitionRectangleAlphaChannel));

    if (transitionClock.getElapsedTime().asSeconds() > 0.1f && transitionRectangleAlphaChannel < 255.f && someBool == superiorBool::True)
    {
        transitionRectangleAlphaChannel += 5;
        transitionClock.restart();

        if (transitionRectangleAlphaChannel == 255)
        {
            someBool = superiorBool::False;
        }

    }
    else if (transitionClock.getElapsedTime().asSeconds() > 0.1f && transitionRectangleAlphaChannel > 0.f && someBool == superiorBool::False)
    {
        transitionRectangleAlphaChannel -= 5;
        transitionClock.restart();

        if (transitionRectangleAlphaChannel == 0)
        {
            someBool = superiorBool::Uninitialized;
        }
    }
}

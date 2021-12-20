//
// Created by paddy on 20.12.21.
//

#include <iostream>
#include "ou_est_le_beurre/FadeObject.hpp"



void FadeObject::update(float delta_t) {
    if(this->get_enabled()){
        // update fade transition
        transition();
    }
}

void FadeObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(this->enabled){
        target.draw(transitionRectangle);
    }
}

void FadeObject::transition()
{
    transitionRectangle.setFillColor(sf::Color(255, 255, 255, sf::Uint8(transitionRectangleAlphaChannel)));

    transitionRectangleAlphaChannel -= 255.0f / (globals::FPS * FADE_DURATION.asSeconds());       // fade value
    if (transitionRectangleAlphaChannel <= 0.0f)
    {
        this->set_enabled(false);
    }

}

FadeObject::FadeObject() {
   // init rectangle
    transitionRectangle = sf::RectangleShape(sf::Vector2f(globals::WIDTH, globals::HEIGHT));
    this->set_enabled(false);
}

void FadeObject::startFade() {
    transitionRectangleAlphaChannel = 255;

    this->set_enabled(true);
}

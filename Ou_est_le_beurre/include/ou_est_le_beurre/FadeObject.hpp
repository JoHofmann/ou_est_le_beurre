//
// Created by paddy on 20.12.21.
//

#ifndef OUESTLEBEURRE_FADEOBJECT_HPP
#define OUESTLEBEURRE_FADEOBJECT_HPP

#include "ou_est_le_beurre/GameObject.hpp"

class FadeObject : public GameObject {
public:
    FadeObject();

    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void update(float) override;
    void startFade();

private:
    const sf::Time FADE_DURATION = sf::seconds(10.0f);

    sf::RectangleShape transitionRectangle;
    float transitionRectangleAlphaChannel;

    void transition();

};


#endif //OUESTLEBEURRE_FADEOBJECT_HPP

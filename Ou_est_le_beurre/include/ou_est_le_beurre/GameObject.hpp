//
// Created by paddy on 06.12.21.
//

#ifndef OUESTLEBEURRE_GAMEOBJECT_HPP
#define OUESTLEBEURRE_GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "ou_est_le_beurre/globals.hpp"

class GameObject : public sf::Drawable {
public:
    virtual void update(float) = 0;

    // *** Getter and Setter ***
    virtual void set_enabled(bool);
    virtual bool get_enabled();
    virtual const sf::Vector2f &getPosition() const;
    virtual void setPosition(const sf::Vector2f &pos);
    virtual const sf::IntRect &getShape() const;
    virtual void setShape(const sf::IntRect &shape);

protected:
    bool enabled;
    // TODO implement scale to zoom


private:
    sf::Vector2f position;
    sf::IntRect shape;
};


#endif //OUESTLEBEURRE_GAMEOBJECT_HPP

//
// Created by paddy on 06.12.21.
//

#ifndef OUESTLEBEURRE_GAMEOBJECT_HPP
#define OUESTLEBEURRE_GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "ou_est_le_beurre/globals.hpp"

class GameObject : public sf::Drawable{
public:
    virtual void update(float);

    // *** Getter and Setter ***
    virtual void set_enabled(bool);
    virtual bool get_enabled();
    virtual const sf::Vector2f &getPos() const;
    virtual void setPos(const sf::Vector2f &pos);
    virtual const sf::FloatRect &getShape() const;
    virtual void setShape(const sf::FloatRect &shape);

protected:
    sf::Vector2f pos;
    sf::FloatRect shape;
    bool enabled;


private:
};


#endif //OUESTLEBEURRE_GAMEOBJECT_HPP

//
// Created by paddy on 06.12.21.
//

#include "ou_est_le_beurre/GameObject.hpp"

const sf::Vector2f &GameObject::getPos() const {
    return pos;
}

void GameObject::setPos(const sf::Vector2f &pos) {
    GameObject::pos = pos;
}

const sf::FloatRect &GameObject::getShape() const {
    return shape;
}

void GameObject::setShape(const sf::FloatRect &shape) {
    GameObject::shape = shape;
}

void GameObject::set_enabled(bool enabled) {
    GameObject::enabled - enabled;
}

bool GameObject::get_enabled() {
    return enabled;
}

//
// Created by paddy on 06.12.21.
//

#include "ou_est_le_beurre/GameObject.hpp"

const sf::Vector2f &GameObject::getPosition() const {
    return position;
}

void GameObject::setPosition(const sf::Vector2f &position) {
    GameObject::position = position;
}

const sf::IntRect &GameObject::getShape() const {
    return shape;
}

void GameObject::setShape(const sf::IntRect &shape) {
    GameObject::shape = shape;
}

void GameObject::set_enabled(bool enabled) {
    GameObject::enabled - enabled;
}

bool GameObject::get_enabled() {
    return enabled;
}

//
// Created by paddy on 05.12.21.
//

#include "ou_est_le_beurre/Textbox.hpp"

#include <iostream>

Textbox::Textbox(const std::string &name) {
    if(!texture.loadFromFile(TEXTURES_PATH + name)){
        std::cerr << "error while loading Textbox texture" << std::endl;
    }

    this->setTexture(texture);
    this->setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));

    // init player position in middle
    this->setPosition(position_offset, globals::HEIGHT - get_height() - position_offset);
}

unsigned int Textbox::get_width() {
    return texture.getSize().x * this->getScale().x;
}

unsigned int Textbox::get_height() {
    return texture.getSize().y * this->getScale().y;
}


Textbox::~Textbox() = default;

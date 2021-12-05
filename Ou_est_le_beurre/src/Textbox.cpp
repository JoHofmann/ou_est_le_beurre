//
// Created by paddy on 05.12.21.
//

#include "ou_est_le_beurre/Textbox.hpp"

#include <iostream>
#include <utility>

Textbox::Textbox(const std::string &name) {
    if(!texture.loadFromFile(TEXTURES_PATH + name)){
        std::cerr << "error while loading Textbox texture" << std::endl;
    }

    this->setTexture(texture);
    this->setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));

    // init player position in middle
    this->setPosition(POSITION_OFFSET, globals::HEIGHT - get_height() - POSITION_OFFSET);


    if (!font.loadFromFile(FONTS_PATH + "arial.ttf"))
    {
        std::cerr << "Error while loading arial.ttf font" << std::endl;
    }
    text_draw.setFont(font);
    text_draw.setCharacterSize(14);
    text_draw.setFillColor(sf::Color::Black);
    text_draw.setPosition(this->getPosition().x + TEXT_POS_OFFSET, this->getPosition().y + TEXT_POS_OFFSET);
}

Textbox::~Textbox() = default;


void Textbox::draw(sf::RenderWindow &window)
{
    window.draw(*this);
    window.draw(text_draw);
}

void Textbox::update(float delta_t)
{
    // TODO only do this if textbox is enabled
    text_animation_timer += delta_t;
    if(text_animation_timer >= TIME_TILL_NEXT_CHAR){
        text_animation_timer = 0;
        // TODO consider the MAX_CHAR limit
        text_draw.setString(text.substr(0, text_pointer++));
    }
}

// *** getter and setter ***
void Textbox::set_text(std::string new_text) {
    text = std::move(new_text);
    text_pointer = 0;
    text_animation_timer = 0.0;
}

unsigned int Textbox::get_width() {
    return texture.getSize().x * this->getScale().x;
}

unsigned int Textbox::get_height() {
    return texture.getSize().y * this->getScale().y;
}


//
// Created by paddy on 05.12.21.
//

#include "ou_est_le_beurre/Textbox.hpp"

#include <iostream>
#include <utility>

Textbox::Textbox(const std::string &name) {
    // init textbox
    if(!texture_box.loadFromFile(TEXTURES_PATH + name)){
        std::cerr << "error while loading Textbox texture" << std::endl;
    }

    this->setShape(sf::IntRect(0, 0, texture_box.getSize().x, texture_box.getSize().y));
    this->setPosition(sf::Vector2f(POSITION_OFFSET, globals::HEIGHT - this->getShape().height - POSITION_OFFSET));

    sprite_box.setTexture(texture_box);
    sprite_box.setTextureRect(this->getShape());
    sprite_box.setPosition(this->getPosition());

    // init arrow down
    if(!texture_arrow.loadFromFile(TEXTURES_PATH + "arrow_down.png")){
        std::cerr << "error while loading arrow_down.png texture" << std::endl;
    }
    sprite_arrow.setTexture(texture_arrow);
    sprite_arrow.setTextureRect(sf::IntRect(0, 0, texture_arrow.getSize().x, texture_arrow.getSize().y));
    sprite_arrow.setPosition(POSITION_OFFSET + this->getShape().width - 22, globals::HEIGHT - POSITION_OFFSET - 22);

    // init text
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


void Textbox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(enabled) {
        target.draw(sprite_box, states);
        target.draw(text_draw, states);
        target.draw(sprite_arrow, states);
    }
}

void Textbox::update(float delta_t)
{
    if(enabled) {
        text_animation_timer += delta_t;
        if (text_animation_timer >= TIME_TILL_NEXT_CHAR) {
            text_animation_timer = 0;
            // TODO consider the MAX_CHAR limit
            text_draw.setString(text.substr(0, text_pointer++));
        }
    }
}

// *** getter and setter ***
void Textbox::set_text(std::string new_text) {
    text = std::move(new_text);
    text_pointer = 0;
    text_animation_timer = 0.0;
}
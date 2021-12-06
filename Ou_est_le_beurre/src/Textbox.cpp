//
// Created by paddy on 05.12.21.
//

#include "ou_est_le_beurre/Textbox.hpp"

#include <iostream>
#include <utility>
#include <sstream>

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

//int get_length_to_next_word(std::string text, int offset)
//{
//    std::regex word_separator(std::string(" "));
//    std::smatch m;
//    std::regex_search(text, m, word_separator);
//    return (int)m.position() + 1;
//}

void Textbox::update(float delta_t)
{
    if(enabled) {
        text_animation_timer += delta_t;
        if (text_animation_timer >= TIME_TILL_NEXT_CHAR) {
            text_animation_timer = 0;
            // TODO consider the MAX_CHAR limit

            //int length_to_next_word = get_length_to_next_word(text.substr(text_pointer+1, text.size()-1), 0);
            // TODO instead of length to next word I need the px size of this new word ...
            //if(text_draw.getLocalBounds().width + length_to_next_word >= this->getShape().width - TEXT_POS_OFFSET*2){
            //    text.at(text_pointer) = '\n';
            //    //std::cout << text_draw.getLocalBounds().width << " | " << this->getShape().width << std::endl;
            //}
            //std::cout << text_draw.getLocalBounds().width << std::endl;
            text_draw.setString(text.substr(0, text_pointer));
            if(text_pointer < text.size()){
                text_pointer++;
            }
        }
    }
}

void Textbox::crop_text_to_textbox(std::string &new_text){
    // crop text to textbox size
    std::vector<std::string> token = utils::split(new_text, ' ');
    std::ostringstream processed_text;
    std::ostringstream tmp_text;
    tmp_text << token[0];
    token.erase(token.begin());
    for (auto t : token) {
        tmp_text << " " << t << std::flush;
        text_draw.setString(tmp_text.str());
        // true if text is bouncing out of the box
        if(text_draw.getLocalBounds().width < getShape().width - TEXT_POS_OFFSET*2){
            processed_text.str(std::string(""));
            processed_text << tmp_text.str();
        } else {
            processed_text << "\n" << t << std::flush;
            tmp_text.str(std::string(""));
            tmp_text << processed_text.str();
        }
    }
    new_text = processed_text.str();

    text_draw.setString(std::string(""));
}

// *** getter and setter ***
void Textbox::set_text(std::string new_text) {
    crop_text_to_textbox(new_text);
    text = new_text;
    text_pointer = 0;
    text_animation_timer = 0.0;


}
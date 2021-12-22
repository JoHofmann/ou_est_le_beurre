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
    sprite_arrow.setPosition(POSITION_OFFSET + this->getShape().width - ARROW_POS_OFFSET.x, globals::HEIGHT - POSITION_OFFSET - ARROW_POS_OFFSET.y);

    // init text
    if (!font.loadFromFile(FONTS_PATH + "OcrB2.ttf"))
    {
        std::cerr << "Error while loading arial.ttf font" << std::endl;
    }
    text_draw.setFont(font);
    text_draw.setCharacterSize(14);
    text_draw.setFillColor(sf::Color::White);
    text_draw.setPosition(this->getPosition().x + TEXT_POS_OFFSET.x, this->getPosition().y + TEXT_POS_OFFSET.y);

    // init name text
    name_text_draw.setFont(font);
    name_text_draw.setCharacterSize(14);
    name_text_draw.setFillColor(sf::Color::Black);
    name_text_draw.setPosition(this->getPosition().x + NAME_TEXT_POS_OFFSET.x, this->getPosition().y + NAME_TEXT_POS_OFFSET.y);

    this->set_text(L"", L"");
    this->set_enabled(false);
}

Textbox::~Textbox() = default;


void Textbox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(enabled) {
        target.draw(sprite_box, states);
        target.draw(text_draw, states);
        target.draw(name_text_draw, states);
        if(stop_typing_text) {
            target.draw(sprite_arrow, states);
        }
    }
}

void Textbox::update(float delta_t)
{
    if(this->get_enabled()) {
        text_animation_timer += delta_t;
        if (text_animation_timer >= TIME_TILL_NEXT_CHAR) {
            text_animation_timer = 0;
            text_draw.setString(text.substr(text_pointer_start, text_pointer_length + 1));

            // update text animation
            if(!stop_typing_text) {
                // consider max line limit
                if (text.at(text_pointer_start + text_pointer_length) == '\n') {
                    if (++drawn_line_counter >= MAX_TEXT_LINES) {
                        stop_typing_text = true;
                        arrow_motion_counter = 0;
                        arrow_motion_direction = {0, -1};
                    }
                }
                if (text_pointer_start + text_pointer_length < text.size() - 1 && !stop_typing_text) {
                    text_pointer_length++;
                    // TODO else show arrow and close after key pressed
                } else {
                    stop_typing_text = true;
                }
            } else {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    // blink until key pressed, then do the following
                    // close textbox if text is done
                    if(text_pointer_start + text_pointer_length >= text.size() -1){
                        this->set_enabled(false);
                        // TODO set something so that the main game can continue
                    }
                    drawn_line_counter = 0;
                    text_pointer_start += text_pointer_length + 1;       // +1 to skip one newline
                    text_pointer_length = 0;
                    stop_typing_text = false;
                } else {
                    // show blinking arrow
                    arrow_motion_counter++;
                    if (arrow_motion_counter > 3) {
                        arrow_motion_direction = {arrow_motion_direction.x * -1, arrow_motion_direction.y * -1};
                        arrow_motion_counter = 0;
                    }
                    sprite_arrow.move(arrow_motion_direction);
                }
            }
        }
    }
}

void Textbox::crop_text_to_textbox(std::wstring &new_text){
    // crop text to textbox size
    std::vector<std::wstring> token = utils::split(new_text, ' ');
    std::wstringstream processed_text;
    std::wstringstream tmp_text;
    tmp_text << token[0];
    token.erase(token.begin());
    for (auto t : token) {
        tmp_text << " " << t << std::flush;
        text_draw.setString(tmp_text.str());
        // true if text is bouncing out of the box
        if(text_draw.getLocalBounds().width < this->getShape().width - TEXT_POS_OFFSET.y*2){
            processed_text.str(std::wstring(L""));
            processed_text << tmp_text.str();
        } else {
            processed_text << "\n" << t << std::flush;
            tmp_text.str(std::wstring(L""));
            tmp_text << processed_text.str();
        }
    }
    new_text = processed_text.str();

    text_draw.setString(std::string(""));
}

// *** getter and setter ***
void Textbox::set_text(std::wstring name, std::wstring new_text) {
    crop_text_to_textbox(new_text);
    text = new_text;
    text_animation_timer = 0.0;
    drawn_line_counter = 0;
    text_pointer_length = 0;
    text_pointer_start = 0;
    stop_typing_text = false;
    arrow_motion_counter = 0;
    arrow_motion_direction = {0, -1};

    name_text_draw.setString(name);
}
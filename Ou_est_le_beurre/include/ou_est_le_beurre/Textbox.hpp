//
// Created by paddy on 05.12.21.
//

#ifndef OUESTLEBEURRE_TEXTBOX_HPP
#define OUESTLEBEURRE_TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/GameObject.hpp"
#include "ou_est_le_beurre/utils.hpp"

class Textbox : public GameObject
{
public:
    Textbox(const std::string &);
    ~Textbox() override;

    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void update(float) override;

    // *** Getter and Setter ***
    void set_text(std::wstring, std::wstring);

private:
    // *** private functions ***
    void crop_text_to_textbox(std::wstring &new_text);


    // *** constants ***
    const unsigned int POSITION_OFFSET = 10;
    const sf::Vector2f TEXT_POS_OFFSET = {30, 60};
    const int MAX_TEXT_LINES = 5;
    const float TIME_TILL_NEXT_CHAR = 0.05;    // after this time the next char of the text is drawn
    const sf::Vector2f NAME_TEXT_POS_OFFSET = {23, 8};
    const sf::Vector2f ARROW_POS_OFFSET = {30, 30};

    // *** private fields ***
    // SFML graphics
    sf::Texture texture_box;
    sf::Sprite sprite_box;
    sf::Texture texture_arrow;
    sf::Sprite sprite_arrow;
    sf::Font font;
    sf::Text text_draw;     // the object to draw a text
    sf::Text name_text_draw;

    // text animation
    std::wstring text;       // the text to draw (not the complete text needs to be drawn at once)
    int text_pointer_length;       // points to the position of the text that should be drawn
    int text_pointer_start;
    float text_animation_timer;
    int drawn_line_counter;
    bool stop_typing_text;
    int arrow_motion_counter;
    bool arrow_up;
    sf::Vector2f arrow_motion_direction;

};


#endif //OUESTLEBEURRE_TEXTBOX_HPP

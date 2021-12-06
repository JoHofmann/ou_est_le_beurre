//
// Created by paddy on 05.12.21.
//

#ifndef OUESTLEBEURRE_TEXTBOX_HPP
#define OUESTLEBEURRE_TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/GameObject.hpp"

class Textbox : public GameObject
{
public:
    Textbox(const std::string &);
    ~Textbox() override;

    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void update(float) override;

    // *** Getter and Setter ***
    void set_text(std::string);

private:
    // *** constants ***
    unsigned int POSITION_OFFSET = 10;
    int TEXT_POS_OFFSET = 20;
    int MAX_CHARS_IN_WINDOW = 100;      // if the number of chars of the drawn text is larger than this constant the text will overflow the window
    float TIME_TILL_NEXT_CHAR = 0.05;    // after this time the next char of the text is drawn

    // *** private fields ***
    // SFML graphics
    sf::Texture texture_box;
    sf::Sprite sprite_box;
    sf::Texture texture_arrow;
    sf::Sprite sprite_arrow;
    sf::Font font;
    sf::Text text_draw;     // the object to draw a text

    // text animation
    std::string text;       // the text to draw (not the complete text needs to be drawn at once)
    int text_pointer;       // points to the position of the text that should be drawn
    float text_animation_timer;

};


#endif //OUESTLEBEURRE_TEXTBOX_HPP

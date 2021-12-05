//
// Created by paddy on 05.12.21.
//

#ifndef OUESTLEBEURRE_TEXTBOX_HPP
#define OUESTLEBEURRE_TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include "ou_est_le_beurre/globals.hpp"

class Textbox : public sf::Sprite
{
public:
    Textbox(const std::string &);
    ~Textbox();

    unsigned int get_width();
    unsigned int get_height();

private:
    sf::Texture texture;
    unsigned int position_offset = 10;

};


#endif //OUESTLEBEURRE_TEXTBOX_HPP

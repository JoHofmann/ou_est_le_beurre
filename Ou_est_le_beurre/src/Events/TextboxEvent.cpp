/*
 * EggPan.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Events/TextboxEvent.hpp"
#include "ou_est_le_beurre/Game.hpp"

#include <iostream>

TextboxEvent::TextboxEvent(Game *game, std::wstring tb_name, std::wstring tb_text) :
	game(game), textbox_name(tb_name), textbox_text(tb_text)
{
	textbox = game->getPTextbox();

	this->setEnabled(false);
}

void TextboxEvent::init() {
	if(textbox->isTextIsFinished() && this->getEnabled()) {
		textbox->set_text(textbox_name, textbox_text);
		textbox->set_enabled(true);
	}
}

void TextboxEvent::update(float delta_t) {

	if(this->getEnabled()) {
		if(textbox->isTextIsFinished()) {
			this->setEnabled(false);
			std::cout << "Textbox event finished" << std::endl;
		}
	}
}

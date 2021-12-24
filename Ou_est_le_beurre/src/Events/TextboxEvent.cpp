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
	Event(), game(game)
{
	textbox = game->getPTextbox();

	messages.push_back(std::make_pair(tb_name, tb_text));
	messages_iter = messages.begin();
}

TextboxEvent::TextboxEvent(Game *game, std::vector<std::pair<std::wstring, std::wstring>> dialog) :
	Event(), game(game)
{
	textbox = game->getPTextbox();

	messages = dialog;

	messages_iter = messages.begin();
}


void TextboxEvent::init() {
	if(textbox->isTextIsFinished()) {
		textbox->set_text(messages_iter->first, messages_iter->second);
		textbox->set_enabled(true);

        this->setActive(true);
	}
}

void TextboxEvent::update(float delta_t) {
	if(this->isActive()) {
		if(textbox->isTextIsFinished()) {

			if(messages_iter != messages.end()) {
				textbox->set_text(messages_iter->first, messages_iter->second);

				messages_iter = next(messages_iter);
			}else{
				std::cout << "Textbox event finished" << std::endl;

	            this->setActive(false);
			}
		}
	}
}

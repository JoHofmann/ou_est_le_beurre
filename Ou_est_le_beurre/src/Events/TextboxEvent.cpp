/*
 * EggPan.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Events/TextboxEvent.hpp"
#include "ou_est_le_beurre/Game.hpp"

#include <iostream>
#include <utility>

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

	messages = std::move(dialog);
}


void TextboxEvent::init() {
    messages_iter = messages.begin();
    textbox->set_text(messages[0].first, messages[0].second);
    textbox->set_enabled(true);
    idx = 1;
    this->setActive(true);
}

void TextboxEvent::update(float delta_t) {
	if(this->isActive()) {
		if(textbox->isTextIsFinished()) {

			if(idx < messages.size()) {
				textbox->set_text(messages[idx].first, messages[idx].second);
                textbox->set_enabled(true);
                idx++;

			}else{
				std::cout << "Textbox event finished" << std::endl;

	            this->setActive(false);
			}
		}
	}
}

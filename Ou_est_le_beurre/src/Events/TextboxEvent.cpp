/*
 * EggPan.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Events/TextboxEvent.hpp"

#include <iostream>

TextboxEvent::TextboxEvent(std::wstring tb_name, std::wstring tb_text) :
	textbox("Simple_Textbox.png")
{
	this->setEnabled(false);

	textbox.set_enabled(false);
	textbox.set_text(tb_name, tb_text);
}

void TextboxEvent::init() {
	textbox.set_enabled(true);

	std::cout << "Textbox event started" << std::endl;
}

void TextboxEvent::update(float delta_t) {

	if(this->getEnabled()) {
		if(textbox.isTextIsFinished()) {
			this->setEnabled(false);
		}
	}
}

/*
 * EggPan.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Events/EggPan.hpp"

EggPan::EggPan() :
	textbox("Simple_Textbox.png")
{
	this->setEnabled(true);
	this->setFinished(false);

	textbox.set_enabled(false);
	textbox.set_text(L"Muttern", L"Dreckige Pfanne von Vatern");
}

void EggPan::update(float delta_t) {

	if(!this->getFinished() && this->getEnabled()) {
		textbox.set_enabled(true);
		textbox.update(delta_t);



		// TODO wann textbox fertig??????
	}
}

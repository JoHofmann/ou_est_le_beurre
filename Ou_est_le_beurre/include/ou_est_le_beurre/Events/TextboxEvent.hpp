/*
 * EggPan.hpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#ifndef INCLUDE_OU_EST_LE_BEURRE_EVENTS_TEXTBOXEVENT_HPP_
#define INCLUDE_OU_EST_LE_BEURRE_EVENTS_TEXTBOXEVENT_HPP_

#include <string>
#include <memory>
#include "ou_est_le_beurre/Events/Event.hpp"
#include "ou_est_le_beurre/Textbox.hpp"

class Game;

class TextboxEvent : public Event {
public:
	TextboxEvent(Game *, std::wstring, std::wstring);

	void init();
	void update(float) override;

private:
	std::shared_ptr<Textbox> textbox;

	std::wstring textbox_name;
	std::wstring textbox_text;

	Game *game;
};

#endif /* INCLUDE_OU_EST_LE_BEURRE_EVENTS_TEXTBOXEVENT_HPP_ */

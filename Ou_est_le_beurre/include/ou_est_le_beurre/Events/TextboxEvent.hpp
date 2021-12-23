/*
 * EggPan.hpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#ifndef INCLUDE_OU_EST_LE_BEURRE_EVENTS_TEXTBOXEVENT_HPP_
#define INCLUDE_OU_EST_LE_BEURRE_EVENTS_TEXTBOXEVENT_HPP_

#include <string>
#include "ou_est_le_beurre/Events/Event.hpp"
#include "ou_est_le_beurre/Textbox.hpp"

class TextboxEvent : public Event {
public:
	TextboxEvent(std::wstring, std::wstring);

	void init();
	void update(float) override;

private:
	Textbox textbox;
};

#endif /* INCLUDE_OU_EST_LE_BEURRE_EVENTS_TEXTBOXEVENT_HPP_ */

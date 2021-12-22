/*
 * EggPan.hpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#ifndef INCLUDE_OU_EST_LE_BEURRE_EVENTS_EGGPAN_HPP_
#define INCLUDE_OU_EST_LE_BEURRE_EVENTS_EGGPAN_HPP_

#include "ou_est_le_beurre/Events/Event.hpp"
#include "ou_est_le_beurre/Textbox.hpp"

class EggPan: public Event {
public:
	EggPan();

	void update(float) override;

private:
	Textbox textbox;
};

#endif /* INCLUDE_OU_EST_LE_BEURRE_EVENTS_EGGPAN_HPP_ */

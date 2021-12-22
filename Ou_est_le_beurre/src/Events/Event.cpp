/*
 * Event.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Events/Event.hpp"

void Event::setFinished(bool _finished) {
	finished = _finished;
}

bool Event::getFinished() {
	return finished;
}

void Event::setEnabled(bool _enabled) {
	enabled = _enabled;
}

bool Event::getEnabled() {
	return enabled;
}




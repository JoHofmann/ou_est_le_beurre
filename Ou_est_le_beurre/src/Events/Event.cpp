/*
 * Event.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#include "ou_est_le_beurre/Events/Event.hpp"

void Event::setEnabled(bool _enabled) {
	enabled = _enabled;
}

bool Event::getEnabled() {
	return enabled;
}

Event::Event() {
    setEnabled(true);
    setActive(false);
}

bool Event::isActive() const {
    return active;
}

void Event::setActive(bool active) {
    Event::active = active;
}




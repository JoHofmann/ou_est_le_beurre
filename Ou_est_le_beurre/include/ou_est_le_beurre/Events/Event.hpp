/*
 * Event.hpp
 *
 *  Created on: Dec 22, 2021
 *      Author: johannes
 */

#ifndef INCLUDE_OU_EST_LE_BEURRE_EVENTS_EVENT_HPP_
#define INCLUDE_OU_EST_LE_BEURRE_EVENTS_EVENT_HPP_

class Event {

public:
    Event();
	virtual void init() = 0;
	virtual void update(float) = 0;

	virtual void setEnabled(bool);
	virtual bool getEnabled();

    bool isActive() const;

    void setActive(bool active);

protected:


private:
	bool enabled;
    bool active;

};



#endif /* INCLUDE_OU_EST_LE_BEURRE_EVENTS_EVENT_HPP_ */

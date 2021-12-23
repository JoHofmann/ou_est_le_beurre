//
// Created by paddy on 08.12.21.
//

#ifndef OUESTLEBEURRE_STATE_HPP
#define OUESTLEBEURRE_STATE_HPP

#include <vector>
#include <memory>

class Game;
class Event;

class State {
public:
    State(Game *);

    void update(float);
    virtual bool goalReached()=0;
    // This function is called just before the state gets active
    virtual void initState()=0;

    // *** Getter and Setter ***
    float getElapsedTime() const;


protected:
    Game *game;
    std::vector<std::shared_ptr<Event>> events;
    virtual void processState()=0;
private:
    // *** private fields ***
    float elapsedTime;

    // *** private functions ***
};


#endif //OUESTLEBEURRE_STATE_HPP

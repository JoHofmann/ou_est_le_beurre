//
// Created by paddy on 08.12.21.
//

#ifndef OUESTLEBEURRE_STATE_HPP
#define OUESTLEBEURRE_STATE_HPP

class Game;

class State {
public:
    State(Game const*);

    void update(float);
    virtual bool goalReached()=0;

    // *** Getter and Setter ***
    float getElapsedTime() const;

protected:
    Game const* game;
    virtual void processState()=0;
private:
    // *** private fields ***
    float elapsedTime;

    // *** private functions ***
};


#endif //OUESTLEBEURRE_STATE_HPP

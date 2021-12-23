//
// Created by paddy on 20.12.21.
//

#ifndef OUESTLEBEURRE_OPENINGSTATE_HPP
#define OUESTLEBEURRE_OPENINGSTATE_HPP

#include "ou_est_le_beurre/StateMachine/State.hpp"
#include "ou_est_le_beurre/Game.hpp"

class OpeningState : public State{
public:
    OpeningState(Game *game);

    bool goalReached() override;
    void initState() override;

private:
    void processState() override;
    void prepareEpilog();

    enum States {FADE_IN, EPILOG, FRIDGE, FINISHED};
    States state = FADE_IN;
    std::shared_ptr<Textbox> pTextbox;
    std::shared_ptr<FadeObject> pFade;
    std::shared_ptr<Player> pPlayer;

    bool desired_event_is_active;
};


#endif //OUESTLEBEURRE_OPENINGSTATE_HPP

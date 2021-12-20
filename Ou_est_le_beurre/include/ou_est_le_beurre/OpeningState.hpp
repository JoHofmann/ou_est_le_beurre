//
// Created by paddy on 20.12.21.
//

#ifndef OUESTLEBEURRE_OPENINGSTATE_HPP
#define OUESTLEBEURRE_OPENINGSTATE_HPP

#include "ou_est_le_beurre/State.hpp"
#include "ou_est_le_beurre/Game.hpp"

class OpeningState : public State{
public:
    OpeningState(Game const *game);

    bool goalReached() override;
private:
    void processState() override;

    std::shared_ptr<Textbox> pTextbox;
};


#endif //OUESTLEBEURRE_OPENINGSTATE_HPP

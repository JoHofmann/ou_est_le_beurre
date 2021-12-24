//
// Created by paddy on 24.12.21.
//

#ifndef OUESTLEBEURRE_CHAUAMOREEVENT_H
#define OUESTLEBEURRE_CHAUAMOREEVENT_H

#include "ou_est_le_beurre/Events/Event.hpp"
#include "ou_est_le_beurre/Textbox.hpp"
#include "ou_est_le_beurre/Player.hpp"

class Game;

class ChauAmoreEvent : public Event{
public:
    ChauAmoreEvent(Game *);

    void init() override;
    void update(float) override;

private:
    std::shared_ptr<Player> pPapo;
    std::shared_ptr<Player> pPlayer;
    std::shared_ptr<Textbox> pTextbox;
    Game *pGame;

    std::vector<Direction> papoEnterTrajectory;
    std::vector<Direction> papoExitTrajectory;
};


#endif //OUESTLEBEURRE_CHAUAMOREEVENT_H

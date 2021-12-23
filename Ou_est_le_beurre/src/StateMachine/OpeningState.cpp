//
// Created by paddy on 20.12.21.
//

#include "ou_est_le_beurre/StateMachine/OpeningState.hpp"


OpeningState::OpeningState(Game *game) : State(game) {
    pTextbox = game->getPTextbox();
    pFade = game->getPFade();
    pPlayer = game->getPlayer();

    events = game->getEvents();

    // TODO initialize scene
    pTextbox->set_enabled(false);
    pFade->startFade();
    // TODO momy at door
    pPlayer->setGridPosition(sf::Vector2i(3, 0));
    pPlayer->setMoveable(true);

    // TODO set all events true
    events[0]->setEnabled(true);	// fridge event
}

bool OpeningState::goalReached() {
//    if(state == FINISHED){
//        return true;
//    }
    return false;
}

void OpeningState::prepareEpilog(){
    pTextbox->set_text(L"Muttern",
                       L"Gääähn.\n"
                       "Oh, was ist das nur für ein schöner Morgen. Ich glaube das ganze Haus schläft noch…\n"
                       "Ah es ist ja schon 10Uhr. Vielleicht sind die Kinder (lange über 18) ja auch schon wach. "
                       "Naja egal. Ich glaube ich nutze den Tag heute um einen Kuchen zu backen. "
                       "Mal schauen, ob ich im Kühlschrank alles dafür finden kann...");
    pTextbox->set_enabled(true);
}

void OpeningState::processState() {
    switch(state){
        case FADE_IN:
            if(!pFade->get_enabled()){
                prepareEpilog();
                state = EPILOG;
            }
            break;
        case EPILOG:
            if(!pTextbox->get_enabled()){
                state = FINISHED;
            }
            break;
    }
}

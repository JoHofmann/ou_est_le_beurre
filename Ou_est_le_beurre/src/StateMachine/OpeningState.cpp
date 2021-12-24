//
// Created by paddy on 20.12.21.
//

#include "ou_est_le_beurre/StateMachine/OpeningState.hpp"


OpeningState::OpeningState(Game *game) : State(game) {
    pTextbox = game->getPTextbox();
    pFade = game->getPFade();
    pPlayer = game->getPlayer();
    desired_event_is_active = false;
}

bool OpeningState::goalReached() {
    if(state == FINISHED){
        return true;
    }
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
            if(!pTextbox->isTextIsFinished()){
                state = FRIDGE;
            }
            break;
        case FRIDGE:
            pPlayer->setMoveable(true);
            if(game->getEvents()[0]->isActive() && !desired_event_is_active){
                desired_event_is_active = true;
            } else if(!game->getEvents()[0]->isActive() && desired_event_is_active){
                desired_event_is_active = false;
                state = FINISHED;
            }
            break;
    }
}

void OpeningState::initState() {
    // TODO initialize scene
    pTextbox->set_enabled(false);
    pFade->startFade();
    // Muttern at door
    pPlayer->setGridPosition(sf::Vector2i(3, 0));
    pPlayer->setMoveable(false);


    // init events
    std::vector<sf::Vector2i> eventTiles;

    std::vector<std::shared_ptr<Event>> events;
    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Kühlschrank"));
    eventTiles.push_back(sf::Vector2i(5, 0));

    game->getPTilemap()->setNewEvents(eventTiles);
    game->setEvents(events);
}

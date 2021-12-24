//
// Created by paddy on 23.12.21.
//

#include "ou_est_le_beurre/StateMachine/ExploringState.hpp"

ExploringState::ExploringState(Game *game) : State(game) {
}



bool ExploringState::goalReached() {
    return false;
}

void ExploringState::processState() {

}

void ExploringState::initState() {
    // init events
    std::vector<sf::Vector2i> eventTiles;


    std::vector<std::shared_ptr<Event>> events;

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Nein. Hier ist die Butter bestimmt nicht..."));
    eventTiles.push_back(sf::Vector2i(5, 0));
    // 0
    events.push_back(std::make_shared<TextboxEvent>(game, L"Vatern", L"Das Schmutz- und Schmeißeck"));
    eventTiles.push_back(sf::Vector2i(0, 1));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Zeit für den sterbenden Schwan!"));
    eventTiles.push_back(sf::Vector2i(0, 2));

    // TODO very strange bug, where is event is on the tile of the ciao d'amore event ....
    //events.push_back(std::make_shared<TextboxEvent>(game, L"Vatern", L"Bin im Garten, hosch mi?"));
    //eventTiles.push_back(sf::Vector2i(0, 3));


    // 1
    events.push_back(std::make_shared<TextboxEvent>(game, L"Schnuck", L"Der JEMPO-Vorrat"));
    eventTiles.push_back(sf::Vector2i(1, 1));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Wo ist denn der Sitzkeil?"));
    eventTiles.push_back(sf::Vector2i(1, 3));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Oh was isch au des? Wo isch denn des Stetzle Butter des I von der Gfriere auf dHeizung glegt hon?"));
    eventTiles.push_back(sf::Vector2i(1, 5));


    // 2
    std::vector<std::pair<std::wstring, std::wstring>> dialog;
    dialog.push_back(std::make_pair(L"Muttern", L"Ach Christoph, ich hab übrigens alle Kontakte aus dem Telefon gelöscht."));
    dialog.push_back(std::make_pair(L"Vatern", L"Dir brennt wohl der Kittel! Und für 60 Euro im Ausland telefoniert…"));
    events.push_back(std::make_shared<TextboxEvent>(game, dialog));
    eventTiles.push_back(sf::Vector2i(2, 1));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Vatern", L"Ach des isch en Rettich! I hon denkt des sind roate Riabe!"));
    eventTiles.push_back(sf::Vector2i(2, 4));

    // 3
    events.push_back(std::make_shared<TextboxEvent>(game, L"Vatern", L"Wer hat schon wieder die Tür offen stehen lassen? Da ka ma ja die 50er aus dem Fenster pfitzge"));
    eventTiles.push_back(sf::Vector2i(3, 0));

    // 4
    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"hust hust\nHust Hust Hust\nhust Hust hust hust\nHUST HUST HUST HUST HUST"));
    eventTiles.push_back(sf::Vector2i(4, 0));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Ich hasse den Sandwichmaker. Weil den nie jemand aufräumt."));
    eventTiles.push_back(sf::Vector2i(4, 3));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Unterm Salem-Aktuell isch DER Butter au it."));
    eventTiles.push_back(sf::Vector2i(4, 4));

    std::vector<std::pair<std::wstring, std::wstring>> dialog2;
    dialog2.push_back(std::make_pair(L"Vatern", L"Will jemand einen Ekschpresso?"));
    dialog2.push_back(std::make_pair(L"Muttern", L"Nein, aber bitte einen kleinen Cappuccino"));
    events.push_back(std::make_shared<TextboxEvent>(game, dialog2));
    eventTiles.push_back(sf::Vector2i(4, 5));

    // 5
    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Nein. Hier ist die Butter bestimmt nicht...\nAber den Kühlschrank könnte man mal wider putzen. Am besten an Heilig Abend. Da haben bestimmt alle richtig viel Zeit. KINDER, kommet mal bitte ..."));
    eventTiles.push_back(sf::Vector2i(5, 0));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Nicht das Schneidebrett auf dem Herd liegen lassen, Mause!"));
    eventTiles.push_back(sf::Vector2i(5, 5));

    // 6
     events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Die drecks Glaskaraffe passt nicht mal ins Rondell!"));
     eventTiles.push_back(sf::Vector2i(6, 0));


    events.push_back(std::make_shared<ChauAmoreEvent>(game));
    eventTiles.push_back(sf::Vector2i(6,5));

    // 7
    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Weisheit #1: Erst die trockenen Sachen ausräumen, bevor man das gespülte Geschirr drauf stapelt."));
    eventTiles.push_back(sf::Vector2i(7, 1));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"Schee, perfekt enthärtetes Wasser"));
    eventTiles.push_back(sf::Vector2i(7, 2));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Vatern", L"Wie kann man eine Spülmaschine so einräumen? Und wer (von den Kindern über 18) hat schon wieder das Besteck reingeworfen?"));
    eventTiles.push_back(sf::Vector2i(7, 3));

    events.push_back(std::make_shared<TextboxEvent>(game, L"Muttern", L"OHREN ZU, JETZT WIRD’S LAUT!"));
    eventTiles.push_back(sf::Vector2i(7, 4));



    game->getPTilemap()->setNewEvents(eventTiles);
    game->setEvents(events);
}

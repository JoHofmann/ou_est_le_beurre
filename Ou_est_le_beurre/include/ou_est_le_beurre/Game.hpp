//
// Created by paddy on 30.11.21.
//

#ifndef OUESTLEBEURRE_GAME_HPP
#define OUESTLEBEURRE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <memory>
#include "Events/TextboxEvent.hpp"
#include "ou_est_le_beurre/globals.hpp"
#include "ou_est_le_beurre/Player.hpp"
#include "ou_est_le_beurre/Textbox.hpp"
#include "ou_est_le_beurre/StateMachine/State.hpp"
#include "ou_est_le_beurre/GameObject.hpp"
#include "ou_est_le_beurre/FadeObject.hpp"
#include "ou_est_le_beurre/StateMachine/OpeningState.hpp"
#include "ou_est_le_beurre/Tilemap.hpp"

class Tilemap;

class Game {
public:
    // public functions
    Game();
    ~Game();

    void update(float);
    void draw(sf::RenderWindow &);

    // *** Getter and Setter ***
    const std::shared_ptr<Textbox> &getPTextbox() const;
    const std::shared_ptr<FadeObject> &getPFade() const;
    const std::shared_ptr<Player> &getPlayer() const;

    std::vector<std::shared_ptr<Event>> &getEvents();

    void setEvents(std::vector<std::shared_ptr<Event>> events);

    const int getEventIndex();
    void setEventIndex(int);

    const std::shared_ptr<Tilemap> &getPTilemap() const;


private:

    // state machine
    void updateStateMachine(float);
    std::vector<std::shared_ptr<State>> states;
    std::vector<std::shared_ptr<State>>::iterator stateIterator;

    // pointer on GameObjects
    std::shared_ptr<Player> pPlayer;
    std::shared_ptr<Textbox> pTextbox;
    std::shared_ptr<FadeObject> pFade;

    // GameObject Vector
    std::vector<std::shared_ptr<GameObject>> gameObjects;

    // background
    sf::Sprite background;
    sf::Texture tex_background;

    // Sound and Music
    sf::SoundBuffer soundBuffer;
    sf::Sound backgroundMusic;

    // tilemap
    std::shared_ptr<Tilemap> pTilemap;

    // events
    int eventIndex;

    std::vector<std::shared_ptr<Event>> events;
};


#endif //OUESTLEBEURRE_GAME_HPP

//
//  EventBroker.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2020/01/04.
//  Copyright © 2020 ogurotetsuro. All rights reserved.
//

#include "EventBroker.hpp"

#include <string>
#include <iostream>

#include <boost/signals2.hpp>

using namespace std;
using namespace boost;
using namespace boost::signals2;

struct EventData
{
    virtual void print() const = 0;
};

struct PlayerScoredData : EventData
{
    string playerName;
    int goalsScoredSoFar;
    
    PlayerScoredData(const string& playerName, int goalsScoredSoFar) :
    playerName(playerName), goalsScoredSoFar(goalsScoredSoFar) {}
    
    void print() const override
    {
        cout << playerName << " has scored! (their " << goalsScoredSoFar << " goal)" << endl;
    }
};

struct Game
{
    signal<void(EventData*)> events;
};

struct Player
{
    string name;
    int goalsScored{0};
    Game& game;
    
    Player(const string& name, Game& game) : name(name), game(game) {}
    
    void score()
    {
        goalsScored++;
        PlayerScoredData ps{name, goalsScored};
        game.events(&ps);
    }
};

struct Coach
{
    Game& game;
    
    Coach(Game& game) : game(game)
    {
        game.events.connect([](EventData* e)
        {
            PlayerScoredData* ps = dynamic_cast<PlayerScoredData*>(e);
            if(ps && ps->goalsScoredSoFar < 3)
            {
                cout << "coach says: well done, " << ps->playerName << "!" << endl;
            }
        });
    }
};


void EventBrokerMain()
{
    Game game;
    Player player{"sam", game};
    Coach coach{game};
    
    player.score();
    player.score();
    player.score();
    
}

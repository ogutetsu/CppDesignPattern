//
//  BrokerChain.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/10/29.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "BrokerChain.hpp"
#include <iostream>
#include <string>
#include <csignal>

using namespace std;

struct Query
{
    string creature_name;
    enum Argument{ attack, defense } argument;
    int result;
    
    Query(Query& query) :
    Query(query.creature_name, query.argument, query.result) {}
    
    Query(const string& creature_name, Argument argument, int result) : argument(argument), result(result), creature_name{creature_name} {}
    
};

struct Game
{
    //signal<Query&> queries;
    
    Query& queries;
};

struct Creature
{
    Game& game;
    int attack, defense;
    string name;
public:
    Creature(Game& game, int attack, int defense, const string& name) :
    game(game), attack(attack), defense(defense), name(name)
    {
        
    }
    
    int get_attack() const
    {
        Query q{name, Query::Argument::attack, attack};
        game.queries = q;
        return q.result;
    }
    
    friend ostream& operator<<(ostream& os, const Creature& creature) {
        os << "attack: " << creature.attack << " name: " << creature.name;
        return os;
    }
};

class CreatureModifier
{
    Game& game;
    Creature& creature;
public:
    CreatureModifier(Game& game, Creature& creature) : game(game), creature(creature) {}
    virtual ~CreatureModifier() = default;
};

/*
DoubleAttackModifier : public CreatureModifier
{
public:
    DoubleAttackModifier(Game& game, Creature& creature) : CreatureModifier(game, creature) {
        
    }
    
};
*/
void BrokenChainMain()
{
    
}


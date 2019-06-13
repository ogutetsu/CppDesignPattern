//
//  ArrayBacked.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/13.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "ArrayBacked.hpp"
#include <algorithm>
#include <array>
#include <numeric>
#include <iostream>

using namespace std;

//class Creature
//{
//    int strength;
//    int agility;
//    int intelligence;
//
//public:
//
//    int GetStreangth()
//    {
//        return strength;
//    }
//    void SetStreangth(int strength)
//    {
//        Creature::strength = strength;
//    }
//    int GetAgility()
//    {
//        return agility;
//    }
//    void SetAgility(int agility)
//    {
//        Creature::agility = agility;
//    }
//    int GetIntelligence()
//    {
//        return intelligence;
//    }
//    void SetIntelligence(int intelligence)
//    {
//        Creature::intelligence = intelligence;
//    }
//
//    double Sum() const {
//        return strength+agility+intelligence;
//    }
//
//    double Average() const {
//        return Sum() / 3.0;
//    }
//
//    int Max() const {
//        return ::max(::max(strength, agility), intelligence);
//    }
//
//};
//

class Creature
{
    enum Abilities { str, agl, intl, count };
    array<int, count> abilities;
public:
    int GetStrength() const { return abilities[str]; }
    void SetStrength(int value) { abilities[str] = value; }
    
    int GetAgility() const { return abilities[agl]; }
    void SetAgility(int value) { abilities[agl] = value; }
    
    int GetIntelligence() const { return abilities[intl]; }
    void SetIntelligence(int value) { abilities[intl] = value; }
    
    int Sum() const {
        return accumulate(abilities.begin(), abilities.end(), 0);
    }
    double Average() const {
        return Sum() / (double)count;
    }
    int Max() const {
        return *max_element(abilities.begin(), abilities.end());
    }
};


void ArrayBackedMain()
{
    Creature orc;
    orc.SetStrength(16);
    orc.SetAgility(11);
    orc.SetIntelligence(8);
    
    cout << "The orc has an average stat of "
        << orc.Average()
        << " and a maximum stat of "
        << orc.Max()
        << endl;
}

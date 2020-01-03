//
//  MadiatorPerson.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2020/01/04.
//  Copyright © 2020 ogurotetsuro. All rights reserved.
//


#include <iostream>


#include "MadiatorPerson.hpp"
#include "MadiatorChatRoom.hpp"

namespace Madiator
{

Person::Person(const string& name) : name(name) {}


void Person::say(const string& message) const
{
    room->broadcast(name, message);
}

void Person::pm(const string& who, const string& message) const
{
    room->message(name, who, message);
}

void Person::receive(const std::string &origin, const std::string &message)
{ 
    string s{origin + ": \"" + message + "\""};
    
    cout << "[" << name << "'s chat session]" << s << endl;
    chatLog.emplace_back(s);
}


bool Person::operator==(const Person& rhs) const
{
    return name == rhs.name;
}

bool Person::operator!=(const Person& rhs) const
{
    return name != rhs.name;
}

} //end of namespace

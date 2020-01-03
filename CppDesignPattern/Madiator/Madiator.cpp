//
//  Madiator.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2020/01/04.
//  Copyright © 2020 ogurotetsuro. All rights reserved.
//

#include "Madiator.hpp"

#include "MadiatorPerson.hpp"
#include "MadiatorChatRoom.hpp"

using namespace Madiator;


void MadiatorMain()
{
    ChatRoom room;
    
    Person john{"john"};
    Person jane{"jane"};
    room.join(&john);
    room.join(&jane);
    
    john.say("hi room");
    jane.say("oh, hey john");
    
    Person simon{"simon"};
    room.join(&simon);
    simon.say("hi everyone!");
    
    jane.pm("simon", "glad you found us. simon!");
    
}

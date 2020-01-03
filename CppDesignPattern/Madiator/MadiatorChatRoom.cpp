//
//  MadiatorChatRoom.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2020/01/04.
//  Copyright © 2020 ogurotetsuro. All rights reserved.
//

#include "MadiatorPerson.hpp"
#include "MadiatorChatRoom.hpp"

namespace Madiator {


void ChatRoom::broadcast(const std::string &origin, const std::string &message)
{
    for(auto p : people)
    {
        if(p->name != origin)
        {
            p->receive(origin, message);
        }
    }
}


void ChatRoom::join(Madiator::Person *p)
{
    string joinMsg = p->name + " joins the chat";
    broadcast("room", joinMsg);
    p->room = this;
    people.push_back(p);
}



} //end of namespace


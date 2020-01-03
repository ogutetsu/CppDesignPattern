//
//  MadiatorChatRoom.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2020/01/04.
//  Copyright © 2020 ogurotetsuro. All rights reserved.
//

#ifndef MadiatorChatRoom_hpp
#define MadiatorChatRoom_hpp

#include <vector>


using namespace std;

namespace Madiator {

struct ChatRoom
{
    vector<Person*> people;
    
    void broadcast(const string& origin, const string& message);
    
    void join(Person* p);
    
    void message(const string& origin, const string& who, const string& message)
    {
        auto target = std::find_if(begin(people), end(people), [&](const Person* p) {
            return p->name == who;
        });
        if(target != end(people))
        {
            (*target)->receive(origin, message);
        }
    }
};


} // end of namespace


#endif /* MadiatorChatRoom_hpp */

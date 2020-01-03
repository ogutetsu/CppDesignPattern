//
//  MadiatorPerson.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2020/01/04.
//  Copyright © 2020 ogurotetsuro. All rights reserved.
//

#ifndef MadiatorPerson_hpp
#define MadiatorPerson_hpp


#include <string>
#include <vector>

using namespace std;

namespace Madiator
{

struct ChatRoom;

struct Person {
    string name;
    ChatRoom* room{nullptr};
    vector<string> chatLog;
    
    Person(const string& name);
    
    void say(const string& message) const;
    void pm(const string& who, const string& message) const;
    
    void receive(const string& origin, const string& message);
    
    bool operator==(const Person& rhs) const;
    bool operator!=(const Person& rhs) const;
};

    
}

#endif /* MadiatorPerson_hpp */

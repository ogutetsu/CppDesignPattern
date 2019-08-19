//
//  Flyweight.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/08/19.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Flyweight.hpp"

#include <string>
#include <map>
#include <ostream>
#include <iostream>

using namespace std;

typedef uint32_t key;

struct User
{
    User(const string& first_name, const string& last_name)
    : first_name{add(first_name)}
    , last_name{add(last_name)} {}
    
    const string& GetFirstName() const
    {
        return names.find(first_name)->second;
    }
    const string& GetLastName() const
    {
        return names.find(last_name)->second;
    }
    
protected:
    static map<key, string> names;
    static key seed;
    
    key first_name;
    key last_name;
    
    static key add(const string& s)
    {
        for(auto it = names.begin(); it != names.end(); it++)
        {
            if(it->second == s)
            {
                return it->first;
            }
        }
        
        key id = ++seed;
        names.insert({seed, s});
        return id;
        
    }
    
};

key User::seed{0};
map<key, string> User::names{};

ostream &operator<<(ostream& os, const User &user) {
    os << "first_name: " << user.GetFirstName() << " last_name: " <<
    user.GetLastName();
    return os;
}

void FlyweightMain()
{
    User user1{"John", "Smith"};
    User user2{"Jane", "Smith"};
    
    cout << user1 << endl << user2 << endl;
    
}

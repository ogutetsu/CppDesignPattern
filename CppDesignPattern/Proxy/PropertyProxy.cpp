//
//  PropertyProxy.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/10/25.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "PropertyProxy.hpp"
#include <ostream>
#include <iostream>

using namespace std;

template <typename T> struct Property
{
    T value;
    Property(T value)
    {
        *this = value;
    }
    
    operator T()
    {
        return value;
    }
    
    T operator=(T new_value)
    {
        cout << "Assignment" << endl;
        return value = new_value;
    }
    
};

struct Creature
{
    Property<int> strength{10};
    Property<int> agility{10};
    
    
    
};


void PropertyProxyMain()
{
    Creature c;
    c.strength = 15;
    int x = c.agility;
    
    
}

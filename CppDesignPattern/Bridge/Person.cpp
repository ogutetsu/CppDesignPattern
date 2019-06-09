//
//  Person.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/07.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Person.hpp"
#include <iostream>

using namespace std;

class Person::PersinImpl
{
public:
    void greet(Person* person);
private:
    
    
};


void Person::PersinImpl::greet(Person* person)
{
    cout << "hello my name is " << person->name << endl;
}

Person::Person() : impl(new PersinImpl)
{
    
}

Person::~Person()
{
    delete impl;
}

void Person::greet()
{
    impl->greet(this);
}

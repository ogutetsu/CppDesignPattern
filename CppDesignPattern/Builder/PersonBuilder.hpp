//
//  PersonBuilder.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/12.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef PersonBuilder_hpp
#define PersonBuilder_hpp

#include <stdio.h>
#include "Person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
    Person& person;
    explicit PersonBuilderBase(Person& person) : person(person) {}
    
public:
    operator Person() const
    {
        return std::move(person);
    }
    
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
    
};


class PersonBuilder : public PersonBuilderBase
{
    Person p;
public:
    PersonBuilder() : PersonBuilderBase { p }
    {
        
    }
    
};


#endif /* PersonBuilder_hpp */

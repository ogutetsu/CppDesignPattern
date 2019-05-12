//
//  PersonAddressBuilder.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/12.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef PersonAddressBuilder_hpp
#define PersonAddressBuilder_hpp

#include <stdio.h>

#include "PersonBuilder.hpp"

class PersonAddressBuilder : public PersonBuilderBase
{
    typedef PersonAddressBuilder Self;
public:
    explicit PersonAddressBuilder(Person& person) : PersonBuilderBase{person}
    {
        
    }
    
    Self& At(string streetAddress)
    {
        person.streetAddress = streetAddress;
        return *this;
    }
    
    Self& WithPostCode(string postCode)
    {
        person.postCode = postCode;
        return *this;
    }
    
    Self& In(string city)
    {
        person.city = city;
        return *this;
    }
};


#endif /* PersonAddressBuilder_hpp */

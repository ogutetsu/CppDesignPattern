//
//  PersonJobBuilder.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/12.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef PersonJobBuilder_hpp
#define PersonJobBuilder_hpp

#include <stdio.h>
#include "PersonBuilder.hpp"

class PersonJobBuilder : public PersonBuilderBase
{
    typedef PersonJobBuilder Self;
public:
    explicit PersonJobBuilder(Person& person) : PersonBuilderBase { person }
    {
        
    }
    
    Self& At(string companyName)
    {
        person.companyName = companyName;
        return *this;
    }
    
    Self& As_a(string position)
    {
        person.position = position;
        return *this;
    }
    
    Self& earning(int annualIncome)
    {
        person.annualIncome = annualIncome;
        return *this;
    }
    
};


#endif /* PersonJobBuilder_hpp */

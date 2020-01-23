//
//  BuilderFactets.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/12.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "BuilderFactets.hpp"

#include "../Builder/Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

void BuilderFactetsMain()
{
    Person p = Person::create()
    .lives().At("123 London Road").WithPostCode("SW1 1GB").In("London")
    .works().At("PragmaSoft").As_a("consultant").earning(10e6);
    
    cout << p << endl;
    
}




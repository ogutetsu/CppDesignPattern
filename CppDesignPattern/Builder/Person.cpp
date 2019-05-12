//
//  Person.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/12.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Person.hpp"
#include "PersonBuilder.hpp"

PersonBuilder Person::create()
{
    return PersonBuilder{};
}

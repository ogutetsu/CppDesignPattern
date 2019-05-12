//
//  PersonBuilder.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/12.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder{ person };
}

PersonJobBuilder PersonBuilderBase::works() const
{
    return PersonJobBuilder{ person };
}

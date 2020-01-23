//
//  Person.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/07.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>

using namespace std;

namespace Bridge
{

    class Person {
    public:
        string name;

        class PersinImpl;
        PersinImpl* impl;

        Person();
        ~Person();

        void greet();

    };

}

#endif /* Person_hpp */

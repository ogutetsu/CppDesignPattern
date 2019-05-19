//
//  AbstractFactory.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/20.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "AbstractFactory.hpp"

#include "HotDrinkFactory.hpp"
#include "DrinkFactory.hpp"

unique_ptr<HotDrink> MakeDrink(string type)
{
    unique_ptr<HotDrink> drink;
    if(type == "tea")
    {
        drink = make_unique<Tea>();
        drink->prepare(200);
    }
    else{
        drink = make_unique<Coffee>();
        drink->prepare(50);
    }
    return drink;
}

void AbstructFactoryMain()
{
    DrinkFactory df;
    auto c = df.MakeDrink("coffee");
    
}



//
//  DrinkFactory.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/20.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef DrinkFactory_hpp
#define DrinkFactory_hpp

#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <map>
using namespace std;

class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> hotFactory;
public:
    DrinkFactory() {
        hotFactory["coffee"] = make_unique<CoffeeFactory>();
        hotFactory["tea"] = make_unique<TeaFactory>();
    }
    
    unique_ptr<HotDrink> MakeDrink(const string& name)
    {
        auto drink = hotFactory[name]->make();
        drink->prepare(200);
        return drink;
    }
};


#endif /* DrinkFactory_hpp */

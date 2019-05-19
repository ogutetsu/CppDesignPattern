//
//  HotDringFactory.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/20.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef HotDrinkFactory_hpp
#define HotDrinkFactory_hpp

#include "HotDrink.hpp"

struct HotDrinkFactory
{
    virtual unique_ptr<HotDrink> make() const =0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    }
};





#endif /* HotDrinkFactory_hpp */

//
//  HotDrink.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/20.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef HotDrink_hpp
#define HotDrink_hpp


#include <iostream>

using namespace std;


struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override {
        cout << "Take tea bag. boil water, pour " << volume
        << "ml, add some lemon\n";
    }
};

struct Coffee : HotDrink
{
    void prepare(int volume) override {
        cout << "Grind some beans, boil water, pour " << volume
        << "ml, add cream, enjoy!\n";
    }
};

#endif /* HotDrink_hpp */

//
//  Multiton.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/02.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Multiton.hpp"
#include <string>
#include <map>
#include <memory>
#include <iostream>

using namespace std;


enum class Importance
{
    primary,
    secondary,
    tertiary
};


template <typename T, typename Key = string>
class Multiton
{
public:
    static shared_ptr<T> get(const Key& key)
    {
        if(const auto it = instances.find(key);
           it != instances.end())
        {
            return it->second;
        }
        auto instance = make_shared<T>();
        instances[key] = instance;
        return instance;
    }
protected:
    Multiton() = default;
    virtual ~Multiton() = default;
private:
    static map<Key, shared_ptr<T>> instances;
    
};


template <typename T, typename Key>
map<Key, shared_ptr<T>> Multiton<T,Key>::instances;



class Printer
{
public:
    Printer()
    {
        ++Printer::totalInstanceCount;
        cout << "A total of " <<
        Printer::totalInstanceCount <<
        " instances created so far\n";
    }
private:
    static int totalInstanceCount;
    
};
int Printer::totalInstanceCount = 0;


void MultitonMain()
{
    typedef Multiton<Printer, Importance> mt;
    
    auto main = mt::get(Importance::primary);
    auto aux = mt::get(Importance::secondary);
    auto aux2 = mt::get(Importance::secondary);
}

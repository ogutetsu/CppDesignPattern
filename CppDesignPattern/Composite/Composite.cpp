//
//  Composite.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/10.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Composite.hpp"
#include <iostream>
#include <vector>

using namespace std;

struct GraphicObject
{
    virtual void Draw() = 0;
};

struct CompositeCircle : GraphicObject
{
    void Draw() override {
        cout << "Circle" << endl;
    }
};


struct Group : GraphicObject
{
    string name;
    vector<GraphicObject*> objects;
    
    Group(const string& name) : name(name) {}
    
    void Draw() override
    {
        cout << "Group " << name.c_str() << "contains: " << endl;
        for(auto&& o : objects)
            o->Draw();
    }
};


void CompositeMain()
{
    Group root("root");
    CompositeCircle c1, c2;
    
    root.objects.push_back(&c1);
    
    Group subgroup("sub");
    subgroup.objects.push_back(&c2);
    
    root.objects.push_back(&subgroup);
    
    root.Draw();
    
}



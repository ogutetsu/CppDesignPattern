//
//  DependencyInversionPrinciple.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/07.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "DependencyInversionPrinciple.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>

using namespace std;

enum class Relationship
{
    parent,
    child,
    sibling,
};

struct Person
{
    string name;
};

struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string& name) = 0;
    
};

//low level
struct Relationships : RelationshipBrowser
{
    vector<tuple<Person, Relationship, Person>> relations;
    
    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }
    
    vector<Person> find_all_children_of(const string& name) override
    {
        vector<Person> result;
        for(auto&& [first, rel, second] : relations)
        {
            if(first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;
    }
    
};

//high level
struct Research
{
    Research(RelationshipBrowser& browser)
    {
        for(auto& child : browser.find_all_children_of("John"))
        {
            cout << "John has a child called " << child.name << endl;
        }
    }
    
//    Research(Relationships& relationships)
//    {
//        auto& relations = relationships.relations;
//        for(auto&& [first, rel, second] : relations)
//        {
//            if(first.name == "John" && rel == Relationship::parent)
//            {
//                cout << "John has a child called " << second.name << endl;
//            }
//        }
//    }
};

void DependencyMain()
{
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};
    
    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);
    
    Research _(relationships);
    
    
}



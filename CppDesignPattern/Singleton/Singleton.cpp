//
//  Singleton.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/30.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Singleton.hpp"


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;


class SingletonDatabase
{
    SingletonDatabase()
    {
        cout << "Initializing database\n";
        ifstream ifs("singletondbsample.txt");
        
        string s, s2;
        while(getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = atoi(s2.c_str());
            capitals[s] = pop;
        }
    }
    map<string, int> capitals;
public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;
    
    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }
    
    int GetPopulation(const string& name)
    {
        return capitals[name];
    }
};



void SingletonMain()
{
    string city = "Tokyo";
    cout << city << " has population " <<
        SingletonDatabase::get().GetPopulation("Tokyo") << endl;
    
}

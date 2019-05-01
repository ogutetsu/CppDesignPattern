//
//  SingleResponsibilityPrinciple.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/01.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "SingleResponsibilityPrinciple.hpp"


#include <string>
#include <vector>
#include <fstream>


using namespace std;


struct Joutnal
{
    string title;
    vector<string> entries;
    
    Joutnal(const string &title) : title(title) {}
    
    void add_entry(const string& entry)
    {
        static int count = 1;
        entries.push_back(to_string(count) + ": " + entry);
        count++;
    }
    
    void save(const string& filename)
    {
        ofstream ofs(filename);
        for(auto& e : entries)
        {
            ofs << e << endl;
        }
    }
};

struct PersistenceManager
{
    static void save(const Joutnal& journal, const string& filename)
    {
        ofstream ofs(filename);
        for(auto& e : journal.entries)
        {
            ofs << e << endl;
        }
    }
}


void SingleResponsibilityPrincipleMain()
{
    Joutnal journal{"Dear Diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("i cried today");
    
    //journal.save("diary.txt");
    
    PersistenceManager pm;
    pm.save(journal, "diary.txt");
    
    
}




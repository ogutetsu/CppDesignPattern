//
//  Printer.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/02.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Printer.hpp"
#include <string>
#include <iostream>
using namespace std;

class Printer
{
    static int id;
public:
    int GetId() const { return id; }
    void SetId(int value) { id = value; }
};
int Printer::id = 0;

void PrinterMain()
{
    Printer p;
    int id = p.GetId();
    
    cout << id << endl;
    
    
}

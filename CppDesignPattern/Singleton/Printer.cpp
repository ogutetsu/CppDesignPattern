//
//  Printer.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/02.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Printer.hpp"

class Printer
{
    static int id;
public:
    int GetId() const { return id; }
    void SetId(int value) { id = value; }
};


void PrinterMain()
{
    Printer p;
    int id = p.GetId();
    
    
    
}

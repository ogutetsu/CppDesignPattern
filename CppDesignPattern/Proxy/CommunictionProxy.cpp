//
//  CommunictionProxy.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/10/25.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "CommunictionProxy.hpp"
#include <string>
#include <iostream>

using namespace std;

struct Pingable
{
    virtual wstring ping(const wstring& message) = 0;
};

struct Pong : Pingable
{
    wstring ping(const wstring& message) override
    {
        return message + L" pong";
    }
};

void tryit(Pingable& pp)
{
    wcout << pp.ping(L"ping") << endl;
}

void CommunicationProxyMain()
{
    Pong pp;
    for(int i = 0; i < 3; i++)
    {
        tryit(pp);
    }
    
}

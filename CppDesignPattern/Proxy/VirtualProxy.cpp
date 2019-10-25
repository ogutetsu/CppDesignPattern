//
//  VirtualProxy.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/10/25.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "VirtualProxy.hpp"
#include <string>
#include <iostream>

using namespace std;

struct Image
{
    virtual void draw() = 0;
};

struct Bitmap : Image
{
    Bitmap(const string& filename)
    {
        cout << "Loading bitmap from " << filename << endl;
    }
    
    void draw() override {
        cout << "Drawing bitmap" << endl;
    }
};

struct LazyBitmap : Image
{
    LazyBitmap(const string& filename) : filename(filename) {}
    
    void draw() override {
        if(!bitmap)
        {
            bitmap = new Bitmap(filename);
        }
        bitmap->draw();
    }
    
private:
    string filename;
    Bitmap* bitmap{nullptr};
};


void VirtualProxyMain()
{
    LazyBitmap bmp{"test.png"};
    bmp.draw();
    
}

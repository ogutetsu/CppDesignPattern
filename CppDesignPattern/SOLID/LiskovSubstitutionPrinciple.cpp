//
//  LiskovSubstitutionPrinciple.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/07.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "LiskovSubstitutionPrinciple.hpp"

#include <iostream>

using namespace std;


class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int width, int height) : width(width), height(height) {}
    
    int getWidth() const
    {
        return width;
    }
    virtual void setWidth(int width)
    {
        Rectangle::width = width;
    }
    int getHeight() const
    {
        return height;
    }
    virtual void setHeight(int height)
    {
        Rectangle::height = height;
    }
    
    int area() const { return width * height; }
};


class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size, size) {}
    
    void setWidth(int width) override
    {
        this->width = this->height = width;
    }
    void setHeight(int height) override
    {
        this->width = this->height = height;
    }
    
};



void process(Rectangle& r)
{
    int w = r.getWidth();
    r.setHeight(10);
    
    cout << "expected area = " << (w*10) << ", got " << r.area() << endl;
}


void LiskovMain()
{
    Rectangle r{3,4};
    process(r);
    
    Square sq{5};
    process(sq);
}

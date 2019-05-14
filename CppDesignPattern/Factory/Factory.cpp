//
//  Factory.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/13.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Factory.hpp"

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

enum class PointType
{
    cartesian,
    polar
};

struct Point
{
public:
    Point(float x, float y) : x(x), y(y) {}
    

    float x,y;
    
//    static Point NewCartesian(float x, float y)
//    {
//        return { x, y };
//    }
//    static Point NewPolar(float r, float theta)
//    {
//        return { r*cos(theta), r*sin(theta) };
//    }
    
    friend ostream &operator<<(ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
    
};

struct PointFactory
{
    static Point NewCartesian(float x, float y)
    {
        return { x, y };
    }
    static Point NewPolar(float r, float theta)
    {
        return { r*cos(theta), r*sin(theta) };
    }
};


void FactoryMain()
{
    auto pf = PointFactory::NewPolar(5, M_PI_4);
    cout << pf << endl;
    
    //auto p = Point::NewPolar(5, M_PI_4);
    //cout << p << endl;
    
}

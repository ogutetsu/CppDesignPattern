//
//  Geometry.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/05.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef Geometry_hpp
#define Geometry_hpp

#include <stdio.h>
#include <vector>
#include <functional>

using namespace std;


struct Point
{
    int x, y;
    
    friend size_t HashValue(const Point& p)
    {
        size_t value;
        value = hash<size_t>()(p.x+p.y);
        return value;
    }
    
};

struct Line
{
    Point start, end;
    
    friend size_t HashValue(const Line& line)
    {
        size_t value;
        value = hash<size_t>()(HashValue(line.start)+HashValue(line.end));
        return value;
    }
};

struct VectorObject
{
    virtual vector<Line>::iterator begin() = 0;
    virtual vector<Line>::iterator end() = 0;
};

struct VectorRectangle : VectorObject
{
    VectorRectangle(int x, int y, int width, int height)
    {
        lines.emplace_back(Line{Point{x,y}, Point{x+width, y}});
        lines.emplace_back(Line{Point{x + width,y}, Point{x+width, y+height}});
        lines.emplace_back(Line{Point{x,y}, Point{x, y+height}});
        lines.emplace_back(Line{Point{x,y+height}, Point{x+width, y+height}});
        
    }
    virtual vector<Line>::iterator begin() { return lines.begin(); }
    virtual vector<Line>::iterator end() { return lines.end(); }
private:
    vector<Line> lines;
    
};


#endif /* Geometry_hpp */

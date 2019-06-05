//
//  Adapter.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/05.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Adapter.hpp"
#include "Geometry.hpp"
#include <vector>
#include <map>

using namespace std;

vector<shared_ptr<VectorObject>> VectorObjects {
    make_shared<VectorRectangle>(10,10,100,100),
    make_shared<VectorRectangle>(30,30,60,60)
};


struct LineToPointAdapter
{
    typedef vector<Point> Points;
    
    LineToPointAdapter(Line& line)
    {
        
        int left = min(line.start.x, line.end.x);
        int right = max(line.start.x, line.end.x);
        int top = min(line.start.y, line.end.y);
        int bottom = max(line.start.y, line.end.y);
        int dx = right-left;
        int dy = line.end.y-line.start.y;
        
        if(dx == 0)
        {
            for(int y = top; y <= bottom; ++y)
            {
                points.emplace_back(Point{left,y});
            }
        }
        else if(dy == 0)
        {
            for(int x = left; x <= right; ++x)
            {
                points.emplace_back(Point{x,top});
            }
        }
        
    }
    virtual Points::iterator begin() { return points.begin(); }
    virtual Points::iterator end() { return points.end(); }
    
private:
    Points points;
    
};



struct LineToPointCachingAdapter
{
    typedef vector<Point> Points;
    
    LineToPointCachingAdapter(Line& line)
    {
        linehash = HashValue(line);
        if(cache.find(linehash) != cache.end()) return;
        
        Points points;
        
        int left = min(line.start.x, line.end.x);
        int right = max(line.start.x, line.end.x);
        int top = min(line.start.y, line.end.y);
        int bottom = max(line.start.y, line.end.y);
        int dx = right-left;
        int dy = line.end.y-line.start.y;
        
        if(dx == 0)
        {
            for(int y = top; y <= bottom; ++y)
            {
                points.emplace_back(Point{left,y});
            }
        }
        else if(dy == 0)
        {
            for(int x = left; x <= right; ++x)
            {
                points.emplace_back(Point{x,top});
            }
        }
        
        cache[linehash] = points;
        
    }
    
    virtual Points::iterator begin() { return cache[linehash].begin(); }
    virtual Points::iterator end() { return cache[linehash].end(); }
    
private:
    size_t linehash;
    static map<size_t, Points> cache;
    
};


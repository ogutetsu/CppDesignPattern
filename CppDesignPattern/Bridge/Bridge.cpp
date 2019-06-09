//
//  Bridge.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/07.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Bridge.hpp"
#include <iostream>

using namespace std;

struct Renderer
{
    virtual void RenderCircle(float x, float y, float radius) = 0;
};

struct RasterRenderer : Renderer
{
    void RenderCircle(float x, float y, float radius) override
    {
        cout << "Rasterizing a circle of raidus" << radius << endl;
    }
};



struct VectorRenderer : Renderer
{
    void RenderCircle(float x, float y, float radius) override
    {
        cout << "Drawing a vector circle of raidus" << radius << endl;
    }
};

struct Shape
{
protected:
    Renderer& renderer;
    Shape(Renderer& renderer) : renderer(renderer) {}
public:
    virtual void Draw() = 0;
    virtual void Resize(float factor) = 0;
    
};

struct Circle : Shape
{
    Circle(Renderer& renderer, float x, float y, float radius) :
    Shape(renderer), x{x}, y{y}, radius{radius}
    {
        
    }
    
    float x, y, radius;
    
    void Draw() override {
        renderer.RenderCircle(x, y, radius);
    }
    
    void Resize(float factor) override {
        radius *= factor;
    }
    
};


void BridgeMain()
{
    RasterRenderer rr;
    Circle RasterCircle{rr, 5, 5, 5};
    RasterCircle.Draw();
    RasterCircle.Resize(2);
    RasterCircle.Draw();
}

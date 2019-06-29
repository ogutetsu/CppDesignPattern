//
//  Decorator.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/27.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Decorator.hpp"
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;
    
    Circle() {}
    Circle(float radius) : radius(radius) {}
    
    void resize(float factor)
    {
        radius *= factor;
    }
    
    string str() const override
    {
        ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
};


struct Square : Shape{
    float side;
    
    Square() {}
    Square(float side) : side(side) {}
    
    string str() const override {
        ostringstream oss;
        oss << "A square of side " << side;
        return oss.str();
    }
};

struct ColoredShape : Shape
{
    Shape& shape;
    string color;
    
    ColoredShape(Shape& shape, const string& color) : shape(shape), color(color)
    {}
    
    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
    
};

struct TransparentShape : Shape{
    Shape& shape;
    uint8_t transparency;
    
    TransparentShape(Shape& shape, uint8_t transparency) : shape(shape), transparency(transparency) {}
    
    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has "
        << static_cast<float>(transparency) / 255.f * 100.f
        << " % transparency";
        return oss.str();
    }
};

template<typename T> struct ColoredShape2 : T
{
    static_assert(is_base_of<Shape, T>::value,
                  "Template argument must be a Shape");
    
    string color;
    
    ColoredShape2() {}
    
    //TransparentShape2<ColoredShape2<Square>> sq{10, "red", 44}
    template <typename...Args>
    ColoredShape2(const string& color, Args ...args) : T(std::forward<Args>(args)...), color{color} {}
    
    string str() const override
    {
        ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};



template<typename T> struct TransparentShape2 : T{
    uint8_t transparency;
    
    template<typename...Args>
    TransparentShape2(uint8_t transparency, Args ...args)
    : T(std::forward<Args>(args)...), transparency{transparency}
    {}
    
    string str() const override {
        ostringstream oss;
        oss << T::str() << " has "
        << static_cast<float>(transparency) / 255.f * 100.f
        << " % transparency";
        return oss.str();
    }
};


void DecoratorMain()
{
    /*
    Square square{5};
    ColoredShape red_square{square, "red"};
    cout << square.str() << endl << red_square.str() << endl;
    
    TransparentShape my_square{red_square, 51};
    cout << my_square.str() << endl;
    */
    
    ColoredShape2<Circle> green_circle{"green", 5};
    green_circle.resize(2);
    cout << green_circle.str() << endl;
    
    TransparentShape2<ColoredShape2<Square>> square{51, "blue", 10};
    cout << square.str() << endl;
    
}

//
//  Builder.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/09.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Builder.hpp"
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>

using namespace std;


class HtmlBuilder;

class HtmlElement
{
    friend class HtmlBuilder;
    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;
    
    HtmlElement() {}
    
    HtmlElement(const string &name, const string &text) : name(name), text(text) {}
    
public:
    string str(int indent = 0) const {
        ostringstream oss;
        string indentstr(indent_size*indent, ' ');
        oss << indentstr << "<" << name << ">" << endl;
        if(text.size() > 0)
            oss << string(indent_size*(indent+1), ' ') << text << endl;
        
        for(const auto &e: elements)
            oss << e.str(indent + 1);
        
        oss << indentstr << "</" << name << ">" << endl;
        return oss.str();
    }
    
    static unique_ptr<HtmlBuilder> build(string rootName)
    {
        return make_unique<HtmlBuilder>(rootName);
    }
    
};

class HtmlBuilder
{
    HtmlElement root;
public:
    HtmlBuilder(string rootName)
    {
        root.name = rootName;
    }
    HtmlBuilder& addChild(string childName, string childText)
    {
        HtmlElement e{childName, childText};
        root.elements.emplace_back(e);
        return *this;
    }
    HtmlBuilder* pAddChild(string childName, string childText)
    {
        HtmlElement e{childName, childText};
        root.elements.emplace_back(e);
        return this;
    }
    
    string str() const { return root.str(); }
    
    operator HtmlElement() const { return root; }
};


void BuilderMain()
{
    auto text = "hello";
    string output;
    output += "<p>";
    output += text;
    output += "<p>";
    cout << output << endl;
    
    string words[] = {"hello", "world" };
    ostringstream oss;
    oss << "<ul>";
    for(auto w : words)
        oss << " <li>" << w << "</li>";
    oss << "</ul>";
    cout << oss.str() << endl;
    
    HtmlBuilder builder{"ul"};
    builder.addChild("li", "hello").addChild("li", "world");
    
    cout << builder.str() << endl;
    
    auto builder2 = HtmlElement::build("ul")->pAddChild("li", "hello")->pAddChild("li", "world");
    
    cout << builder2 << endl;
    
    
}


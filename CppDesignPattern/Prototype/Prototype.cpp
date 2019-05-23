//
//  Prototype.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/24.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "Prototype.hpp"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

struct Address
{
    string street, city;
    int suite;
    Address(const string& street, const string& city, int suite) :
        street(street), city(city), suite(suite)
    {}
    
    friend ostream& operator<<(ostream& os, const Address& obj)
    {
        return os << "street: " << obj.street << " city: " << obj.city << " suite: " << obj.suite;
    }
    
};


struct Contact
{
    string name;
    Address address;
    
    Contact(const string& name, const Address& address) :
        name(name), address(address)
    {}
    
    friend ostream& operator<<(ostream& os, Contact& contact)
    {
        return os << "name: " << contact.name << " address: " << contact.address;
    }
};


void PrototypeMain()
{
    Contact john{"John Doe", Address{"123 East Dr", "London", 123}};
    //Contact jane{"Jane Smith", Address{"123 East Dr", "London", 103}};
    Contact jane = john;
    jane.name = "Jane Smith";
    jane.address.suite = 103;
    cout << john << endl << jane << endl;
}

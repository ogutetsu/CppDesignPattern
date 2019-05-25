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
    
    Address(const Address& address) :
    street{address.street}, city{address.city}, suite{address.suite}
    {
        
    }
    
    
    friend ostream& operator<<(ostream& os, const Address& obj)
    {
        return os << "street: " << obj.street << " city: " << obj.city << " suite: " << obj.suite;
    }
    
};


struct Contact
{
    string name;
    Address* address;
    
    Contact(const string& name, Address* address) :
        name(name), address(address)
    {}
    
    Contact(const Contact& other) :
    name { other.name }, address { new Address { *other.address }}
    {
        
    }
    
    friend ostream& operator<<(ostream& os, Contact& contact)
    {
        return os << "name: " << contact.name << " address: " << contact.address;
    }
};


void PrototypeMain()
{
    Contact john{"John Doe", new Address{"123 East Dr", "London", 123}};
    //Contact jane{"Jane Smith", Address{"123 East Dr", "London", 103}};
    Contact jane {john}; //shallow copy
    jane.name = "Jane Smith";
    jane.address->suite = 103;
    cout << john << endl << jane << endl;
}

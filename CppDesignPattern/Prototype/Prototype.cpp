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
    
    ~Contact() { delete address; }
    
    friend ostream& operator<<(ostream& os, Contact& contact)
    {
        return os << "name: " << contact.name << " address: " << *contact.address;
    }
};

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee
        (const string& name, const int suite)
    {
        static Contact p{"", new Address {"123 East Dr", "London", 0 }};
        return new_employee(name, suite, p);
    }
private:
    static unique_ptr<Contact> new_employee(const string& name, int suite, const Contact& prototype)
    {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

void PrototypeMain()
{
    auto john = EmployeeFactory::new_main_office_employee("John", 123);
    
    cout << *john <<  endl;
}

//
//  Person.hpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/05/12.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>
#include <iostream>


using namespace std;

class PersonBuilder;

class Person
{
    //address
    string streetAddress, postCode, city;
    
    //employment
    string companyName, position;
    int annualIncome{0};
    
    Person()
    {
        cout << "Person created/n";
    }
    
public:
    ~Person()
    {
        cout << "Person destroyed/n";
    }
    
    static PersonBuilder create();
    
    Person(Person&& other)
    : streetAddress{move(other.streetAddress)},
    postCode{move(other.postCode)},
    city{move(other.city)},
    companyName{move(other.companyName)},
    position{move(other.position)},
    annualIncome{move(other.annualIncome)}
    {
        
    }
    
    Person& operator=(Person&& other)
    {
        if(this == &other) return *this;
        
        streetAddress = move(other.streetAddress);
        postCode = move(other.postCode);
        city = move(other.city);
        companyName = move(other.companyName);
        position = move(other.position);
        annualIncome = other.annualIncome;
        return *this;
    }
    
    friend ostream& operator <<(ostream& os, const Person& obj)
    {
        return os
        << "street address: " << obj.streetAddress
        << " post code: " << obj.postCode
        << " city: " << obj.city
        << " company name: " << obj.companyName
        << " position: " << obj.position
        << " annual income: " << obj.annualIncome;
    }
    
    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
    
    
};


#endif /* Person_hpp */


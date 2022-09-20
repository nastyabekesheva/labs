//
//  TemplateEmployee.hpp
//  Employee
//
//  Created by Nastya Bekesheva on 25.05.2022.
//

#ifndef TemplateEmployee_hpp
#define TemplateEmployee_hpp

#pragma once

#include <stdio.h>
#include <string>
using namespace std;

template<typename T>
class TemplateEmployee{
protected:
    string name;
    int age;
    string position;
    int expirience;
    
public:
    TemplateEmployee();//   Default constructor
    TemplateEmployee(string name, int age, string position, int expirience);//   Parameterized constructor
    TemplateEmployee(const TemplateEmployee<T> & other);//   Copy constructor
    template<typename U>
    TemplateEmployee(const TemplateEmployee<U> & other);//   Copy constructor other type
    virtual ~TemplateEmployee();//    Destructor
    
//    Setetrs
    void set_name(string name);//   Sets name, takes one string as argument
    void set_age(int age);//   Sets age, takes one int as argument
    void set_position(string position);//   Sets position, takes one string as argument
    void set_expirience(int expirience);//   Sets expirience, takes one int as argument
    void set_info(string name, int age, string position, int expirience);//   Sets all info, takes two strings and two ints as arguments
    
//    Getters
    string get_name();//   Gets name property of an object
    int get_age();//   Gets age property of an object
    string get_position();//   Gets position property of an object
    int get_expirience();//   Gets expirience property of an object
    string get_name() const;//   Gets name property of an object
    int get_age() const;//   Gets age property of an object
    string get_position() const;//   Gets position property of an object
    int get_expirience() const;//   Gets expirience property of an object
    
//    Overloaded operators
    TemplateEmployee<T> & operator = (const TemplateEmployee<T> & other);//   Overload assigment
    
    template<typename U>
    friend ostream & operator << (ostream & output, const TemplateEmployee<U> & employee);//   Overload output
    template<typename U>
    friend istream & operator >> (ostream & input, TemplateEmployee<T> & employee);//   Overload input
};

template<typename T>
class CoolTemplateEmployee: public TemplateEmployee<T>{
private:
    
    int amount;
    T *bonus;
    
public:
    
    CoolTemplateEmployee();//   Default constructor
    CoolTemplateEmployee(string name, int age, string position, int expirience, int amount, T * bonus);//   Parameterized constructor
    CoolTemplateEmployee(const TemplateEmployee<T> & other);//   Copy constructor
    CoolTemplateEmployee(const CoolTemplateEmployee<T> & other);//   Copy constructor
    template<typename U>
    CoolTemplateEmployee(const TemplateEmployee<U> & other);//   Copy constructor other type
    template<typename U>
    CoolTemplateEmployee(const CoolTemplateEmployee<U> & other);//   Copy constructor other type
    ~CoolTemplateEmployee();//    Destructor
    
//    Setetrs
    void set_bonus(int amount, T * bonus);//  Sets bonuses and ita amount, takes int and array as argumets
    
//    Getters
    T * get_bonus();//    Returns bonuses of an object
    int get_amount();//    Returns amount of bonuses of an object
    int get_amount() const;
    T * get_bonus() const;
    
//    Overloaded operators
    bool operator == (const CoolTemplateEmployee<T> & other);//   Overload comparasion
    
    template<typename U>
    friend ostream & operator << (ostream & output, const CoolTemplateEmployee<T> & employee);//   Overload output
    template<typename U>
    friend istream & operator >> (ostream & input, CoolTemplateEmployee<T> & employee);//   Overload input
};

#endif /* TemplateEmployee_hpp */

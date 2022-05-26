//
//  main.cpp
//  Employee
//
//  Created by Nastya Bekesheva on 16.05.2022.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include "TemplateEmployee.hpp"
#include "TemplateEmployee.cpp"
using namespace std;

class Employee{
protected:
    string name;
    int age;
    string position;
    int expirience;
    
public:
    
    Employee();//   Default constructor
    Employee(string name, int age, string position, int expirience);//   Parameterized constructor
    Employee(const Employee & other);//   Copy constructor
    virtual ~Employee();//    Destructor
    
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
    
//    Overloaded operators
    Employee & operator = (const Employee & other);//   Overload assigment
    
    friend ostream & operator << (ostream & output, const Employee & employee);//   Overload output
    friend istream & operator >> (ostream & input, Employee & employee);//   Overload input
};


class CoolEmployee: public Employee{
private:
    
    int amount;
    int *bonus;
    
public:
    
    CoolEmployee();//   Default constructor
    CoolEmployee(string name, int age, string position, int expirience, int amount, int * bonus);//   Parameterized constructor
    CoolEmployee(const Employee & other);//   Copy constructor
    CoolEmployee(const CoolEmployee & other);//   Copy constructor
    ~CoolEmployee();//    Destructor
    
//    Setetrs
    void set_bonus(int amount, int * bonus);//  Sets bonuses and ita amount, takes int and array as argumets
    
//    Getters
    int * get_bonus();//    Returns bonuses of an object
    int get_amount();//    Returns amount of bonuses of an object
    int get_amount() const;
    int * get_bonus() const;
    
//    Overloaded operators
    bool operator == (const CoolEmployee & other);//   Overload comparasion
    
    friend ostream & operator << (ostream & output, const CoolEmployee & employee);//   Overload output
    friend istream & operator >> (ostream & input, CoolEmployee & employee);//   Overload input
};

Employee::Employee(){ }

Employee::Employee(string name, int age, string position, int expirience){
    this->name = name, this->age = age, this->position = position, this->expirience = expirience;
}

Employee::Employee(const Employee & other){
    this->name = other.name, this->age = other.age, this->position = other.position, this->expirience = other.expirience;
}

Employee::~Employee() {}

void Employee::set_name(string name){ this->name = name; }

void Employee::set_age(int age){ this->age = age; }

void Employee::set_position(string position){ this->position = position; }

void Employee::set_expirience(int expirience){ this->expirience = expirience; }

void Employee::set_info(string name, int age, string position, int expirience){ this->name = name, this->age = age, this->position = position, this->expirience = expirience; }

string Employee::get_name(){ return this->name; }

int Employee::get_age(){ return this->age; }

string Employee::get_position(){ return this->position; }

int Employee::get_expirience(){ return this->expirience; }

CoolEmployee::CoolEmployee() : Employee(){ };

CoolEmployee::CoolEmployee(string name, int age, string position, int expirience, int amount, int *bonus) : Employee(name, age, position, expirience){
    this->amount = amount;
    this->bonus = new int[amount];
    for(int i = 0; i < amount; i++){
        this->bonus[i] = bonus[i];
    }
}

CoolEmployee::CoolEmployee(const Employee & other) : Employee(other){ }

CoolEmployee::CoolEmployee(const CoolEmployee & other) : Employee(other){
    this->amount = other.amount;
    this->bonus = new int[amount];
    for(int i = 0; i < amount; i++){
        this->bonus[i] = other.bonus[i];
    }
}

CoolEmployee::~CoolEmployee(){ delete [] bonus; }

void CoolEmployee::set_bonus(int amount, int *bonus){
    this->bonus = new int[amount];
    this->amount = amount;
    for(int i = 0; i < amount; i++){
        this->bonus[i] = bonus[i];
    }
}

int * CoolEmployee::get_bonus(){ return this->bonus; }

int * CoolEmployee::get_bonus() const { return this->bonus; }

int CoolEmployee::get_amount(){ return this->amount; }

int CoolEmployee::get_amount() const{ return this->amount; }

Employee & Employee::operator = (const Employee & other){
    this->name = other.name, this->age = other.age, this->position = other.position, this->expirience = other.expirience;
    return *this;
}

bool CoolEmployee::operator == (const CoolEmployee &other){
    bool temp = false;
    if(this->amount != other.amount){
        temp = true;
        for(int i = 0; i < this->amount; i++){
            if(this->bonus[i] != other.bonus[i]){
                temp = false;
            }
        }
    }
    else{
        return temp;
    }
    return temp;
}

ostream & operator << (ostream & output, const Employee & employee){
    output << "Name: " << employee.name << endl << "Age: " << employee.age << endl << "Position: " << employee.position << endl << "Expirience: " << employee.expirience << endl;
    
    return output;
}

istream & operator >> (istream & input, Employee & employee){
    cout << "Enter name: ";
    string name;
    input >> name;
    cout << "Enter age: ";
    int age;
    input >> age;
    cout << "Enter position: ";
    string position;
    input >> position;
    cout << "Enter expirience: ";
    int expirience;
    input >> expirience;
    
    employee.set_info(name, age, position, expirience);
    
    return input;
}

ostream & operator << (ostream & output, const CoolEmployee & employee){
    output << "Name: " << employee.name << endl << "Age: " << employee.age << endl << "Position: " << employee.position << endl << "Expirience: " << employee.expirience << endl << "Bonus: [ ";
    
    for(int i = 0; i < employee.get_amount(); i++){
        cout << employee.get_bonus()[i] << " ";
    }
    cout << "]" << endl;
    
    return output;
}

istream & operator >> (istream & input, CoolEmployee & employee){
    cout << "Enter name: ";
    string name;
    input >> name;
    cout << "Enter age: ";
    int age;
    input >> age;
    cout << "Enter position: ";
    string position;
    input >> position;
    cout << "Enter expirience: ";
    int expirience;
    input >> expirience;
    
    employee.set_info(name, age, position, expirience);
    
    cout << "Enter amount: ";
    int amount;
    cin >> amount;
    cout << "Enter bonus: ";
    int * bonus = new int[amount];
    for(int i = 0; i < amount; i++){
        cin >> bonus[i];
    }
    employee.set_bonus(amount, bonus);
    
    return input;
}



int main() {
    TemplateEmployee<double> Me("Me", 18, "junior", 2);
    cout << Me;
    CoolTemplateEmployee<double> MeCool(Me);
    cin >> MeCool;
    cout << MeCool;
    
    return 0;
    
}

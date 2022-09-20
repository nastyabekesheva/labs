//
//  TemplateEmployee.cpp
//  Employee
//
//  Created by Nastya Bekesheva on 25.05.2022.
//
#include <iostream>
#include "TemplateEmployee.hpp"
using namespace std;

template<typename T>
TemplateEmployee<T>::TemplateEmployee(){ }

template<typename T>
TemplateEmployee<T>::TemplateEmployee(string name, int age, string position, int expirience){
    this->name = name, this->age = age, this->position = position, this->expirience = expirience;
}

template<typename T>
TemplateEmployee<T>::TemplateEmployee(const TemplateEmployee<T> & other){
    this->name = other.name, this->age = other.age, this->position = other.position, this->expirience = other.expirience;
}

template<typename T>
TemplateEmployee<T>::~TemplateEmployee() {}

template<typename T>
void TemplateEmployee<T>::set_name(string name){ this->name = name; }

template<typename T>
void TemplateEmployee<T>::set_age(int age){ this->age = age; }

template<typename T>
void TemplateEmployee<T>::set_position(string position){ this->position = position; }

template<typename T>
void TemplateEmployee<T>::set_expirience(int expirience){ this->expirience = expirience; }

template<typename T>
void TemplateEmployee<T>::set_info(string name, int age, string position, int expirience){ this->name = name, this->age = age, this->position = position, this->expirience = expirience; }

template<typename T>
string TemplateEmployee<T>::get_name(){ return this->name; }

template<typename T>
int TemplateEmployee<T>::get_age(){ return this->age; }

template<typename T>
string TemplateEmployee<T>::get_position(){ return this->position; }

template<typename T>
int TemplateEmployee<T>::get_expirience(){ return this->expirience; }

template<typename T>
string TemplateEmployee<T>::get_name() const{ return this->name; }

template<typename T>
int TemplateEmployee<T>::get_age() const { return this->age; }

template<typename T>
string TemplateEmployee<T>::get_position() const { return this->position; }

template<typename T>
int TemplateEmployee<T>::get_expirience() const{ return this->expirience; }

template<typename T>
CoolTemplateEmployee<T>::CoolTemplateEmployee() : TemplateEmployee<T>(){ };

template<typename T>
CoolTemplateEmployee<T>::CoolTemplateEmployee(string name, int age, string position, int expirience, int amount, T *bonus) : TemplateEmployee<T>(name, age, position, expirience){
    this->amount = amount;
    this->bonus = new T[amount];
    for(int i = 0; i < amount; i++){
        this->bonus[i] = bonus[i];
    }
}

template<typename T>
CoolTemplateEmployee<T>::CoolTemplateEmployee(const TemplateEmployee<T> & other) : TemplateEmployee<T>(other){ }

template<typename T>
CoolTemplateEmployee<T>::CoolTemplateEmployee(const CoolTemplateEmployee<T> & other) : TemplateEmployee<T>(other){
    this->amount = other.amount;
    this->bonus = new T[amount];
    for(int i = 0; i < amount; i++){
        this->bonus[i] = other.bonus[i];
    }
}

template<typename T>
CoolTemplateEmployee<T>::~CoolTemplateEmployee(){ delete [] bonus; }

template<typename T>
void CoolTemplateEmployee<T>::set_bonus(int amount, T *bonus){
    this->bonus = new T[amount];
    this->amount = amount;
    for(int i = 0; i < amount; i++){
        this->bonus[i] = bonus[i];
    }
}

template<typename T>
T * CoolTemplateEmployee<T>::get_bonus(){ return this->bonus; }

template<typename T>
T * CoolTemplateEmployee<T>::get_bonus() const { return this->bonus; }

template<typename T>
int CoolTemplateEmployee<T>::get_amount(){ return this->amount; }

template<typename T>
int CoolTemplateEmployee<T>::get_amount() const{ return this->amount; }

template<typename T>
TemplateEmployee<T> & TemplateEmployee<T>::operator = (const TemplateEmployee<T> & other){
    this->name = other.name, this->age = other.age, this->position = other.position, this->expirience = other.expirience;
    return *this;
}

template<typename T>
bool CoolTemplateEmployee<T>::operator == (const CoolTemplateEmployee<T> &other){
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

template<typename T>
ostream & operator << (ostream & output, const TemplateEmployee<T> & employee){
    output << "Name: " << employee.name << endl << "Age: " << employee.age << endl << "Position: " << employee.position << endl << "Expirience: " << employee.expirience << endl;
    
    return output;
}

template<typename T>
istream & operator >> (istream & input, TemplateEmployee<T> & employee){
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

template<typename T>
ostream & operator << (ostream & output, const CoolTemplateEmployee<T> & employee){
    output << "Name: " << employee.get_name() << endl << "Age: " << employee.get_age() << endl << "Position: " << employee.get_position() << endl << "Expirience: " << employee.get_expirience() << endl << "Bonus: [ ";
    
    for(int i = 0; i < employee.get_amount(); i++){
        cout << employee.get_bonus()[i] << " ";
    }
    cout << "]" << endl;
    
    return output;
}

template<typename T>
istream & operator >> (istream & input, CoolTemplateEmployee<T> & employee){
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
    T * bonus = new T[amount];
    for(int i = 0; i < amount; i++){
        cin >> bonus[i];
    }
    employee.set_bonus(amount, bonus);
    
    return input;
}

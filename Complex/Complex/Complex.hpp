//
//  Complex.hpp
//  Complex
//
//  Created by Nastya Bekesheva on 03.05.2022.
//

#pragma once
#ifndef Complex_hpp
#define Complex_hpp

#include <iostream>

template<typename T, typename U>
class complex {
    
protected:
    T _Re;
    T _Im;
    
public:
    
/*        Constructor         */
    
    //  Default
    complex();
    //  Parametr
    complex(T r, T i);
    //  Copy || Convert
    complex(const T& complex);
    
/*        Getters         */
    
    //  Return real part of complex number
    T& real();
    //  Return real part of complex number
    const T& real() const;
    //  Return imaginary part of complex number
    T& imag();
    //  Return imaginary part of complex number
    const T& imag() const;
    
/*        Setters         */
    
    //  Set real part
    void real(T r);
    //  Set imaginary part
    void imag(T i);
    
/*        Overloaded arithmetic operators        */
    
    // Assign another complex number to this one
    
    const complex<T, U>& operator=(const complex<T, U> other);
    // Return new complex value @a x plus @a y
    complex<T, U> operator+(const complex<T, U>& other);
    //  Return new complex value @a x minus @a y
    complex<T, U> operator-(const complex<T, U>& other);
    //  Return new complex value @a x times @a y
    complex<T, U> operator*(const complex<T, U>& other);
    //  Return new complex value @a x divided by @a y
    complex<T, U> operator/(const complex<T, U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        return complex((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
    }
    // Add another complex number to this one
    complex<T, U>& operator+=(complex<T, U>& other) {
        _Re += other.real(), _Im += other.imag();
        return *this;
    }
    // Subtract another complex number from this one
    complex<T, U>& operator-=(const complex<T, U>& other) {
        _Re -= other.real(), _Im -= other.imag();
        return *this;
    }
    // Multiply this complex number by another
    complex<T, U>& operator*=(const complex<T, U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        _Re = a*c - b*d, _Im = b*c + a*d;
        return *this;
    }
    // Divide this complex number by another.
    complex<T, U>& operator/=(const complex<T, U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        _Re = (a*c + b*d)/(c*c + d*d), _Im = (b*c - a*d)/(c*c + d*d);
        return *this;
    }
    
    
/*        Overloaded arithmetics operators for complex numbers and scalars        */
    
    // Assign scalar number to this one
    const complex<T, U>& operator=(const U scalar) {
        _Re = scalar, _Im = 0;
        return *this;
    }
    // Return new complex value @a x plus scalar y
    complex<T, U> operator+(const U& scalar) {
        return complex(_Re + scalar, _Im);
    }
    // Return new complex value @a x minus scalar y
    complex<T, U> operator-(const U& scalar) {
        return complex(_Re - scalar, _Im);
    }
    // Return new complex value @a x multiplied by scalar y
    complex<T, U> operator*(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        return complex(a*c - b*d, b*c + a*d);
    }
    // Return new complex value @a x divided by scalar y
    complex<T, U> operator/(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        return complex((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
    }
    // Add scalar to this complex number
    complex<T, U>& operator+=(const U& scalar) {
        _Re += scalar;
        return *this;
    }
    // Substract scalar from this complex number
    complex<T, U>& operator-=(const U& scalar) {
        _Re -= scalar;
        return *this;
    }
    // Multiply this complex number by scalar
    complex<T, U>& operator*=(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        _Re = a*c - b*d, _Im = b*c + a*d;
        return *this;
    }
    // Divide this complex number by scalar
    complex<T, U>& operator/=(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        _Re = (a*c + b*d)/(c*c + d*d), _Im = (b*c - a*d)/(c*c + d*d);
        return *this;
    }
    
/*        Overloaded stream        */
    
    friend std::ostream & operator <<(std::ostream &out, complex<T, U>& complex) {
        if (complex.imag() == 0){
            out << complex.real() << std::endl;
        }
        else {
            out << complex.real() << " + " << complex.imag() << "i" << std::endl;
        }
        
        return out;
    }
    friend std::istream & operator >> (std::istream &in,  complex<T, U> &complex) {
        in >> complex._Re >> complex._Im;
        return in;
    }
    
/*        Overloaded bool operators        */
    
    //  Return true if @a x is equal to @a y
    bool operator==(const complex<T, U> other) const {
        return (_Re == other.real() && _Im == other.imag());
    }
    //  Return true if @a x is not equal to @a y
    bool operator!=(const complex<T, U> other) const {
        return (_Re != other.real() || _Im != other.imag());
    }
    //  Return true if @a x is greater or equal to @a y
    bool operator>=(const complex<T, U> other) const {
        double module1 = sqrt(_Re*_Re + _Im*_Im), module2 = sqrt(other.real()*other.real() + other.imag()*other.imag());
        return (module1 >= module2);
    }
    //  Return true if @a x is lesser or equal to @a y
    bool operator<=(const complex<T, U> other) const {
        double module1 = sqrt(_Re*_Re + _Im*_Im), module2 = sqrt(other.real()*other.real() + other.imag()*other.imag());
        return (module1 > module2);
    }
    //  Return true if @a x is greater than @a y
    bool operator>(const complex<T, U> other) const {
        double module1 = sqrt(_Re*_Re + _Im*_Im), module2 = sqrt(other.real()*other.real() + other.imag()*other.imag());
        return (module1 >= module2);
    }
    //  Return true if @a x is lesser than @a y
    bool operator<(const complex<T, U> other) const {
        double module1 = sqrt(_Re*_Re + _Im*_Im), module2 = sqrt(other.real()*other.real() + other.imag()*other.imag());
        return (module1 > module2);
    }
    
/*        Overloaded bool operators for complex numbers and scalars        */

    //  Return true if @a x is equal to scalar y
    bool operator==(const U scalar) const {
        return (_Re == scalar && _Im == 0);
    }
    //  Return true if @a x is not equal to scalar y
    bool operator!=(const U scalar) const {
        return (_Re != scalar || _Im != 0);
    }
    //  Return true if @a x is greater or equal to scalar y
    bool operator>=(const U scalar) const {
        double module = sqrt(_Re*_Re + _Im*_Im);
        return (module >= scalar);
    }
    //  Return true if @a x is lesser or equal to scalar y
    bool operator<=(const U scalar) const {
        double module = sqrt(_Re*_Re + _Im*_Im);
        return (module >= scalar);
    }
    //  Return true if @a x is greater than scalar y
    bool operator>(const U scalar) const {
        double module = sqrt(_Re*_Re + _Im*_Im);
        return (module > scalar);
    }
    //  Return true if @a x is lesser than scalar y
    bool operator<(const U scalar) const {
        double module = sqrt(_Re*_Re + _Im*_Im);
        return (module > scalar);
    }
        
};

template<typename T, typename U>
class Real: public complex<T, U>{
    
public:
    /*        Constructor         */
        
    //  Default
    Real() : complex<T, U>() { }
    //  Parametr
    Real(T r, T i = 0) : complex<T, U>(r, i) { }
    //  Copy || Convert
    Real(const complex<T, U>& complex){
        this->_Re = complex.real(), this->_Im = 0;
    }
/*        Overloaded arithmetic operators        */
        
    // Assign another complex number to this one
    const Real<T, U>& operator=(const complex<T, U> other) {
        this->_Re = other.real(), this->_Im = other.imag();
        return *this;
    }
    // Return new complex value @a x plus @a y
    Real<T, U> operator+(const complex<T, U>& other) {
        return Real(this->_Re + other.real(), this->_Im + other.imag());
    }
    //  Return new complex value @a x minus @a y

    Real<T, U> operator-(const complex<T, U>& other) {
        return Real(this->_Re - other.real(), this->_Im - other.imag());
    }
    //  Return new complex value @a x times @a y
    Real<T, U> operator*(const complex<T, U>& other) {
        T a = this->_Re, b = this->_Im, c = other.real(), d = other.imag();
        return Real(a*c - b*d, b*c + a*d);
    }
    //  Return new complex value @a x divided by @a y
    Real<T, U> operator/(const complex<T, U>& other) {
        T a = this->_Re, b = this->_Im, c = other.real(), d = other.imag();
        return Real((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
    }
    // Add another complex number to this one
    Real<T, U>& operator+=(complex<T, U>& other) {
        this->_Re += other.real(), this->_Im += other.imag();
        return *this;
    }
    // Subtract another complex number from this one
    Real<T, U>& operator-=(const complex<T, U>& other) {
        this->_Re -= other.real(), this->_Im -= other.imag();
        return *this;
    }
    // Multiply this complex number by another
    Real<T, U>& operator*=(const complex<T, U>& other) {
        T a = this->_Re, b = this->_Im, c = other.real(), d = other.imag();
        this->_Re = a*c - b*d, this->_Im = b*c + a*d;
        return *this;
    }
    // Divide this complex number by another.
    Real<T, U>& operator/=(const complex<T, U>& other) {
        T a = this->_Re, b = this->_Im, c = other.real(), d = other.imag();
        this->_Re = (a*c + b*d)/(c*c + d*d), this->_Im = (b*c - a*d)/(c*c + d*d);
        return *this;
    }
        
    
    
};

#endif /* Complex_hpp */

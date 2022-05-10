//
//  Complex.hpp
//  Complex
//
//  Created by Nastya Bekesheva on 03.05.2022.
//

#pragma once
#ifndef Complex_hpp
#define Complex_hpp

template<typename T>
class complex {
    
private:
    T _Re;
    T _Im;
    
public:
    
/*        Constructor         */
    
    //  Default
    complex() { }
    //  Parametr
    complex(T r, T i){
        _Re = r, _Im = i;
    }
    //  Copy || Convert
    complex(const T& complex){
        _Re = complex.real(), _Im = complex.imag();
    }
    
/*        Getters         */
    
    //  Return real part of complex number
    T& real() {
        return _Re;
    }
    //  Return real part of complex number
    const T& real() const {
        return _Re;
    }
    //  Return imaginary part of complex number
    T& imag() {
        return _Im;
    }
    //  Return imaginary part of complex number
    const T& imag() const {
        return _Im;
    }
    
/*        Setters         */
    
    //  Set real part
    void real(T r) {
        _Re = r;
    }
    //  Set imaginary part
    void imag(T i) {
        _Im = i;
    }
    
/*        Overloaded arithmetic operators        */
    
    // Assign another complex number to this one
    template<typename U>
    const complex<T>& operator=(const complex<U> other) {
        _Re = other.real(), _Im = other.imag();
        return *this;
    }
    // Return new complex value @a x plus @a y
    template<typename U>
    complex<T> operator+(const complex<U>& other) {
        return complex(_Re + other.real(), _Im + other.imag());
    }
    //  Return new complex value @a x minus @a y
    template<typename U>
    complex<T> operator-(const complex<U>& other) {
        return complex(_Re - other.real(), _Im - other.imag());
    }
    //  Return new complex value @a x times @a y
    template<typename U>
    complex<T> operator*(const complex<U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        return complex(a*c - b*d, b*c + a*d);
    }
    //  Return new complex value @a x divided by @a y
    template<typename U>
    complex<T> operator/(const complex<U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        return complex((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
    }
    // Add another complex number to this one
    template<typename U>
    complex<T>& operator+=(complex<U>& other) {
        _Re += other.real(), _Im += other.imag();
        return *this;
    }
    // Subtract another complex number from this one
    template<typename U>
    complex<T>& operator-=(const complex<U>& other) {
        _Re -= other.real(), _Im -= other.imag();
        return *this;
    }
    // Multiply this complex number by another
    template<typename U>
    complex<T>& operator*=(const complex<U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        _Re = a*c - b*d, _Im = b*c + a*d;
        return *this;
    }
    // Divide this complex number by another.
    template<typename U>
    complex<T>& operator/=(const complex<U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        _Re = (a*c + b*d)/(c*c + d*d), _Im = (b*c - a*d)/(c*c + d*d);
        return *this;
    }
    
/*        Overloaded arithmetics operators for complex numbers and scalars        */
    
    // Assign scalar number to this one
    template<typename U>
    const complex<T>& operator=(const U scalar) {
        _Re = scalar, _Im = 0;
        return *this;
    }
    // Return new complex value @a x plus scalar y
    template<typename U>
    complex<T> operator+(const U& scalar) {
        return complex(_Re + scalar, _Im);
    }
    // Return new complex value @a x minus scalar y
    template<typename U>
    complex<T> operator-(const U& scalar) {
        return complex(_Re - scalar, _Im);
    }
    // Return new complex value @a x multiplied by scalar y
    template<typename U>
    complex<T> operator*(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        return complex(a*c - b*d, b*c + a*d);
    }
    // Return new complex value @a x divided by scalar y
    template<typename U>
    complex<T> operator/(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        return complex((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
    }
    // Add scalar to this complex number
    template<typename U>
    complex<T>& operator+=(const U& scalar) {
        _Re += scalar;
        return *this;
    }
    // Substract scalar from this complex number
    template<typename U>
    complex<T>& operator-=(const U& scalar) {
        _Re -= scalar;
        return *this;
    }
    // Multiply this complex number by scalar
    template<typename U>
    complex<T>& operator*=(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        _Re = a*c - b*d, _Im = b*c + a*d;
        return *this;
    };=
    // Divide this complex number by scalar
    template<typename U>
    complex<T>& operator/=(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        _Re = (a*c + b*d)/(c*c + d*d), _Im = (b*c - a*d)/(c*c + d*d);
        return *this;
    }
    
/*        Overloaded stream        */
    
    friend std::ostream & operator <<(std::ostream &out, complex<T>& complex) {
        out << complex.real() << " + " << complex.imag() << "i" << std::endl;
        return out;
    }
    friend std::istream & operator >> (std::istream &in,  complex<T> &complex) {
        in >> complex._Re >> complex._Im;
        return in;
    }
    
/*        Overloaded bool operators        */
    
    //  Return true if @a x is equal to @a y
    template<typename U>
    bool operator==(const complex<U> other) const {
        return (_Re == other.real() && _Im == other.imag());
    }
    //  Return true if @a x is not equal to @a y
    template<typename U>
    bool operator!=(const complex<U> other) const {
        return (_Re != other.real() || _Im != other.imag());
    }
    //  Return true if @a x is greater or equal to @a y
    template<typename U>
    bool operator>=(const complex<U> other) const {
        double module1 = sqrt(_Re*_Re + _Im*_Im), module2 = sqrt(other.real()*other.real() + other.imag()*other.imag());
        return (module1 >= module2);
    }
    //  Return true if @a x is lesser or equal to @a y
    template<typename U>
    bool operator<=(const complex<U> other) const {
        double module1 = sqrt(_Re*_Re + _Im*_Im), module2 = sqrt(other.real()*other.real() + other.imag()*other.imag());
        return (module1 > module2);
    }
    //  Return true if @a x is greater than @a y
    template<typename U>
    bool operator>(const complex<U> other) const {
        double module1 = sqrt(_Re*_Re + _Im*_Im), module2 = sqrt(other.real()*other.real() + other.imag()*other.imag());
        return (module1 >= module2);
    }
    //  Return true if @a x is lesser than @a y
    template<typename U>
    bool operator<(const complex<U> other) const {
        double module1 = sqrt(_Re*_Re + _Im*_Im), module2 = sqrt(other.real()*other.real() + other.imag()*other.imag());
        return (module1 > module2);
    }
    
/*        Overloaded bool operators for complex numbers and scalars        */

    //  Return true if @a x is equal to scalar y
    template<typename U>
    bool operator==(const U scalar) const {
        return (_Re == scalar && _Im == 0);
    }
    //  Return true if @a x is not equal to scalar y
    template<typename U>
    bool operator!=(const U scalar) const {
        return (_Re != scalar || _Im != 0);
    }
    //  Return true if @a x is greater or equal to scalar y
    template<typename U>
    bool operator>=(const U scalar) const {
        double module = sqrt(_Re*_Re + _Im*_Im);
        return (module >= scalar);
    }
    //  Return true if @a x is lesser or equal to scalar y
    template<typename U>
    bool operator<=(const U scalar) const {
        double module = sqrt(_Re*_Re + _Im*_Im);
        return (module >= scalar);
    }
    //  Return true if @a x is greater than scalar y
    template<typename U>
    bool operator>(const U scalar) const {
        double module = sqrt(_Re*_Re + _Im*_Im);
        return (module > scalar);
    }
    //  Return true if @a x is lesser than scalar y
    template<typename U>
    bool operator<(const U scalar) const {
        double module = sqrt(_Re*_Re + _Im*_Im);
        return (module > scalar);
    }
        
};


#endif /* Complex_hpp */

//
//  Complex.hpp
//  Complex
//
//  Created by Nastya Bekesheva on 03.05.2022.
//

#ifndef Complex_hpp
#define Complex_hpp

template<typename T>
struct complex {
    
private:
    T _Re;
    T _Im;
    
public:
    
/*        Constructor         */
    
    complex() { };
    complex(T r, T i){
        _Re = r, _Im = i;
    };
    complex(const T& complex){
        _Re = complex.real(), _Im = complex.imag();
    };
    
/*        Getters         */
    
    T& real() {
        return _Re;
    };
    const T& real() const {
        return _Re;
    };
    T& imag() {
        return _Im;
    };
    const T& imag() const {
        return _Im;
    };
    
/*        Setters         */
    
    void real(T r) {
        _Re = r;
    };
    void imag(T i) {
        _Im = i;
    };
    
/*        Overloaded operators for complex numbers arithmetics        */
    
    template<typename U>
    const complex<T>& operator=(const complex<U> other) {
        _Re = other.real(), _Im = other.imag();
        return *this;
    };
    template<typename U>
    complex<T> operator+(const complex<U>& other) {
        return complex(_Re + other.real(), _Im + other.imag());
    };
    template<typename U>
    complex<T> operator-(const complex<U>& other) {
        return complex(_Re - other.real(), _Im - other.imag());
    };
    template<typename U>
    complex<T> operator*(const complex<U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        return complex(a*c - b*d, b*c + a*d);
    };
    template<typename U>
    complex<T> operator/(const complex<U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        return complex((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
    };
    template<typename U>
    complex<T>& operator+=(complex<U>& other) {
        _Re += other.real(), _Im += other.imag();
        return *this;
    };
    template<typename U>
    complex<T>& operator-=(const complex<U>& other) {
        _Re -= other.real(), _Im -= other.imag();
        return *this;
    };
    template<typename U>
    complex<T>& operator*=(const complex<U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        _Re = a*c - b*d, _Im = b*c + a*d;
        return *this;
    };
    template<typename U>
    complex<T>& operator/=(const complex<U>& other) {
        T a = _Re, b = _Im, c = other.real(), d = other.imag();
        _Re = (a*c + b*d)/(c*c + d*d), _Im = (b*c - a*d)/(c*c + d*d);
        return *this;
    };
    
/*        Overloaded operators for complex numbers and scalars arithmetics        */
    
    template<typename U>
    const complex<T>& operator=(const U scalar) {
        _Re = scalar, _Im = 0;
        return *this;
    };
    template<typename U>
    complex<T> operator+(const U& scalar) {
        return complex(_Re + scalar, _Im);
    };
    template<typename U>
    complex<T> operator-(const U& scalar) {
        return complex(_Re - scalar, _Im);
    };
    template<typename U>
    complex<T> operator*(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        return complex(a*c - b*d, b*c + a*d);
    };
    template<typename U>
    complex<T> operator/(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        return complex((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
    };
    template<typename U>
    complex<T>& operator+=(const U& scalar) {
        _Re += scalar;
        return *this;
    };
    template<typename U>
    complex<T>& operator-=(const U& scalar) {
        _Re -= scalar;
        return *this;
    };
    template<typename U>
    complex<T>& operator*=(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        _Re = a*c - b*d, _Im = b*c + a*d;
        return *this;
    };
    template<typename U>
    complex<T>& operator/=(const U& scalar) {
        T a = _Re, b = _Im, c = scalar, d = 0;
        _Re = (a*c + b*d)/(c*c + d*d), _Im = (b*c - a*d)/(c*c + d*d);
        return *this;
    };
    
/*        Overloaded stream        */
    
    friend std::ostream & operator <<(std::ostream &out, complex<T>& complex) {
        out << complex.real() << " + " << complex.imag() << "i" << std::endl;
        return out;
    };
    friend std::istream & operator >> (std::istream &in,  complex<T> &complex) {
        in >> complex._Re >> complex._Im;
        return in;
    };
        
};

#endif /* Complex_hpp */

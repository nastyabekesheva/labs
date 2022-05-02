//
//  main.cpp
//  Set
//
//  Created by Nastya Bekesheva on 02.05.2022.
//

#include <iostream>

template<typename T>
class Set{
private:
    T *_data;
    
public:
    Set() {};
    Set(T data){
        this->_data = &data;
    }
    Set(const Set<T> &data){
        this->_data = data._data;
    }
    
    void display(){
        std::cout << _data[0] << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Set<int> n(5);
    Set<int> m(n);
    m.display();
    return 0;
}

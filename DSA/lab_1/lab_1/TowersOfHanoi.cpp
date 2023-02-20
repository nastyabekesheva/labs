//
//  TowersOfHanoi.cpp
//  lab_1
//
//  Created by Nastya Bekesheva on 07.02.2023.
//

#include <stdio.h>
#include <vector>
#include <unistd.h>

int steps = 0;

class Disk{
private:
    int _size;
public:
    Disk(int n);
    int sizeOf();
};

class Tower{
private:
    std::string _name;
public:
    std::vector<Disk> _disks;
    Tower(std::string name, std::vector<Disk> disks);
    Tower() = default;
    void printTower(); // visualization
};

class TowersOfHanoi{
private:
    int _n;
public:
    Tower _towers[3];
    TowersOfHanoi(int n);
    void start(); // trigers algorithm
    void moveOne(Tower * start, Tower * end); // move top disk from one tower to another
    void move(Tower * start, Tower * end, Tower * help, int n); // recursive algorithm
};

Disk::Disk(int n){
    this->_size = n;
}

int Disk::sizeOf(){
    return this->_size;
}

Tower::Tower(std::string name, std::vector<Disk> disks){
    this->_name = name;
    this->_disks = disks;
}

void Tower::printTower(){
    std::cout<< "-----------step " << steps << "-----------" << std::endl;
    std::cout << this->_name << ":" << std::endl;
    std::vector<Disk> copy_disks = _disks;
    std::reverse(copy_disks.begin(), copy_disks.end());
    for (Disk i: copy_disks){
        std::string s = "";
        for (int j = 0; j < i.sizeOf(); j++){
            s += std::to_string(i.sizeOf());
        }
        std::cout << " | \n " << s << " " << std::endl;
    }
    std::cout << "_|_" << std::endl;
    std::cout<< "-----------step " << steps << "-----------" << std::endl;
}

TowersOfHanoi::TowersOfHanoi(int n){
    this->_n = n;
    std::vector<Disk> disksA;
    for (int i = n; i > 0; i--){
        disksA.push_back(Disk(i)); // create vector of disks of size i
    }
    Tower towers[3] = {{"A", disksA}, {"B", {}}, {"C", {}}}; // initialize towers: A has all disks, others are empty
    for (int i = 0; i < 3; i++){
        this->_towers[i] = towers[i]; // push towers
    }
}
void TowersOfHanoi::start(){
    steps = 0;
    move(& _towers[0], & _towers[1], & _towers[2], _n); // we need to move all disks from A to C
}

void TowersOfHanoi::moveOne(Tower * start, Tower * end){
    steps++;
    end->_disks.push_back(start->_disks[start->_disks.size()-1]); // add disk to tower
    start->_disks.pop_back(); // remove first disk from tower
    for (int i = 0; i < 3; i++){
        this->_towers[i].printTower();
    }
    std::cout << std::endl;
    sleep(2); // wait for 2 seconds befor doing anything
}

void TowersOfHanoi::move(Tower * start, Tower * help, Tower * end, int n){
    if (n > 0) {
        if (n == 1){
            moveOne(start, end); // A->C
            return;
        }
        move(start, end, help, n-1); // n-1'th disk: A -> B
        moveOne(start, end); // n'th disk: A->C
        move(help, start, end, n-1);// n-1'th disk: B->C
    }
}




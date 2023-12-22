#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>    
#include <ctime>  


class Human {
private:

protected:
    string name;
    string surname;
    int age;
    string email;
    int phone;
public:
    Human() : name(""), surname(""), age(0), email(""), phone(0) {}
    //вiртуальна функцiя
    virtual void TouristType() = 0;
};

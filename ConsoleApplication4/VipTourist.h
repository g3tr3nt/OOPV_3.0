#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>  
#include <cstdlib>    
#include <ctime>  


#include "Tourist.h"

class VipTourist :public virtual Tourist {
private:
    string vipService;

public:
    VipTourist operator+(const int& ageToAdd) {
        VipTourist result = *this;
        result.setAge(this->getAge() + ageToAdd);
        return result;
    }

    // Перевантаження оператора віднімання "-"
    VipTourist operator-(const int& ageToSubtract) {
        VipTourist result = *this;
        result.setAge(this->getAge() - ageToSubtract);
        return result;
    }

    VipTourist operator*(const int& multiplier) {
        VipTourist result = *this;
        result.setAge(this->getAge() * multiplier);
        return result;
    }
    // Перевантаження оператора "+="
    VipTourist& operator+=(const int& valueToAdd) {
        this->setAge(this->getAge() + valueToAdd);
        return *this;
    }
    //вiртуальний деструктор
    ~VipTourist() {

        cout << "VIP tourist named " << name << " is leaving." << endl;
    }

    //вiртуальна функцiя
    void TouristType(){
        std::cout << "Its VIP tourist named " << name << endl;
    }


    VipTourist() : Tourist(), vipService("") {  }

    void setVipService(string service) {
        vipService = service;
    }

    string getVipService() {
        return vipService;
    }
};


void calculate(VipTourist& Viptourist) {
    float dailyCost = Viptourist.getPhone() / Viptourist.getAge();
    std::cout << "Результат дiлення номеру телефона на вiк: " << dailyCost << std::endl;
}
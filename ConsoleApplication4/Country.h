#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>  
#include <cstdlib>    
#include <ctime>  



using namespace std;

template <typename T>
class Country {
private:
    T name;
    T hotel;

public:
    Country() : name(T()), hotel(T()) {}

    void setCountryName(T name) { this->name = name; }
    void setHotel(T hotel) { this->hotel = hotel; }

    T getCountryName() { return name; }
    T getHotel() { return hotel; }
};







//class EliteTourist : public virtual Tourist, public VipTourist {
//private:
//    string superVipService;
//
//public:
//
//    EliteTourist() : Tourist(), VipTourist(), superVipService("") {}
//
//    // Деструктор
//    ~EliteTourist() {
//        cout << "Super VIP tourist named " << name << " is leaving." << endl;
//    }
//
//    // Віртуальна функція
//    void TouristType() const override {
//        cout << "It's Elite tourist named " << name << endl;
//    }
//
//    void setSuperVipService(string service) {
//        superVipService = service;
//    }
//
//    string getSuperVipService() {
//        return superVipService;
//    }
//};













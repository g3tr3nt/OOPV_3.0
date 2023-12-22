#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>  
#include <cstdlib>    
#include <ctime> 

#include "Country.h"

class Trip {

private:



    string country;
    int duration;
    double price;
    string hotel;
    string transport;
    int tripNum;
    //Country* countryPointer;
public:

    void incrementDuration() {
        duration++;
    }

    void decrementDuration() {
        if (duration > 0) {
            duration--;
        }
    }

    Trip(const string& country = "", const int& duration = 0, double price = 0.0, const string& hotel = "", const string& transport = "")
        : country(country), duration(duration), price(price), hotel(hotel), transport(transport) {}


    void setCountry(string country) { this->country = country; }
    void setDuration(int duration) { this->duration = duration; }
    void setPrice(double price) { this->price = price; }
    void setTransport(string transport) { this->transport = transport; }
    void setTripNum(int tripNum) { this->tripNum = tripNum; }

    string getTransport() { return transport; }
    string getCountry() { return country; }
    int getDuration() { return duration; }
    double getPrice() { return price; }
    int getTripNum() { return tripNum; }
    Trip(const Trip& other)
        : country(other.country), duration(other.duration), price(other.price), hotel(other.hotel), transport(other.transport) {}

};

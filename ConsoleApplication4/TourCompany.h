#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>  
#include <cstdlib>    
#include <ctime>  
#include <deque>

#include "Trip.h"

class TourCompany {
private:
    deque<Trip> trips;
    string name;
    string email;
    int phone;
public:

    void displayTrips(){
        for_each(trips.begin(), trips.end(), [](Trip& trip) {
            std::cout << "Місце призначення: " << trip.getCountry() << ", Тривалість: " << trip.getDuration() << " днів" << std::endl;
            });
    }

    void Read(std::ifstream& file) {
        if (!file.is_open()) {
            throw std::runtime_error("Помилка вiдкриття файлу для читання");
        }
        // Читання даних з файлу та їх збереження в полях класу
        cout << name << endl << email << endl << phone << endl;
    }

    void Write(std::ofstream& file) {
        if (!file.is_open()) {
            throw std::runtime_error("Помилка вiдкриття файлу для запису");
        }
        // Запис даних з полiв класу у файл
        file << name << endl << email << endl << phone << endl;
    }

    void setName(string name) { this->name = name; }
    void setPhone(int phone) { this->phone = phone; }
    void setEmail(string email) { this->email = email; }

    string getEmail() { return email; }
    string getName() { return name; }
    int getPhone() { return phone; }

    //агрегацiя
    void addTrip(const Trip& trip) { trips.push_back(trip); } // додати путiвку
    Trip getTrip(int index) { return trips[index]; } // отримати путiвку
    int getTripsCount() { return trips.size(); } // отримати кiлькiсть путiвок

};

//Оголосити функцiю типу описаного класу, яка повертатиме об’єкт класу. Функцiя оперує з методами,
//наявними в класi.
TourCompany createCompany(const string& name, const string& email, int phone) {
    TourCompany myCompany;
    myCompany.setName(name);
    myCompany.setEmail(email);
    myCompany.setPhone(phone);
    return myCompany;
}

void Service(const std::string& filename, TourCompany& obj) {
    try {
        // Вiдкриття файлу для читання та запису
        std::ifstream input_file(filename);
        

        // Читання та запис даних
        obj.Read(input_file);

        // Закриття файлiв
        input_file.close();

        std::ofstream output_file(filename, std::ios::app); // Якщо файл не iснує, створюємо його

        obj.Write(output_file);

        output_file.close();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Виникла помилка: " << e.what() << std::endl;
    }
    // Обробка iнших виняткiв
    catch (const std::exception& e) {
        std::cout << "Виникла невiдома помилка: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Виникла невiдома помилка." << std::endl;
    }
}

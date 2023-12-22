#include "Tourist.h"
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
void WritePricesToFile(const std::list<int>& prices) {
    // Відкриття файлу для запису
   ofstream file("Ціни.txt");
    if (file.is_open()) {
        // Запис кожного елементу списку у файл
        for (const int& price : prices) {
            file << price << std::endl;
        }

        // Закриття файлу
        file.close();
       
    }

}
vector<Tourist*> tourists;
Tourist* tourist = new Tourist();
void setCommonTourists(TourCompany& myCompany) {


    static int prices[6] = { 2500, 2000, 1500, 4000, 3500, 3000 };

    list<int> pricesList(prices, prices + sizeof(prices) / sizeof(prices[0]));

    WritePricesToFile(pricesList);

    plus<int> addition;
    addition(prices[3], prices[5]);

    multiplies<int> multiplication;
    multiplication(prices[1], 2);

    divides<int> division;
    division(prices[1], 2);

    greater<int> greater_than;
    greater_than(prices[2], prices[5]);

    less<int> less_than;
    less_than(prices[5], prices[6]);

    int Summary = accumulate(pricesList.begin(), pricesList.end(), 0);

    reverse(pricesList.begin(), pricesList.end());

    int target = 2000;
    int check = count(pricesList.begin(), pricesList.end(), target);

    cout << check;

    pricesList.sort();
    try {
        //запис у файл
        ofstream Tourists("Tourists.txt", ios::app);

        if (!Tourists) {
            throw std::runtime_error("Помилка вiдкриття файлу VipTourists.txt");
        }


        if (!tourist) {
            throw std::bad_alloc();
        }
        string name;
        string surname;
        string email;
        string country;
        string Transport;
        int duration;
        int phone;
        int age;
        std::cout << "Введiть iм'я: ";
        std::cin >> name;
        tourist->setName(name);
        Tourists << "iм'я " << name << endl;

        std::cout << "Введiть прiзвище: ";
        std::cin >> surname;
        tourist->setSurname(surname);
        Tourists << "Прiзвище " << surname << endl;

        std::cout << "Введiть вiк: ";
        std::cin >> age;
        tourist->setAge(age);
        Tourists << "Вiк " << age << endl;

        std::cout << "Введiть email: ";
        std::cin >> email;
        tourist->setEmail(email);
        Tourists << "Email " << email << endl;

        std::cout << "Введiть мобiльний номер телефону: ";
        std::cin >> phone;
        tourist->setPhone(phone);
        Tourists << "Мобiльний номер телефону " << phone << endl;

        std::cout << "Введiть країну для подорожi: ";
        std::cin >> country;
        tourist->myCountry.setCountryName(country);
        Tourists << "Країна " << country << endl;

        std::cout << "Введiть термiн подорожi: ";
        std::cin >> duration;
        tourist->myTrip.setDuration(duration);
        Tourists << "Термiн подорожi " << duration << endl;

        std::cout << "Введiть транспорт для подорожi: ";
        std::cin >> Transport;
        tourist->myTrip.setTransport(Transport);
        Tourists << "Транспорт " << Transport << endl;

        string hotel;
        std::cout << "Введiть тип готелю для вашої подорожi: ";
        std::cin >> hotel;
        tourist->myCountry.setHotel(hotel);
        Tourists << "Тип готелю " << hotel << endl;

        double price;
        std::cout << "Виберiть цiну подорожi ";
        for_each(pricesList.begin(), pricesList.end(), [](int price) {
            std::cout << price << " ";
            });
        cout << std::endl;
        std::cin >> price;

       

        bool validPrice = false;
        for (int i = 0; i < 5; i++) {
            if (price == prices[i]) {
                
                validPrice = true;
                break;
            }
        }

        if (!validPrice) {
            throw std::invalid_argument("Цiна повинна бути однiєю з наступних: 1500, 2000, 2500, 3000, 3500");
        }


        tourist->myTrip.setPrice(price);
        Tourists << "Цiна " << price << endl;



        calculate(*tourist);

        int ticket = rand() % 10000 + 1; // Генеруємо номер квитка в дiапазонi вiд 1 до 10000
        tourist->myTrip.setTripNum(ticket);
        Tourists << "Номер квитка " << ticket << endl;
        std::cout << "Номер вашого квитка: " << ticket << '\n';

        tourist->print("Туриста записано!");

        Tourists << "================================" << endl;

        Trip newTrip(country, duration, price, hotel, Transport);
        myCompany.addTrip(newTrip); // Додаємо путiвку до компанiї

        std::cout << "Ви обрали звичайну подорож. Ваш готель: " << tourist->myCountry.getHotel() << ". Цiна подорожi: " << tourist->myTrip.getPrice() << endl;
        tourists.push_back(tourist);
        Tourists.close();

    }
    catch (std::runtime_error& e) {
        std::cout << "Виникла помилка: " << e.what() << std::endl;
    }

    catch (std::bad_alloc& e) {
        std::cout << "Виникла помилка при видiленнi пам'ятi: " << e.what() << std::endl;
    }

    catch (std::invalid_argument& e) {
        std::cout << "Помилка введення цiни: " << e.what() << std::endl;
    }
}

void ShowTourist() {
    for (Tourist* tourist : tourists) {
        std::cout << "Туристи:\n";
        std::cout << "Iм'я: " + tourist->getName() << "\n";
        std::cout << "Прiзвище: " << tourist->getSurname() << "\n";
        std::cout << "Вiк: " << tourist->getAge() << "\n";
        std::cout << "Email: " << tourist->getEmail() << "\n";
        std::cout << "Телефон: " << tourist->getPhone() << "\n";
        std::cout << "Готель: " << tourist->myCountry.getHotel() << "\n";
        std::cout << "Цiна подорожi: " << tourist->myTrip.getPrice() << "\n";
        std::cout << "Країна: " << tourist->myCountry.getCountryName() << endl;
        std::cout << "Термiн подорожi: " << tourist->myTrip.getDuration() << endl;
        std::cout << "Транспорт: " << tourist->myTrip.getTransport() << endl;
        std::cout << "Номер квитка: " << tourist->myTrip.getTripNum() << endl;



        ////Human* refTourist;
        ////refTourist = tourist;
        ////refTourist->TouristType();

        //Human* refTourist;
        //Tourist CommonTourist;
        //VipTourist VIPtourist;


        ////Human* refTourist = &VIPtourist;
        ////tourist->TouristType();

        //refTourist = (Human*)&CommonTourist;
        //refTourist->TouristType();
        //

       




        std::cout << "================================" << endl;
    }
}
void showTouristFromFile() {
    string line;
    string a;

    ifstream Tourists("Tourists.txt");
    if (Tourists.is_open()) {
        cout << "Туристи: " << endl;
        while (getline(Tourists, line)) {
            cout << line << '\n' << "\n";
        }
        Tourists.close();
    }
}
void PlusPrefixOp() {
    ++(*tourist);
    std::cout << "Префiксне збільшення: " << tourist->myTrip.getDuration() << std::endl;
}
void PlusPostfixOp() {
    (*tourist)++;
    std::cout << "Постфiксне збільшення: " << tourist->myTrip.getDuration() << std::endl;
}
void MinusPrefixOp() {
    --(*tourist);
    std::cout << "Префiксне зменшення: " << tourist->myTrip.getDuration() << std::endl;
}
void MinusPostfixOp() {
    (*tourist)--;
    std::cout << "Постфіксне зменшення: " << tourist->myTrip.getDuration() << std::endl;
}
void deleteTourist() {
    int tripNumber;
    std::cout << "Введiть номер путiвки для видалення туриста: ";
    std::cin >> tripNumber;


    bool touristDeleted = false;
    for (auto it = tourists.begin(); it != tourists.end(); ++it) {
        if ((*it)->myTrip.getTripNum() == tripNumber) {
            delete* it; // Видаляємо об'єкт з пам'ятi
            tourists.erase(it); // Видаляємо вказiвник з вектора
            std::cout << "Турист з номером путiвки " << tripNumber << " успiшно видалений." << std::endl;
            touristDeleted = true;
            break;
        }
    }
    if (!touristDeleted) {
        std::cout << "Туриста з номером путiвки " << tripNumber << " не знайдено у списку." << std::endl;
    }
}
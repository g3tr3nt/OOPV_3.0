#include "VipTourist.h"

vector<Tourist*> Viptourists;
VipTourist* vipTourist = new VipTourist();
void setVIPTourists(TourCompany& myCompany) {
    try {
        //запис у файл
        ofstream vipTourists("VipTourists.txt", ios::app);


        if (!vipTourists) {
            throw std::runtime_error("Помилка вiдкриття файлу VipTourists.txt");
        }
        

        if (!vipTourist) {
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
        string hotel;
        int price = 0;
        std::cout << "Введiть iм'я: ";
        std::cin >> name;
        vipTourist->setName(name);
        vipTourists << "iм'я " << name << endl;

        std::cout << "Введiть прiзвище: ";
        std::cin >> surname;
        vipTourist->setSurname(surname);
        vipTourists << "Прiзвище " << surname << endl;

        std::cout << "Введiть вiк: ";
        std::cin >> age;
        vipTourist->setAge(age);
        vipTourists << "Вiк " << age << endl;

        std::cout << "Введiть email: ";
        std::cin >> email;
        vipTourist->setEmail(email);
        vipTourists << "email " << email << endl;

        std::cout << "Введiть мобiльний номер телефону: ";
        std::cin >> phone;
        vipTourist->setPhone(phone);
        vipTourists << "Мобiльний номер телефону " << phone << endl;

        std::cout << "Введiть країну для подорожi: ";
        std::cin >> country;
        vipTourist->myCountry.setCountryName(country);
        vipTourists << "Країна " << country << endl;

        std::cout << "Введiть термiн подорожi: ";
        std::cin >> duration;
        vipTourist->myTrip.setDuration(duration);
        vipTourists << "Термiн подорожi " << duration << endl;

        std::cout << "Введiть транспорт для подорожi: ";
        std::cin >> Transport;
        vipTourist->myTrip.setTransport(Transport);
        vipTourists << "Транспорт " << Transport << endl;


        Trip newTrip(country, duration, price, hotel, Transport);
        myCompany.addTrip(newTrip); // Додаємо путiвку до компанiї

        int ticket = rand() % 10000 + 1; // Генеруємо номер квитка в дiапазонi вiд 1 до 10000
        vipTourist->myTrip.setTripNum(ticket);
        std::cout << "Номер вашого квитка: " << ticket << '\n';
        vipTourists << "Номер квитка " << ticket << endl;

        vipTourist->setVipService("Премiум обслуговування");
        std::cout << "Ви обрали вiп подорож, вас обслуговуюють за схемою " << vipTourist->getVipService() << endl;
        Viptourists.push_back(vipTourist);
        vipTourists << "================================" << endl;
        vipTourists.close();
        calculate(*vipTourist);

    }
    catch (std::runtime_error& e) {
        std::cout << "Виникла помилка: " << e.what() << std::endl;
    }

    catch (std::bad_alloc& e) {
        std::cout << "Виникла помилка при видiленнi пам'ятi: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Виникла невiдома помилка." << std::endl;
    }
}

void show_VipTourists(){
    for (Tourist* vipTourist : Viptourists) {
        std::cout << "Вiп туристи:\n";

        std::cout << "Iм'я: " << vipTourist->getName() << "\n";
        std::cout << "Прiзвище: " << vipTourist->getSurname() << "\n";
        std::cout << "Вiк: " << vipTourist->getAge() << "\n";
        std::cout << "Email: " << vipTourist->getEmail() << "\n";
        std::cout << "Телефон: " << vipTourist->getPhone() << "\n";
        std::cout << "Країна: " << vipTourist->myCountry.getCountryName() << endl;
        std::cout << "Термiн подорожi: " << vipTourist->myTrip.getDuration() << endl;
        std::cout << "Транспорт: " << vipTourist->myTrip.getTransport() << endl;
        std::cout << "Номер квитка: " << vipTourist->myTrip.getTripNum() << endl;

        // використання вiртуального методу через вказiвник
        vipTourist->TouristType();



        Human* person;
        VipTourist tourist;
        person = &tourist;
        person->TouristType();







        person = new VipTourist;
        person->TouristType();
        delete person;

        person = new Tourist();
        person->TouristType();
        delete person;

       




        std::cout << "================================" << endl;
    }
}
void showVipTouristFromFile() {

    string line;
    string a;
    //читання з файлу
    ifstream vipTourists("VipTourists.txt");
    if (vipTourists.is_open()) {
        cout << "Вiп туристи: " << endl;
        while (getline(vipTourists, line)) {
            cout << line << '\n' << '\n';
        }
    }
}

void BinarPlus() {
    *vipTourist = *vipTourist + 10;
    cout << "Новий вік туриста " << vipTourist->getAge() << endl;
}
void BinarMinus() {
    *vipTourist = *vipTourist - 10;
    cout << "Новий вік туриста " << vipTourist->getAge() << endl;
}
void Multiply() {
    *vipTourist = *vipTourist * 2;
    cout << "Новий вік туриста " << vipTourist->getAge() << endl;
}
void PlusEqual() {
    *vipTourist += 5;
    cout << "Новий вік туриста " << vipTourist->getAge() << endl;
}
void deleteVipTourist() {
    int tripNumber;
    std::cout << "Введiть номер путiвки для видалення туриста: ";
    std::cin >> tripNumber;

    bool touristDeleted = false;
    for (auto it = Viptourists.begin(); it != Viptourists.end(); ++it) {
        if ((*it)->myTrip.getTripNum() == tripNumber) {
            delete* it; // Видаляємо об'єкт з пам'ятi
            Viptourists.erase(it); // Видаляємо вказiвник з вектора
            std::cout << "Турист з номером путiвки " << tripNumber << " успiшно видалений." << std::endl;
            touristDeleted = true;
            break;
        }
    }
    if (!touristDeleted) {
        std::cout << "Туриста з номером путiвки " << tripNumber << " не знайдено у списку." << std::endl;
    }
}
#include "Tourist.h"
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
void WritePricesToFile(const std::list<int>& prices) {
    // ³������� ����� ��� ������
   ofstream file("ֳ��.txt");
    if (file.is_open()) {
        // ����� ������� �������� ������ � ����
        for (const int& price : prices) {
            file << price << std::endl;
        }

        // �������� �����
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
        //����� � ����
        ofstream Tourists("Tourists.txt", ios::app);

        if (!Tourists) {
            throw std::runtime_error("������� �i������� ����� VipTourists.txt");
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
        std::cout << "����i�� i�'�: ";
        std::cin >> name;
        tourist->setName(name);
        Tourists << "i�'� " << name << endl;

        std::cout << "����i�� ��i�����: ";
        std::cin >> surname;
        tourist->setSurname(surname);
        Tourists << "��i����� " << surname << endl;

        std::cout << "����i�� �i�: ";
        std::cin >> age;
        tourist->setAge(age);
        Tourists << "�i� " << age << endl;

        std::cout << "����i�� email: ";
        std::cin >> email;
        tourist->setEmail(email);
        Tourists << "Email " << email << endl;

        std::cout << "����i�� ���i����� ����� ��������: ";
        std::cin >> phone;
        tourist->setPhone(phone);
        Tourists << "���i����� ����� �������� " << phone << endl;

        std::cout << "����i�� ����� ��� �������i: ";
        std::cin >> country;
        tourist->myCountry.setCountryName(country);
        Tourists << "����� " << country << endl;

        std::cout << "����i�� ����i� �������i: ";
        std::cin >> duration;
        tourist->myTrip.setDuration(duration);
        Tourists << "����i� �������i " << duration << endl;

        std::cout << "����i�� ��������� ��� �������i: ";
        std::cin >> Transport;
        tourist->myTrip.setTransport(Transport);
        Tourists << "��������� " << Transport << endl;

        string hotel;
        std::cout << "����i�� ��� ������ ��� ���� �������i: ";
        std::cin >> hotel;
        tourist->myCountry.setHotel(hotel);
        Tourists << "��� ������ " << hotel << endl;

        double price;
        std::cout << "�����i�� �i�� �������i ";
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
            throw std::invalid_argument("�i�� ������� ���� ���i�� � ���������: 1500, 2000, 2500, 3000, 3500");
        }


        tourist->myTrip.setPrice(price);
        Tourists << "�i�� " << price << endl;



        calculate(*tourist);

        int ticket = rand() % 10000 + 1; // �������� ����� ������ � �i������i �i� 1 �� 10000
        tourist->myTrip.setTripNum(ticket);
        Tourists << "����� ������ " << ticket << endl;
        std::cout << "����� ������ ������: " << ticket << '\n';

        tourist->print("������� ��������!");

        Tourists << "================================" << endl;

        Trip newTrip(country, duration, price, hotel, Transport);
        myCompany.addTrip(newTrip); // ������ ���i��� �� ������i�

        std::cout << "�� ������ �������� �������. ��� ������: " << tourist->myCountry.getHotel() << ". �i�� �������i: " << tourist->myTrip.getPrice() << endl;
        tourists.push_back(tourist);
        Tourists.close();

    }
    catch (std::runtime_error& e) {
        std::cout << "������� �������: " << e.what() << std::endl;
    }

    catch (std::bad_alloc& e) {
        std::cout << "������� ������� ��� ���i����i ���'��i: " << e.what() << std::endl;
    }

    catch (std::invalid_argument& e) {
        std::cout << "������� �������� �i��: " << e.what() << std::endl;
    }
}

void ShowTourist() {
    for (Tourist* tourist : tourists) {
        std::cout << "�������:\n";
        std::cout << "I�'�: " + tourist->getName() << "\n";
        std::cout << "��i�����: " << tourist->getSurname() << "\n";
        std::cout << "�i�: " << tourist->getAge() << "\n";
        std::cout << "Email: " << tourist->getEmail() << "\n";
        std::cout << "�������: " << tourist->getPhone() << "\n";
        std::cout << "������: " << tourist->myCountry.getHotel() << "\n";
        std::cout << "�i�� �������i: " << tourist->myTrip.getPrice() << "\n";
        std::cout << "�����: " << tourist->myCountry.getCountryName() << endl;
        std::cout << "����i� �������i: " << tourist->myTrip.getDuration() << endl;
        std::cout << "���������: " << tourist->myTrip.getTransport() << endl;
        std::cout << "����� ������: " << tourist->myTrip.getTripNum() << endl;



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
        cout << "�������: " << endl;
        while (getline(Tourists, line)) {
            cout << line << '\n' << "\n";
        }
        Tourists.close();
    }
}
void PlusPrefixOp() {
    ++(*tourist);
    std::cout << "����i���� ���������: " << tourist->myTrip.getDuration() << std::endl;
}
void PlusPostfixOp() {
    (*tourist)++;
    std::cout << "�����i���� ���������: " << tourist->myTrip.getDuration() << std::endl;
}
void MinusPrefixOp() {
    --(*tourist);
    std::cout << "����i���� ���������: " << tourist->myTrip.getDuration() << std::endl;
}
void MinusPostfixOp() {
    (*tourist)--;
    std::cout << "���������� ���������: " << tourist->myTrip.getDuration() << std::endl;
}
void deleteTourist() {
    int tripNumber;
    std::cout << "����i�� ����� ���i��� ��� ��������� �������: ";
    std::cin >> tripNumber;


    bool touristDeleted = false;
    for (auto it = tourists.begin(); it != tourists.end(); ++it) {
        if ((*it)->myTrip.getTripNum() == tripNumber) {
            delete* it; // ��������� ��'��� � ���'��i
            tourists.erase(it); // ��������� ����i���� � �������
            std::cout << "������ � ������� ���i��� " << tripNumber << " ���i��� ���������." << std::endl;
            touristDeleted = true;
            break;
        }
    }
    if (!touristDeleted) {
        std::cout << "������� � ������� ���i��� " << tripNumber << " �� �������� � ������." << std::endl;
    }
}
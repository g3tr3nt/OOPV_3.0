#include "VipTourist.h"

vector<Tourist*> Viptourists;
VipTourist* vipTourist = new VipTourist();
void setVIPTourists(TourCompany& myCompany) {
    try {
        //����� � ����
        ofstream vipTourists("VipTourists.txt", ios::app);


        if (!vipTourists) {
            throw std::runtime_error("������� �i������� ����� VipTourists.txt");
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
        std::cout << "����i�� i�'�: ";
        std::cin >> name;
        vipTourist->setName(name);
        vipTourists << "i�'� " << name << endl;

        std::cout << "����i�� ��i�����: ";
        std::cin >> surname;
        vipTourist->setSurname(surname);
        vipTourists << "��i����� " << surname << endl;

        std::cout << "����i�� �i�: ";
        std::cin >> age;
        vipTourist->setAge(age);
        vipTourists << "�i� " << age << endl;

        std::cout << "����i�� email: ";
        std::cin >> email;
        vipTourist->setEmail(email);
        vipTourists << "email " << email << endl;

        std::cout << "����i�� ���i����� ����� ��������: ";
        std::cin >> phone;
        vipTourist->setPhone(phone);
        vipTourists << "���i����� ����� �������� " << phone << endl;

        std::cout << "����i�� ����� ��� �������i: ";
        std::cin >> country;
        vipTourist->myCountry.setCountryName(country);
        vipTourists << "����� " << country << endl;

        std::cout << "����i�� ����i� �������i: ";
        std::cin >> duration;
        vipTourist->myTrip.setDuration(duration);
        vipTourists << "����i� �������i " << duration << endl;

        std::cout << "����i�� ��������� ��� �������i: ";
        std::cin >> Transport;
        vipTourist->myTrip.setTransport(Transport);
        vipTourists << "��������� " << Transport << endl;


        Trip newTrip(country, duration, price, hotel, Transport);
        myCompany.addTrip(newTrip); // ������ ���i��� �� ������i�

        int ticket = rand() % 10000 + 1; // �������� ����� ������ � �i������i �i� 1 �� 10000
        vipTourist->myTrip.setTripNum(ticket);
        std::cout << "����� ������ ������: " << ticket << '\n';
        vipTourists << "����� ������ " << ticket << endl;

        vipTourist->setVipService("����i�� ��������������");
        std::cout << "�� ������ �i� �������, ��� ������������� �� ������ " << vipTourist->getVipService() << endl;
        Viptourists.push_back(vipTourist);
        vipTourists << "================================" << endl;
        vipTourists.close();
        calculate(*vipTourist);

    }
    catch (std::runtime_error& e) {
        std::cout << "������� �������: " << e.what() << std::endl;
    }

    catch (std::bad_alloc& e) {
        std::cout << "������� ������� ��� ���i����i ���'��i: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "������� ���i���� �������." << std::endl;
    }
}

void show_VipTourists(){
    for (Tourist* vipTourist : Viptourists) {
        std::cout << "�i� �������:\n";

        std::cout << "I�'�: " << vipTourist->getName() << "\n";
        std::cout << "��i�����: " << vipTourist->getSurname() << "\n";
        std::cout << "�i�: " << vipTourist->getAge() << "\n";
        std::cout << "Email: " << vipTourist->getEmail() << "\n";
        std::cout << "�������: " << vipTourist->getPhone() << "\n";
        std::cout << "�����: " << vipTourist->myCountry.getCountryName() << endl;
        std::cout << "����i� �������i: " << vipTourist->myTrip.getDuration() << endl;
        std::cout << "���������: " << vipTourist->myTrip.getTransport() << endl;
        std::cout << "����� ������: " << vipTourist->myTrip.getTripNum() << endl;

        // ������������ �i���������� ������ ����� ����i����
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
    //������� � �����
    ifstream vipTourists("VipTourists.txt");
    if (vipTourists.is_open()) {
        cout << "�i� �������: " << endl;
        while (getline(vipTourists, line)) {
            cout << line << '\n' << '\n';
        }
    }
}

void BinarPlus() {
    *vipTourist = *vipTourist + 10;
    cout << "����� �� ������� " << vipTourist->getAge() << endl;
}
void BinarMinus() {
    *vipTourist = *vipTourist - 10;
    cout << "����� �� ������� " << vipTourist->getAge() << endl;
}
void Multiply() {
    *vipTourist = *vipTourist * 2;
    cout << "����� �� ������� " << vipTourist->getAge() << endl;
}
void PlusEqual() {
    *vipTourist += 5;
    cout << "����� �� ������� " << vipTourist->getAge() << endl;
}
void deleteVipTourist() {
    int tripNumber;
    std::cout << "����i�� ����� ���i��� ��� ��������� �������: ";
    std::cin >> tripNumber;

    bool touristDeleted = false;
    for (auto it = Viptourists.begin(); it != Viptourists.end(); ++it) {
        if ((*it)->myTrip.getTripNum() == tripNumber) {
            delete* it; // ��������� ��'��� � ���'��i
            Viptourists.erase(it); // ��������� ����i���� � �������
            std::cout << "������ � ������� ���i��� " << tripNumber << " ���i��� ���������." << std::endl;
            touristDeleted = true;
            break;
        }
    }
    if (!touristDeleted) {
        std::cout << "������� � ������� ���i��� " << tripNumber << " �� �������� � ������." << std::endl;
    }
}
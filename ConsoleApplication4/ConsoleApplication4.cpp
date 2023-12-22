#include <iostream>
#include <vector>
#include <locale>
#include <fstream>
#include <string>
#include <algorithm>  
#include <cstdlib>    
#include <ctime> 

#include "TourCompany.h"
#include "Tourist.h"
#include "VipTourist.h"
#include "TourCompanyRealization.cpp"
#include "TouristRelaization.cpp"
#include "VipTouristRealization.cpp"

int main() {
    setlocale(LC_ALL, "ukr");

    TourCompany myCompany = createCompany("TravelCo", "info@travelco.com", 1234567890);
    string command;
    do {
        std::cout << "Введiть команду (Add, Show_company_info, Show_Tourists_From_File, Show_VipTourists_From_File, Show_Tourists, Show_VipTourists, Show_trips_count, Delete_Tourist, Delete_VipTourist, Service, Operators або Exit): ";
        std::cin >> command;


        if (command == "Add") {
            ofstream Tourists("Tourists", ios::app);

            string type;
            std::cout << "Введiть тип подорожi (VIP або Common): ";
            std::cin >> type;

            if (type == "VIP") {
                setVIPTourists(myCompany);
            }
            else if (type == "Common") {
                setCommonTourists(myCompany);

            }
        }
        else if (command == "Show_company_info")
        {
            Show_company_info(myCompany);
        }
        else if (command == "Show_trips_count") {
            cout << myCompany.getTripsCount() << endl;
        }
        else if (command == "Show_VipTourists") {
            show_VipTourists();
        }
        else if (command == "Show_VipTourists_From_File") {
            showVipTouristFromFile();
        }
        else if (command == "Show_Tourists")
        {
            ShowTourist();
        }
        else if (command == "Show_Tourists_From_File")
        {
            showTouristFromFile();
        }
        else if (command == "Delete_Tourist")
        {
            deleteTourist();

        }
        else if (command == "Operators")
        {

            string a, b;
            string c,d;
            cin >> c;
            if (c == "unar")
            {
                cin >> a;
                if (a == "Prefix")
                {
                    cin >> b;
                    if (b == "Plus")
                    {
                        PlusPrefixOp();
                    }
                    else if (b == "Minus")
                    {
                        MinusPrefixOp();
                    }
                }
                else if (a == "Postfix")
                {
                    cin >> b;
                    if (b == "Plus")
                    {
                        PlusPostfixOp();
                    }
                    else if (b == "Minus")
                    {
                        MinusPostfixOp();
                    }
                }
            }
            else if (c == "binar")
            {
                cin >> d; 
                if (d == "Plus")
                {
                    BinarPlus();
                }
                else if (d == "Minus")
                {
                    BinarMinus();
                }
                else if (d == "Multiply") 
                {
                    Multiply();
                }
                else if (d == "Plus_Equal")
                {
                    PlusEqual();
                }
            }
        }
        else if (command == "Delete_VipTourist")
        {
            deleteVipTourist();

        }
        else if (command == "foreach")
        {
            myCompany.displayTrips();
        }
        else if (command == "Service")
        {
            Service("CompanyInfo.txt", myCompany);
        }
    } while (command != "Exit");

    for (Tourist* tourist : tourists) {
        delete tourist;
    }
    for (Tourist* vipTourist : Viptourists) {
        delete vipTourist;
    }

    return 0;

}

#include "Country.h"

void Show_company_info(TourCompany& myCompany){
    std::cout << "iм'я: " << myCompany.getName() << std::endl;
    std::cout << "Електронна пошта: " << myCompany.getEmail() << std::endl;
    std::cout << "Номер телефону: " << myCompany.getPhone() << std::endl;

}



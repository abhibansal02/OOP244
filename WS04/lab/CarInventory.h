/*
    ==================================================
    Workshop #4 (Part-1):
    ==================================================
    Name   : Abhi Bansal
    ID     : 122132210
    Email  : abansal19@myseneca.ca
    Section: NMM
    Date   : 02/10/2022
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef _CAR_INVENTORY_H
#define _CAR_INVENTORY_H

namespace sdds
{
    class CarInventory
    {
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;
        void resetInfo();
    public:
        CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
        ~CarInventory();
        void printInfo() const;
        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;
    };

    bool find_similar(CarInventory car[], const int num_cars);

};
#endif
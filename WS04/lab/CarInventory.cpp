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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CarInventory.h"
using namespace std;

namespace sdds
{
    CarInventory::CarInventory()
    {
        this->resetInfo();
    };
    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        m_type=nullptr;
        m_brand=nullptr;
        m_model=nullptr;
        this->setInfo(type,brand,model,year,code,price);
    };
    CarInventory::~CarInventory() 
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    };

    void CarInventory::resetInfo()
    {
        m_type=nullptr;
        m_brand=nullptr;
        m_model=nullptr;
        m_year=0;
        m_code=0;
        m_model=0;
    };

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || (code < 100 || code>999) || price < 1)
        {
            delete[] this->m_type;
            delete[] this->m_brand;
            delete[] this->m_model;
            this->resetInfo();
        }
        else
        {
            delete[] m_type;
            delete[] m_brand;
            delete[] m_model;
            m_type = new char[strlen(type) + 1];
            m_brand = new char[strlen(brand) + 1];
            m_model = new char[strlen(model) + 1];
            strcpy(m_type, type);
            strcpy(m_brand, brand);
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;
        }
        return *this;
    }

    void CarInventory::printInfo() const
    {

        cout << left << "| " << setw(10) << m_type << " | " << setw(16) << m_brand << " | " << setw(16) << m_model;
        cout << right << " | " << setw(4) << m_year << " | " << setw(4) << m_code << " | " << fixed << setprecision(2) << setw(9) << m_price << " |" << endl;
    };

    bool CarInventory::isValid() const
    {
        return (m_type != nullptr && m_brand != nullptr && m_model != nullptr &&
               m_year >= 1990 && (m_code >= 100 && m_code <= 999) && m_price > 0);
    };

    bool CarInventory::isSimilarTo(const CarInventory& car) const
    {
        bool ret = false;
        if (car.isValid() && this->isValid())
        {
            ret = (strcmp(car.m_type, this->m_type) == 0) && (strcmp(car.m_brand, this->m_brand) == 0) &&
                (strcmp(car.m_model, this->m_model) == 0) && (car.m_year == this->m_year);
        }
        else if (!car.isValid() && !this->isValid())
        {
            ret = true;
        }

        return ret;
    }

    bool find_similar(CarInventory car[], const int num_cars)
    {
        bool ret=false;
        for (int i = 0; i < num_cars; i++)
        {
            for (int j = i + 1; j < num_cars; j++)
            {
                if (car[i].isSimilarTo(car[j]))
                {
                    ret=true; // match is found
                }
            }
        }

        return ret;

    };
}
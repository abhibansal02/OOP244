/* ------------------------------------------------------
Workshop 3 part 1
Name: Abhi Bansal
Email: abansal19@myseneca.ca
Date: 02/04/2022  
Section: NMM
ID: 122132210
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/

#ifndef _TRAIN_H
#define _TRAIN_H
#define MAX_NAME_LEN 20
#define MAX_PEOPLE 1000
#define MAX_SPEED 320
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>

namespace sdds
{
    class Train
    {
        char name[MAX_NAME_LEN+1];
        int numPeople;
        double speed;
    

    public:
        bool isSafeEmpty() const;
        void display() const;
        double getSpeed() const;
        const char* getName() const;
        int getNumberOfPeople() const;
        void set(const char*, int, double);
        bool safeState;
    };
}

#endif

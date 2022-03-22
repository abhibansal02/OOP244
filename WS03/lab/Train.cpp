/* ------------------------------------------------------
Workshop 3 part 1
Name: Abhi Bansal
Email: abansal19@myseneca.ca
Date: 02/04/2022
Section: NMM
ID: 122132210
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/

#include "Train.h"

using namespace std;

namespace sdds
{
    void Train::set(const char* name, int numPeople, double speed)
    {
        int length=0;
        safeState=false;
        if (name != nullptr)
        {
            length=strlen(name);
        }

        if ((name != nullptr && length > 0 && (numPeople >= 0 && numPeople <= MAX_PEOPLE) && (speed >= 0 && speed <= MAX_SPEED)))
        {
            strncpy(this->name,name,MAX_NAME_LEN);
            this->numPeople=numPeople;
            this->speed=speed;
        }

        else
        {
            safeState=true;
        }
    }

    int Train::getNumberOfPeople() const
    {
        return this->numPeople;
    }

    const char* Train::getName() const
    {
        return this->name;
    }

    double Train::getSpeed() const
    {
        return this->speed;
    }

    bool Train::isSafeEmpty() const
    {
        return safeState;
    }

    void Train::display() const
    {
        if (safeState)
        {
            cout<<"Safe Empty State!\n";
        }
        else
        {
            cout << "NAME OF THE TRAIN : " << this->name << "\n";
            cout << "NUMBER OF PEOPLE  : " << this->numPeople << "\n";
            cout << "SPEED             : " << this->speed << " km/h" << "\n";
        }
    }
}
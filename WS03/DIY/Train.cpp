/* ------------------------------------------------------
Workshop 3 part 1
Name: Abhi Bansal
Email: abansal19@myseneca.ca
Date: 02/06/2022
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
        int length = 0;
        safeState = false;
        if (name != nullptr)
        {
            length = strlen(name);
        }

        if ((name != nullptr && length > 0 && (numPeople >= 0 && numPeople <= MAX_PEOPLE) && (speed >= 0 && speed <= MAX_SPEED)))
        {
            strncpy(this->name, name, MAX_NAME_LEN);
            this->numPeople = numPeople;
            this->speed = speed;
        }

        else
        {
            safeState = true;
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
            cout << "Safe Empty State!\n";
        }
        else
        {
            cout << "NAME OF THE TRAIN : " << this->name << "\n";
            cout << "NUMBER OF PEOPLE  : " << this->numPeople << "\n";
            cout << "SPEED             : " << this->speed << " km/h" << "\n";
        }
    }

    bool Train::loadPeople(int newPeople)
    {
        if ((numPeople + newPeople) <= MAX_PEOPLE && (numPeople + newPeople) >= 0)
        {
            numPeople+=newPeople;
        }
        else if (newPeople > 0)
        {
            numPeople=MAX_PEOPLE;
        }
        else
        {
            speed=0;
            numPeople=0;
            return true;
        }
        return newPeople;
    }

    bool Train::changeSpeed(int newSpeed)
    {
        if ((speed + newSpeed) <= MAX_SPEED && (speed + newSpeed) >= 0)
        {
            speed+=newSpeed;
        }
        else if (newSpeed > 0)
        {
            speed=MAX_SPEED;
        }
        else
        {
            speed=0;
            return true;
        }
        if (safeState)
        {
            return false;
        }
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        return newSpeed;
    }

    int transfer(Train& one, Train& two)
    {
        int total=one.getNumberOfPeople() + two.getNumberOfPeople();
        int moved_people=0;
        int extras=0;

        if (total < MAX_PEOPLE)
        {
            moved_people=two.getNumberOfPeople();
        }
        else
        {
            extras = total-MAX_PEOPLE;
            moved_people=two.getNumberOfPeople()-extras;
        }
        if (one.isSafeEmpty() || two.isSafeEmpty())
        {
            return -1;
        }

        two.loadPeople(-moved_people);
        one.loadPeople(moved_people);
        return moved_people;
    }
}
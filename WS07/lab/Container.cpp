/*
    ==================================================
    Workshop #7 Lab:
    ==================================================
    Name   : Abhi Bansal
    ID     : 122132210
    Email  : abansal19@myseneca.ca
    Section: NMM
    Date   : 03/16/2022
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>

#include"Container.h"

using namespace std;
namespace sdds
{

    void Container::setEmpty ()
    {
        
        mCapacity = -1;
    }

    int Container::capacity ()
    {
        return  mCapacity;
    }

    int Container::volume ()
    {
        return mContentVolume;
    }

    int Container::operator +=( int n )
    {
        int newVolume = n + mContentVolume;
        int change = n;

        if(newVolume > mCapacity)
        {
            mContentVolume = mCapacity;
            change = n - (newVolume - mCapacity);
        }
        else
        {
            mContentVolume = newVolume;
        }

        return change;
    }

    int Container::operator -=( int n )
    {
        int newVolume = mContentVolume - n;
        int change = n;

        if(newVolume < 0)
        {
            change += newVolume;
            mContentVolume = 0;
        }
        else
        {
            mContentVolume = newVolume;
        }

        return change;
    }

    Container::operator bool ()
    {
        return mCapacity >= 0;
    }

    void Container::clear ( int capacity, const char* desc )
    {
        if(capacity > 0 && desc != nullptr)
        {
            mCapacity = capacity;
            strncpy ( mContent, desc, 50 );
        }
    }

    ostream& Container::print ( ostream& os )
    {
        if(mCapacity == -1) os << "****: (**cc/***)";
        else os << mContent << ": (" << mContentVolume << "cc/" << mCapacity << ")";
        return os;
    }


    istream& Container::read ( istream& is )
    {
        if(mCapacity == -1)
        {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
            is.ignore ( 1, '\n' );
        }
        else if(mCapacity == mContentVolume)
        {
            cout << "Pack is full!, press <ENTER> to continue...";
            is.ignore ( 1, '\n' );
        }
        else
        {
            int num = 0;
            int amountAdded;
            cout << "Add to ";
            print ( cout ) << endl;
            cout << "> ";
            is >> num;

            if(num >= 1 && num < 999)
            {
                amountAdded = (*this += num);

                cout << "Added " << amountAdded << " CCs" << endl;
            }
            else
            {
                cout << "Value out of range [1<=val<=999]: ";
            }
        }
        return is;
    }

    Container::Container ( const char* content, int capacity, int contentVolume )
    {
        if(content == nullptr || contentVolume > capacity)
        {
            setEmpty ();
            return;
        }

        strncpy ( mContent, content, 50 );
        mCapacity = capacity;
        mContentVolume = contentVolume;
    }

    istream& operator>>( istream& is, Container& con )
    {
        return con.read ( is );
    }

    ostream& operator<<( ostream& os, Container& con )
    {
        return con.print ( os );
    }


}
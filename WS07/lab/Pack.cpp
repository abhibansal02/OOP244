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
#include "Container.h"
#include "Pack.h"
#include<iostream>

using namespace std;

namespace sdds
{
    int Pack::operator+=( int n )
    {
        return Container::operator+=( n * mUnitSize ) / mUnitSize;
    }

    int Pack::operator-=( int n )
    {
        return Container::operator-=( n * mUnitSize ) / mUnitSize;
    }

    int Pack::unit ()
    {
        return mUnitSize;
    }

    int Pack::noOfUnits ()
    {
        return volume () / mUnitSize;
    }

    int Pack::size ()
    {
        return  capacity () / mUnitSize;
    }

    void Pack::clear ( int size, int unitSize, const char* description )
    {
        if(unitSize > 0)
        {
            Container::clear ( size * unitSize, description );
            mUnitSize = unitSize;
        }
    }

    ostream& Pack::print ( ostream& os )
    {
        if(capacity () != -1)
        {
            Container::print ( os );
            os << ", " << noOfUnits () << " in a pack of " << size ();
        }
        else
        {
            os << "Broken Container, adding aborted! Press <ENTER> to continue....";
        }
        return os;
    }

    istream& Pack::read ( istream& is )
    {
        if(capacity () != -1)
        {
            if(noOfUnits () < size ())
            {
                int range = size () - noOfUnits ();
                cout << "Add to ";
                print ( cout ) << endl << "> ";
                int num;
                is >> num;

                if(num >= 1 && num <= range)
                {
                    int added = *this += num;
                    cout << "Added " << added << endl;
                }
                else
                {
                    cout << "Value out of range [1<=val<=" << range << "]: ";
                    is >> num;
                    if(num >= 1 && num <= range)
                    {
                        int added = *this += num;
                        cout << "Added " << added << endl;
                    }
                }

            }
            else
            {
                cout << "Pack is full!, press <ENTER> to continue..." << endl;
                is.ignore ( 1, '\n' );
            }
        }
        else
        {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            is.ignore ( 1, '\n' );
        }
        return is;
    }

    Pack::Pack ( const char* description, int size, int unitSize, int numberOfUnits ) : Container ( description, size* unitSize, numberOfUnits* unitSize )
    {
        if(unitSize >= 0)
        {
            mUnitSize = unitSize;
        }
        else
        {
            setEmpty ();
        }

    }


    istream& operator>>( istream& is, Pack& p )
    {
        return p.read ( is );
    }

    ostream& operator<<( ostream& os, Pack& p )
    {
        return p.print ( os );
    }

}
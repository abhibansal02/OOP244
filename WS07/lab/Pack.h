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
#include<iostream>

using namespace std;
namespace sdds
{
    class Pack : public Container
    {
    private:
        int mUnitSize=0;

    public:
        int operator+=( int n );
        int operator-=( int n );
        int unit ();
        int noOfUnits ();
        int size ();
        void clear ( int size, int unitSize, const char* description );

        ostream& print ( ostream& os );
        istream& read ( istream& is );

        Pack ( const char* description, int size, int unitSize = 330, int numberOfUnits = 0 );
    };

    istream& operator>>( istream& is, Pack& p );
    ostream& operator<<( ostream& os, Pack& p );
}
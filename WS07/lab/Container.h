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

using namespace std;
namespace sdds
{
    const int MAX_CONTAINER_CONTENT = 50;

    class Container
    {
    private:
        char mContent[MAX_CONTAINER_CONTENT];
        int mCapacity;
        int mContentVolume=0;

    protected:
        void setEmpty ();

        int capacity ();

        int volume ();

    public:
        int operator +=( int n );
        
        int operator -=( int n );

        operator bool ();

        void clear ( int capacity, const char* desc );

        ostream& print ( ostream& os );

        istream& read ( istream& is );

        Container ( const char* content, int capacity, int contentVolume = 0 );
    };

    istream& operator>>( istream& is, Container& con );
    ostream& operator<<( ostream& os, Container& con );

}
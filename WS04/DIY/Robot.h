/*
    ==================================================
    Workshop #4 (Part-2):
    ==================================================
    Name   : Abhi Bansal
    ID     : 122132210
    Email  : abansal19@myseneca.ca
    Section: NMM
    Date   : 02/13/2022
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Reason for resubmission: Forgot to add the name template.
*/


#ifndef _ROBOT_H
#define _ROBOT_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sdds
{
    class Robot
    {
        char* m_Name;
        char* m_Location;
        double m_Weight;
        double m_Width;
        double m_Height;
        double m_Speed;
        bool m_Deployed;
        void reset();
        void set_p(const char* name, const char* location, double weight, double width,
            double height, double speed, double deployment);

    public:
        Robot();
        Robot(const char* name, const char* location, double weight,
        double width, double height, double speed, double deployment);
        ~Robot();

        Robot& set(const char* name, const char* location, double weight, double width,
            double height, double speed, double deployment);
        void setLocation(const char* location);
        void setDeployed(bool deployed);
        char* getName() const;
        char* getLocation() const;
        bool isDeployed() const;
        bool isValid() const;
        void display() const;
        double speed() const;
    };
    int conrtolRooomReport(const Robot robot[], int num_robots);
    void header_show();
    void lineDisp();
    void controlHeaderDisp();
   
}

#endif

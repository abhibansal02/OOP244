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

#include "Robot.h"
using namespace std;

namespace sdds
{
    Robot::Robot()
    {
        m_Name=nullptr;
        m_Location=nullptr;
        m_Weight=0;
        m_Width=0;
        m_Height=0;
        m_Speed=0;
        m_Deployed=0;
    }

    void Robot::set_p(const char* name, const char* location, double weight, double width,
        double height, double speed, double deployment)
    {
        m_Name=new char[strlen(name)+1];
        m_Location=new char[strlen(location)+1];
        strcpy(m_Name,name);
        strcpy(m_Location,location);
        m_Weight=weight;
        m_Width=width;
        m_Height=height;
        m_Speed=speed;
        m_Deployed=deployment;
    }

    Robot::Robot(const char* name, const char* location, double weight,
        double width, double height, double speed, double deployment)
    {
        set_p(name, location, weight, width, height, speed, deployment);
    }

    Robot::~Robot()
    {
        reset();
    }

    void Robot::reset()
    {
        if (m_Name != nullptr)
        {
            delete[] m_Name;
        }

        if (m_Location != nullptr)
        {
            delete[] m_Location;
        }
    }

    Robot& Robot::set(const char* name, const char* location, double weight,
        double width, double height, double speed, double deployment)
    {
        reset();
        set_p(name, location, weight, width, height, speed, deployment);

        return *this;
    }

    void Robot::setLocation(const char* location)
    {
        delete[] m_Location;
        m_Location= new char[strlen(location)+1];
        strcpy(m_Location,location);
    }

    void Robot::setDeployed(bool deployed)
    {
        m_Deployed=deployed;
    }

    char* Robot::getName() const
    {
        return m_Name;
    }

    char* Robot::getLocation() const
    {
        return m_Location;
    }

    bool Robot::isDeployed() const
    {
        return m_Deployed;
    }

    bool Robot::isValid() const
    {
        return((m_Name!=nullptr) && (m_Location != nullptr) && (m_Weight != 0)
        && (m_Height != 0) && (m_Width != 0) && (m_Speed != 0));
    }

    double Robot::speed() const
    {
        return m_Speed;
    }

    void Robot::display() const
    {
        cout << "| " << setw(10) << left << m_Name <<" | " << setw(15) << m_Location<< setprecision(1) << fixed << right
            << " | " << setw(6) << m_Weight<< " | " << setw(6) << m_Width<< " | " << setw(6) << m_Height<< " | " << setw(6) << m_Speed
            << " | " <<left<< setw(8) << (m_Deployed ? "YES" : "NO") << " |" << endl;
    }

    void header_show()
    {
        cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl
            <<"|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
    }

    void lineDisp()
    {
        cout << "|=============================================================================|" << endl;

    }


    void controlHeaderDisp()
    {
        cout <<"                        " << "------ Robot Control Room -----" << endl;
        cout<<"                    " << "---------------------------------------" << endl;
    }

    int conrtolRooomReport(const Robot robot[], int num_robots)
    {
        controlHeaderDisp();
        header_show();

        double max_speed=0;
        int robots_deployed=0;
        for (int i = 0; i < num_robots; i++)
        {
            if (!robot[i].isValid())
            {
                return i;
            }
            robot[i].display();
            if (robot[i].speed() >= max_speed)
            {
                max_speed=robot[i].speed();
            }
            if (robot[i].isDeployed())
            {
                ++robots_deployed;
            }
        }

        lineDisp();
        cout << "| " << setw(75) << left << "SUMMARY:" << " |" << endl<< "| " << robots_deployed << setw(74) << left
            << "  robots are deployed." << " |" << endl << "| " << setw(75) << left << "The fastest robot is:" << " |" << endl;

        header_show();

        for (int i = 0; i < num_robots; ++i)
        {
            if (robot[i].speed() == max_speed)
            {
                robot[i].display();
            }
        }
        lineDisp();
        return -1;
    }

}
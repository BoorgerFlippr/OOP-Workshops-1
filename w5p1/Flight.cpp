/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
16-02-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const
    {
        bool toReturn = false;

        if (m_passengers > 0 && m_fuel >= 600 * m_passengers)
        {
            toReturn = true;
        }

        return toReturn;
    }

    Flight::operator int() const
    {
        return m_passengers;
    }

    Flight::operator double() const
    {
        return m_fuel;
    }

    Flight::operator char*() const
    {
        return (char*)m_title;
    }

    bool Flight::operator~() const
    {
        bool numP = false;

        if (m_passengers == 0)
            numP = true;

        return numP;
    }

    Flight& Flight::operator=(Flight& plane)
    {
    
        this->m_passengers = plane.m_passengers;
        this->m_fuel = plane.m_fuel;
        strcpy(this->m_title, plane.m_title);

        plane.m_passengers = 0;
        plane.m_fuel = 0.0;
        strcpy(plane.m_title, "EmptyPlane");

        return *this;
    }

    Flight& Flight::operator=(int passengers)
    {
        if (passengers >= 0 && passengers <= Boen747Capacity)
        {
            this->m_passengers = passengers;
        }

        return *this;
    }

    Flight& Flight::operator=(double fuel)
    {
        if (fuel >= 0.0 && fuel <= FuelTankCapacity)
        {
            this->m_fuel = fuel;
        }

        return *this;
    }

    Flight& Flight::operator+=(double fuel)
    {
        if (fuel >= 0 || this->m_fuel < FuelTankCapacity)
        {
            this->m_fuel += fuel;
        }

        return *this;
    }

    Flight& Flight::operator+=(int passengers)
    {
        if (passengers >= 0 || this->m_passengers < Boen747Capacity)
        {
            this->m_passengers += passengers;
        }

        return *this;
    }

    Flight& Flight::operator-=(double fuel)
    {
        if (fuel >= 0)
            this->m_fuel -= fuel;

        return *this;
    }

    Flight& Flight::operator-=(int passengers)
    {
        if (passengers >= 0)
            this->m_passengers -= passengers;

        return *this;
    }

    Flight& Flight::operator<<(Flight& plane)
    {
        this->m_passengers += plane.m_passengers;
        if (this->m_passengers > Boen747Capacity)
        {
            plane.m_passengers = this->m_passengers - Boen747Capacity;
            this->m_passengers = Boen747Capacity;
        }

        return *this;
    }

    Flight& Flight::operator>>(Flight& plane)
    {
        plane.m_passengers += this->m_passengers;
        if (plane.m_passengers > Boen747Capacity)
        {
            this->m_passengers = plane.m_passengers - Boen747Capacity;
            plane.m_passengers = Boen747Capacity;
        }

        return *this;
    }

    int operator+(const Flight& plane1, const Flight& plane2)
    {
        int toReturn = plane1.m_passengers + plane2.m_passengers;

        return toReturn;
    }

    int operator+=(int& num, const Flight& plane)
    {
        int toReturn = num += plane.m_passengers;

        return toReturn;
    }
}
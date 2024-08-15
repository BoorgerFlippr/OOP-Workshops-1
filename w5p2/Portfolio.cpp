/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
19-02-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
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
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const
    {
        return m_value;
    }

    Portfolio::operator const char* () const
    {
        return m_stock;
    }

    Portfolio::operator char() const
    {
        return m_type;
    }

    Portfolio::operator bool() const
    {
        bool toReturn = false;

        if (m_type == 'G' || m_type == 'V' || m_type == 'I')
        {
            toReturn = true;
        }
        else 
            toReturn = false;

        return toReturn;
    }

    Portfolio& Portfolio::operator+=(double val)
    {
        if ((bool)(*this))
        {
            //cout << "exec\n";
            m_value += val;
        }

        return *this;
    }

    Portfolio& Portfolio::operator-=(double val)
    {
        if ((bool)(*this))
        {
            //cout << "exec\n";
            m_value -= val;
        }

        return *this;
    }

    bool Portfolio::operator~() const
    {
        bool toReturn = false;

        if (m_value < 0)
        {
            toReturn = true;
        }

        return toReturn;
    }

    Portfolio& Portfolio::operator<<(Portfolio& val)
    {
        this->m_value += val.m_value;
        val.emptyPortfolio();

        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& val)
    {
        val.m_value += this->m_value;
        this->emptyPortfolio();

        return *this;
    }

    double operator+(const Portfolio& valLeft, const Portfolio& valRight)
    {
        double toReturn = valLeft.m_value + valRight.m_value;

        return toReturn;
    }

    double operator+=(double& valLeft, const Portfolio& valRight)
    {
        double toReturn = valLeft += valRight.m_value;

        return toReturn;
    }

}
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
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        void emptyPortfolio();
        Portfolio(double, const char*, char);
        void dispPortfolio() const;
        std::ostream& display() const;
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;
        Portfolio& operator+=(double);
        Portfolio& operator-=(double);
        bool operator~() const;
        Portfolio& operator<<(Portfolio&);
        Portfolio& operator>>(Portfolio&);
        friend double operator+(const Portfolio&, const Portfolio&);
        friend double operator+=(double&, const Portfolio&);

    };
}
#endif // SDDS_Portfolio_H_
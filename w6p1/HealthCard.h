/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
02-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

using namespace std;
namespace sdds {
    const int MaxNameLength = 55;
    class HealthCard {
        char* m_name{};
        long long m_number;
        char m_vCode[3];
        char m_sNumber[10];
        //---------------//
        //---------------//
        void setEmpty();
        void allocateAndCopy(const char*);
        bool validID(const char*, long long, const char[], const char[]) const;
        void extractChar(std::istream&, char) const;
        std::ostream& printIDInfo(std::ostream& ostr)const;
        void set(const char*, long long, const char[], const char[]);
    public:
        HealthCard();
        HealthCard(const char*, long long, const char[], const char[]);
        HealthCard(const HealthCard&);
        HealthCard& operator=(const HealthCard&);
        ~HealthCard();
        operator bool() const;
        ostream& print(std::ostream&, bool) const;
        istream& read(istream& istr);
        friend ostream& operator<<(std::ostream&, const HealthCard&);
        friend istream& operator>>(std::istream&, HealthCard&);
        
    };

    
}
#endif // !SDDS_HealthCard_H

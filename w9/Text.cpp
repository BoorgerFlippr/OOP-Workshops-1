/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
30-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Text.h"
#include<string.h>
#include<cstring>
#include<iomanip>
using namespace std;
namespace sdds 
{
    const char& Text::operator[](int index)const {
        return m_content[index];
    }

    Text::Text() {
        m_content = nullptr;
    }

    Text::Text(const Text& tx) {
        *this = tx;
    }

    Text& Text::operator=(const Text& tx) {
        if (tx.m_content != nullptr)
        {
            delete[] m_content;
            m_content = nullptr;
            m_content = new char[strlen(tx.m_content) + 1];
            strcpy(m_content, tx.m_content);
        }
        return *this;
    }

    Text::~Text() {
        delete[] m_content;
        m_content = nullptr;
    }

    istream& Text::read(istream& is) {
        delete[] m_content;
        m_content = nullptr;
        int i = 0;
        char c;
        int len = getFileLength(is) + 1;
        m_content = new char[len];
        while (is.get(c))
        {
            if (is)
            {
                m_content[i] = c;
                i++;
            }

        }
        m_content[i] = '\0';
        if (m_content != nullptr)
        {
            is.clear();
        }
        return is;
    }

    ostream& Text::write(ostream& os) const {
        if (m_content != nullptr)
        {
            os << m_content;
        }
        return os;
    }

    int Text::getFileLength(std::istream& is) {
        int len{};
        if (is) {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // let what is the positions (end position = size)
            len = is.tellg();
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }

    istream& operator>>(istream& is, Text& tx) {
        tx.read(is);
        return is;
    }
    ostream& operator<<(ostream& os, const Text& tx) {
        tx.write(os);
        return os;
    }
}
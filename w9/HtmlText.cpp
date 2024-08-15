/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
30-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Text.h"
#include"HtmlText.h"
#include<string.h>
#include<cstring>
#include<iomanip>
using namespace std;
namespace sdds
{
    HtmlText::HtmlText(const char* title) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    }

    HtmlText::HtmlText() {
        m_title = nullptr;
    }

    HtmlText::HtmlText(const HtmlText& ht) {
        *this = ht;
    }

    HtmlText& HtmlText::operator=(const HtmlText& ht) {
        Text::operator=(ht);
        if (ht.m_title != nullptr)
        {
            if (m_title != nullptr)
            {
                delete[] m_title;
                m_title = nullptr;
            }
            m_title = new char[strlen(ht.m_title) + 1];
            strcpy(m_title, ht.m_title);
        }
        return *this;
    }

    HtmlText::~HtmlText() {
        delete[] m_title;
        m_title = nullptr;
    }

    ostream& HtmlText::write(ostream& ostr) const {
        bool MS = false;
        int i = 0;
        char ch;
        ostr << "<html><head><title>";
        if (m_title != nullptr)
        {
            ostr << m_title;
        }
        else
        {
            ostr << "No Title";
        }
        ostr << "</title></head>\n<body>\n";
        if (m_title != nullptr)
        {
            ostr << "<h1>" << m_title << "</h1>\n";
        }
        do
        {
            ch = Text::operator[](i);
            i++;
            if (ch == ' ')
            {
                if (MS == true)
                {
                    ostr << "&nbsp;";
                }
                else
                {
                    MS = true;
                    ostr << " ";
                }
            }
            else if (ch == '<')
            {
                ostr << "&lt;";
                MS = false;
            }
            else if (ch == '>')
            {
                ostr << "&gt;";
                MS = false;
            }
            else if (ch == '\n')
            {
                ostr << "<br />\n";
                MS = false;
            }
            else if (ch == '\0')
            {
                ;
            }
            else
            {
                MS = false;
                ostr << ch;
            }
        } while (ch != '\0');
        ostr << "</body>\n</html>";
        return ostr;
    }
}
/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
30-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include<iostream>
#include"Text.h"
using namespace std;
namespace sdds
{
	class HtmlText : public Text
	{
		char* m_title = nullptr;

	public:
		HtmlText(const char*);
		HtmlText();
		HtmlText(const HtmlText&);
		HtmlText& operator=(const HtmlText&);
		~HtmlText();
		ostream& write(ostream&) const;
	};
}
#endif // !SDDS_HTMLTEXT_H


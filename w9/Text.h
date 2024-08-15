/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
30-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include<iostream>
using namespace std;
namespace sdds
{
	class Text
	{
		char* m_content = nullptr;

	protected:
		const char& operator[](int) const;

	public:
		Text();
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		istream& read(istream&);
		virtual ostream& write(ostream&) const;
		int getFileLength(istream& is);


	};

	ostream& operator<<(ostream&, const Text&);
	istream& operator>>(istream&, Text&);
}
#endif // !SDDS_TEXT_H

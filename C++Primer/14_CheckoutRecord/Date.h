#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::ostream;
using std::istream;
using std::endl;

class Date{
private:
	int year_, month_,day_;
public:
	Date() {}   //default constructor
/*	constructor */
	Date(int year, int month, int day):year_(year), month_(month), day_(day) {}
	
friend ostream& operator << (ostream&, const Date&); //overload output
friend istream& operator >> (istream&, Date&);	//overload input

friend bool operator == (const Date&, const Date&);
friend bool operator != (const Date&, const Date&);
};

ostream& operator << (ostream& os, const Date& s) {
	os <<  s.year_ << '\t' <<  s.month_  << '\t' << s.day_ << endl;
	return os;
}

istream& operator >> (istream& in, Date& s) {
	in >> s.year_ >> s.month_ >> s.day_;
	if(!in) {
		s = Date();
	}
	return in;
}
bool operator ==(const Date& s1, const Date& s2) {
	return s1.year_ == s2.year_ && s1.month_ == s2.month_ && s1.day_ == s2.day_;
}

bool operator != (const Date& s1, const Date& s2) {
	if(s1==s2)
		return 0;
	else 
		return 1;
}


#endif

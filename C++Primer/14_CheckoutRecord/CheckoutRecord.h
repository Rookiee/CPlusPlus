#ifndef CHECKOUTREC_H
#define CHECKOUTREC_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "Date.h"


using std::istream;
using std::ostream;
using std::pair;
using std::vector;
using std::string;
using std::endl;
using std::cout;
/*************Define Class *****************/
class CheckoutRecord {
private:
	double book_id_;
	string title_;
	Date date_borrowed_;
	Date date_due_;
	pair<string, string> borrower_;
	vector<pair<string,string>* > wait_list_;

public:
	CheckoutRecord() {}
	CheckoutRecord(double book_id, string title, Date date_borrowed, Date date_due) : book_id_(book_id), title_(title), date_borrowed_(date_borrowed),
					date_due_(date_due) {}

	CheckoutRecord& operator = (const CheckoutRecord&);
//	CheckoutRecord& operator += (CheckoutRecord&);
//	CheckoutRecord& operator -= (CheckoutRecord&);
	pair<string,string> & operator [] (const size_t);
	const pair<string,string> & operator [] (const size_t) const;

friend bool operator == (const CheckoutRecord&, const CheckoutRecord&);
friend bool operator != (const CheckoutRecord&, const CheckoutRecord&);
friend bool operator <  (const CheckoutRecord&, const CheckoutRecord&);

friend ostream& operator << (ostream&, const CheckoutRecord&);
friend istream& operator >> ( istream&, CheckoutRecord&);

};

/*************Define Operations*************/

CheckoutRecord& CheckoutRecord::operator = (const CheckoutRecord& s) {
	book_id_ = s.book_id_;
	title_ = s.title_;
	date_borrowed_ = s.date_borrowed_;
	date_due_ = s.date_due_;
	borrower_.first = s.borrower_.first;
	borrower_.second = s.borrower_.second;

	wait_list_.clear();

	for(vector< pair<string,string>* >::const_iterator iter=s.wait_list_.begin(); iter != s.wait_list_.end(); ++iter) {
		pair<string,string>* ppr = new pair<string,string>;
		ppr->first = (*iter)->first;
		ppr->second = (*iter)->second;
		wait_list_.push_back(ppr);
	}
	return *this;		
}		

bool operator == (const CheckoutRecord& s1, const CheckoutRecord&s2) {
//	if( (s1.book_id_ == s2.book_id_) &&	(s1.title_ == s2.title_) && (s1.date_borrowed_ == s2.date_borrowed_) && (s1.date_due_ == s2.date_due_) 
//			&& s1.borrower_.first == s2.borrower_.first && s1.borrower_.second == s2.borrower_.second)
	if( (s1.book_id_ == s2.book_id_) &&	(s1.title_ == s2.title_) && (s1.date_borrowed_ == s2.date_borrowed_) && (s1.date_due_ == s2.date_due_) )
		return true;
	else
		return false;
}

bool operator != (const CheckoutRecord& s1, const CheckoutRecord& s2) {
	if(s1 == s2)
		return 0;
	else
		return 1;
}

 ostream& operator << ( ostream& os, const CheckoutRecord& s) {
	os << endl;
/*
	os << s.book_id_ << '\t' << s.title_ << '\t' << s.date_borrowed_ << '\t' << s.date_due_ << '\t';
	os << "Borrowers: " << s.borrower_.first << ", " << s.borrower_.second << endl;
	os << "Wait List: " << endl;
	for(vector< pair<string,string>* >::const_iterator iter = s.wait_list_.begin(); iter != s.wait_list_.end(); ++iter) {
		os << " " << (*iter)->first << ", " << (*iter)->second << endl;
	}
*/

	os << "The book id: " << '\t'<< s.book_id_ << endl;
	os << "Title: " << '\t' <<s.title_ << endl;
	os << "Borrowed date: " <<'\t' <<  s.date_borrowed_;
	os << "Borrowed due: " << '\t' << s.date_due_;
	os << "Borrower: " << '\t' << s.borrower_.first << ", " << s.borrower_.second << endl;
	os << "The wait list: " << endl;
	for(vector< pair<string,string>* >::const_iterator iter = s.wait_list_.begin(); iter != s.wait_list_.end(); ++iter) {
		os << " " << (*iter)->first << ", " << (*iter)->second << endl;
	}
	return os;
}

istream& operator >> ( istream& in, CheckoutRecord& s) {
	cout << "Input the id and title: ";
	in >> s.book_id_ >> s.title_;
	cout << "Input the borrowed date:(year, month, day) ";
	in >> s.date_borrowed_;
	cout << "Input the borrow due: ";
	in >> s.date_due_;
	cout << "Input the brower(pair<string,string>): ";
	in >> s.borrower_.first >> s.borrower_.second;	
	
	if(!in) {
		s = CheckoutRecord();
		return in;
	}

	cout << "Input the wait_list" << endl;
	s.wait_list_.clear();

	while(in) {
		pair<string,string>* ppr = new pair<string,string>;
		in >> ppr->first >> ppr->second;
		if(!in) {
			delete ppr;
			return in;
		}
		s.wait_list_.push_back(ppr);
	}
	return in;
}
	

pair<string,string>& CheckoutRecord::operator [] (const size_t index) {
	return *wait_list_[index];
} 
const pair<string,string>& CheckoutRecord::operator [] (const size_t index) const {
	return *wait_list_[index];
}

#endif

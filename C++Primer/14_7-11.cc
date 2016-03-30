#include <iostream>
#include <vector>
#include <utility>
class Date {
private:
	int year, month, day;
public:
	Date() {}
	Date(int y, int m, int d) {
		year = y; month = m, day = d;
	}
friend std::ostream& operator << (std::ostream& os, const Date& s) {
	os << "year: " << s.year << '\t' << "month: " << s.month << '\t' << "day: " << s.day << std::endl;
	return os;
}
/*
friend std::istream& operator >> (std::istream& in, Date& s) {
	Date tmp;
	in >> tmp.year >> tmp.month >> tmp.day;
	if(in) {
		s.year = tmp.year;	s.month = tmp.month;	s.day = tmp.day;
	}
	else 
		s = Date();
	return in; 
}
*/
friend std::istream& operator >> (std::istream&  in, Date& s) {
	in >> s.year >> s.month >> s.day;
	if(!in)
		s = Date();
	return in;
}
};

class CheckoutRecord {
private:
	double book_id;
	std::string title;
	Date date_borrowed;
	Date date_due;
	std::pair<std::string, std::string> borrower;
	std::vector< std::pair<std::string, std::string>* > wait_list;
public:

friend std::ostream& operator << (std::ostream& out, const CheckoutRecord& s) {
		out << s.book_id << "\t" << s.title << '\t' << s.date_borrowed 
			<< '\t' << s.date_due << '\t';
		out << "borrower: " << s.borrower.first << ", " << s.borrower.second;
		out << std::endl;
		out << "wait_list: " << std::endl;
		for(std::vector<std::pair<std::string, std::string>* >::const_iterator iter = s.wait_list.begin(); iter != s.wait_list.end(); ++iter) {
		out << '\t' << (*iter)->first << ", " << (*iter)->second << std::endl;
		}
		return out;
	}

friend std::istream& operator >>(std::istream& in, CheckoutRecord& s) {
	std::cout << "Input book id and title:" << std::endl;
	in >> s.book_id >> s.title;
	std::cout << "Input data_borrowed(year,month,day): " << std::endl;
	in >> s.date_due;

	std::cout << "Input the pair<string,string> borrower: " << std::endl;
	in >> s.borrower.first >> s.borrower.second;
	if(!in) {
		s = CheckoutRecord();
		return in;
	}
	
    std::cout << "Input the wait_list(string): " << std::endl;
	s.wait_list.clear();
	while(in) {
		std::pair<std::string, std::string>* ppr = new std::pair<std::string, std::string>;
		in >> ppr->first >> ppr->second;
		if(!in) {
			delete ppr;
			return in;
		}
		s.wait_list.push_back(ppr);
	}
	return in;
}

};

int main() {
	using namespace std;
	
	return 0;
}

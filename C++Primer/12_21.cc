#include <iostream>
#include <fstream>

class test {
private:
	const std::string str_;
	int int_;
	double *dp_;
//	std::ifstream &is;

public:
//	test():str_("test"),int_(20),dp_(&str_),ifstream(cin) {};
	test():str_("test"),int_(20),dp_(NULL) {}
	void print() {
/*
	test *p = new test();
	cout << p->str_ << endl;
	cout << p->int_ << endl;
	cout << p->*dp_ << endl;
	delete p;
*/
	std::cout << str_ << std::endl;
	std::cout << int_ << std::endl;
//	std::cout << *dp_ << std::endl;

	}
		
};

int main() {
	using namespace std;
	test my;
	my.print();

	return 0;		
}


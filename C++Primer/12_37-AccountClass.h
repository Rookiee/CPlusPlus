//#ifndef ACCOUNT.H
//#define ACCOUNT.H
#include <iostream>

class Account {
private:
	std::string owner;
	double amount;
	static double interestRate;

public:
	Account();
	explicit Account(std::string ):amount(0.0) {}
	Account(std::string str, double num) : owner(str),amount(num) {}
//	explicit Account(std::istream &is):is(std::cin) {}
	void showAccount() const;
};
double Account::interestRate = 0.1;

Account::Account() : owner("None"),amount(0.0) {};
//Account::Account(std::string = "None") : amount(0.0) {}
//Account::Account(std::istream &is) : is(std::cin), amount(0.0) {}
void Account::showAccount() const{
	std::cout << owner << " has " << amount * (1+interestRate) << " Dollor." << std:: endl;
}
	

//#endif

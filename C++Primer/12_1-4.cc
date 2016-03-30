#include <iostream>
#include <string>

class Person {
private:
	std::string name_;
	std::string address_;

public:
	Person() : name_("None"), address_("None") {};
	Person(const std::string &name, const std::string &address) : name_(name), address_(address) {};
	void ShowInfo() const {
		std::cout << name_ << " lives in " << address_ << std::endl;
	}
	std::string GetName() const {
		return name_;
	}

	std::string GetAddress() const {
		return address_;
	}
};

int main() {
	using namespace std;
	string name("Xie Haoyang");
	string address("Shanghai");
	Person per(name,address);
	per.ShowInfo();
	cout << "The name is " << per.GetName() << endl;
	cout << "Address is " << per.GetAddress() << endl;
	return 0;
}


#include <iostream>

class Employee {
private:
	std::string name_;
	int id_;
	static int cnt;  // define the unique ID, each new object is created, cnt will increment automatically,
					// a static data member is owned by the class and is shared by all of the objects

public:
	Employee() : name_("NONE"), id_(++cnt) {}
	Employee(std::string name);
	Employee(const Employee &);
	Employee & operator=(const Employee &);

	/* print out */
	void print();
};

int Employee::cnt = 0;  // define the static data member outside the class


// constructor 
Employee::Employee(std::string name) {
	name_ = name;	
	id_ = ++Employee::cnt;
}
// copy constructor
Employee::Employee(const Employee &orig) {
	this->name_ = orig.name_;
	this->id_ = Employee::cnt;
}
//overloaded assignment operator =
Employee & Employee::operator = (const Employee & orig) {
	name_ = orig.name_;
	id_ = cnt;
/* I ignored this following statement, but this code still works. WHY? */
//	return *this;
}
//show information for test
void Employee::print() {
	std::cout << name_ ;
	std::cout << " " << id_ << std::endl;
}


int main() {
	Employee person1; // create a new boject by default constructor
	person1.print(); 
	Employee haoyang("Haoyang");  // create a new object by the constructor which takes string parameter
	haoyang.print();
	Employee person2(haoyang);   // call copy constructor
	person2.print();
	Employee person3 = haoyang;  // call overloaded operator =
	person3.print();	
	return 0;
}



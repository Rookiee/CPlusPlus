#include <iostream>

class Math{
private:
	int * num1;
	int * num2;
public:
	Math():num1(0),num2(0) {}
/* The next two are error;
//	Math(int a, int b) : *num1(a), *num2(b) {}
//	Math(const Math &rhs) : *num1(*rhs.num1), *num2(*rhs.num2) {};

/*
// This constructor is ok, almost the same as the following one;
	Math(int &a, int &b) {
		num1 = new int(a);
		num2 = new int(b);
	}
*/
	Math(int &a, int  &b) : num1(new int(a)), num2(new int(b)) {}
/* The next one ----ERROR */
//	Math(int a, int b) : num1(new int(*a)), num2(new int(*b)) {}

	Math(const Math &rhs) : num1(new int(*rhs.num1)), num2(new int(*rhs.num2)) {}

	~Math() {
		if(num1)
			delete num1;
		if(num2)
			delete num2;
	}
	Math & operator = (const Math &rhs) {
		*num1 = *rhs.num1;
		*num2 = *rhs.num2;
		return *this;
	}

/* operation */
	int add() {
		return *num1 + *num2;
	}
	void get_vals() {
		if(num1==0 || num2==0)
			std::cout << "No values" << std::endl;
		else {
		std::cout << "The first is: " << *num1 << "The second is " << *num2 << std::endl;
		std::cout << "The sum is: " << this->add() << std::endl;
		}
	}
};

int main() {
	int a = 1, b = 1;
	Math t1;
	Math t2(a, b);
	Math t3(t2);
	Math t4 = t3;
	t1.get_vals();
	t2.get_vals();
	t3.get_vals();
	t4.get_vals();	
	return 0;
}


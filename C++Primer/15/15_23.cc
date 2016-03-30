#include <iostream>
using namespace std;

class Base {
public:
	void foo(int);
protected:
	int bar;
	double foo_bar;
};

class Derived : public Base {
public:
	void foo(string);
	bool bar_fcn(Base *pb);
	void foobar();
protected:
	string bar;
};

bool Derived::bar(Base *pb) {
	return foo_bar == pb->foo_bar;
}

int main() {
	
	return 0;
}


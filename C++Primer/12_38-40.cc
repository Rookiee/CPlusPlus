#include <iostream>

class Foo {
private:
	int int_;
public:
	Foo(int num):int_(num) {}

	int getValue() {	return this->int_; }
};

class Bar {
private:
	static int cnt;
	static int int_;
	static Foo foo_;
public:
	static Foo FooVal();
	static int callsFooVal();
	
	
};

int Bar::cnt = 0;
int Bar::int_ = 20;
Foo Bar::foo_ = Foo(0);



int Bar::callsFooVal() {
	Bar::cnt++;
//	std::cout << cnt << std::endl;
	return Bar::cnt;
}
Foo Bar::FooVal() {
	callsFooVal();
	return foo_;
}

int main() {
	using namespace std;
	Bar test;
	for(unsigned i = 0; i !=10 ;i++)
		test.FooVal();
	cout << test.callsFooVal()-1 << endl;
	return 0;
}



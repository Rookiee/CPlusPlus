#include <iostream>

class NoName {
private:
	std::string *pstring;
	int i;
	double d;
public:
	NoName() : pstring(new std::string),i(0),d(0) {}
	NoName(const NoName &newNoName) {
		pstring = new std::string;
//		pstring(newNoName.pstring);
		i=newNoName.i;
		d=(newNoName.d);
	}

	void get() {
		std::cout << *pstring << std::endl;
	}
};

int main() {
	NoName test();
	test.get();
	return 0;
}
	

#include <iostream>

class Test {
private:
	int val1, val2, val3;
public:
	Test() {}
	Test(int a,int b, int c) : val1(a), val2(b), val3(c) {}
	int operator () (const int, const int, const int) const;
};

int Test::operator()(int a, int b, int c) const {
	return a ? b:c;
}


int main() {
	using namespace std;
	int a=1, b = 2, c = 3;
	Test test(1,2,3);
	cout << test(0,2,3) << endl;	
	return 0;
}

 

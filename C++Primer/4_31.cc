#include <iostream>
#include <cstring>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	string str;
	getline(cin,str);
	string::size_type len = str.length();

//	char * pa = new char[len+1];
/*
	const char * p = pa;
	p = str.c_str();
	while(*p) {
		cout << *p ;
		++p;
	}
*/
	const char * pa = new char[len+1];
	const char *p = pa;
	p = str.c_str();
	
	while(*p) {
		cout << *p;
		++p;
	}

	
	cout << endl;



	delete [] pa;
	return 0;
}


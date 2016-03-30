#include <iostream>
#include <cstring>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	const char * pa = "Hello";
	const char * pb = " world!";
	size_t len = strlen(pa) + strlen(pb);
	char * pc = new char[len+1];
	strcpy(pc,pa);
	strcat(pc,pb);
	
	char * pcr = pc;
	while(*pcr) {
		cout << *pcr << " ";
		++pcr;
	}
	cout << endl;
	delete [] pc;
	return 0;
}
	

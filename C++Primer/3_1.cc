#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int value =2;
	int power = 10;
	int result = 1;
	for(unsigned i = 0; i<power;i++) {
		result *= value;
	}
	cout << value
		<< " raised to the power of "
		<< power << ": "
		<< result << endl;
	return 0;
}
 

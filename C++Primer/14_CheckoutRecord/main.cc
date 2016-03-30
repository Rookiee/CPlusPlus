#include <iostream>
#include "Date.h"
#include "CheckoutRecord.h"
using namespace std;

int main() {
	CheckoutRecord test1;
	cin >> test1;	
	cout << "The test1: " << endl;
	cout << test1 << endl;
	CheckoutRecord test2 = test1;
	if(test1 == test2){
		cout << "Test 1 and test 2 are equal, Test2: " << endl;
		cout << test2 << endl;
	}
//	cout << test2[1] << endl;
	return 0;
}



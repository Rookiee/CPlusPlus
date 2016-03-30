#include <iostream>
#include "CheckedPtr.h"
using namespace std;
int main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	CheckedPtr test1(a,a+10);
	cout << test1<< endl;
	cout << test1[3] << endl;	
	int a2[10] = {10,9,8,7,6,5,4,3,2,1};
	CheckedPtr test2(a2,a2+9);
	if(test1 != test2)
		cout << test2 << endl;	
	test2 = test1;
	cout << test2 << endl;
	
	

	return 0;
}


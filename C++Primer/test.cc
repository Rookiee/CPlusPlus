#include <string> 
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
	int a = 10;
	int *p1 = &a;
	int *p2 = p1;
	*p2 = 20;
	cout << *p1 << endl;
	cout << &a << endl;
	cout << &p1 << endl;
	cout << &p2 << endl << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	return 0;
}


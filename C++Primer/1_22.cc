#include <iostream>
#include "Sales_item.h"
using namespace std;
int main() {
	Sales_item item1, item2;
	cout << "Enter two books:" << endl;
	cin >> item1 >> item2;
	Sales_item sum;
	sum = item1 + item2;
	cout << sum << endl;

	return 0;
}


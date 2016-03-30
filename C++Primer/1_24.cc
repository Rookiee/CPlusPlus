#include <iostream>
#include "Sales_item.h"
using namespace std;
int main() {
	Sales_item trans, total;
	unsigned int count = 0;
	if(cin >> total) {
		while(cin >> trans) {
			if(trans.same_isbn(total)){
				total += trans;
				count ++;
			}
			else {
				cout << "NO MATCHING" << endl;
				total = trans;
			}
		cout << total << endl;
		cout << count << " trans totally." << endl;
		}
	}
	else {
		cout << "No data" << endl;
		return -1;
	}
	return 0;
}


#include <iostream>
#include <list>
using namespace std;

typedef list<int>::iterator Iterator;
int main() {

	return 0;
}

void writelist(list<int> & ilist){
	Iterator beg = ilist.begin();
	Iterator end = ilist.end();
	while(beg != end) {
		cout << *end << endl;
		end--;
	}
}
	

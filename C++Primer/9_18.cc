#include <iostream>
#include <list>
#include <deque>
using namespace std;
typedef list<int>::iterator iterList;
typedef deque<int>::iterator iterDeque;
int main() {
	list<int> ilist;
	int num;
	while(cin >> num)
		ilist.push_back(num);

	deque<int> de1,de2;
	for(iterList iterl = ilist.begin(); iterl != ilist.end(); ++iterl) {
		
		if(*iterl % 2 == 0) {
			de1.push_back(*iterl);
		}
		if(*iterl % 2 !=0) {
			de2.push_back(*iterl);
		}
	}

	for(iterDeque iterd = de1.begin(); iterd != de1.end(); ++iterd) {
		cout << *iterd ;
		if( iterd != de1.end()-1 )	cout << " ";
	}

	cout << endl;
	for(iterDeque iterd = de2.begin(); iterd != de2.end(); ++iterd) {
		cout << *iterd ;
		if( iterd != de2.end()-1 )	cout << " ";
	}

	return 0;
}

	
	

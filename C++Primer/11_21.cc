#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	int a[] = {1,2,3,4,0,6,0};
	list<int> ilist(a,a+sizeof(a)/sizeof(int));

	list<int>::iterator it = find(ilist.begin(),ilist.end(),0);
	for(list<int>::iterator iter = it; iter != ilist.end();++iter)
		cout << *iter << " ";
	cout << endl;

	list<int>::reverse_iterator it1 = find(ilist.rbegin(), ilist.rend(),3);
	cout << *it1 << endl;
	cout << *it1.base() << endl;
	for(list<int>::iterator iter = it1.base(); iter != ilist.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	
/*
	for(list<int>::iterator iter = it1.base(); iter != ilist.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
*/
	return 0;
}


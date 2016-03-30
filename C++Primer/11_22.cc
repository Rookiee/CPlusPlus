#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> ivec(a, a+10);
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << *iter ;
		if(iter != --ivec.end()) cout << " ";
	}
	cout << endl;

	list<int> ilist;
	copy(ivec.rbegin()+3, ivec.rend()-2, back_inserter(ilist));
	
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter) {
		cout << *iter ;
		if(iter != --ilist.end()) cout << " ";
	}
	cout << endl;

	

	return 0;
}


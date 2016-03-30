#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main() {
	int a[] = {1,2,1,2,3,4,5,5};
	vector<int> ivec(a,a+sizeof(a)/sizeof(int));
	cout << "The vector is: " << endl;
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	list<int> ilist;
//	list<int>::iterator itUnique = unique_copy(ivec.begin(), ivec.end(),ilist.begin());
	unique_copy(ivec.begin(), ivec.begin(),back_inserter(ilist));
//	cout << *ilist.begin() << endl;
//	cout << *(ilist.begin()+1) << endl;
//	cout << *(ilist.begin()+2) << endl;

	cout << "The list is: " << endl;
//	for(list<int>::iterator iter = ilist.begin(); iter != itUnique; ++iter)
//		cout << *iter << " ";
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end();++iter)
		cout << *iter << " ";
	cout << endl;
/*
	cout << "The real list is:" << endl;
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
*/	
	

	return 0;
}


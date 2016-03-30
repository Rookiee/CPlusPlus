#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
using namespace std;
typedef list<int>::iterator itList;
int main() {
	int at[] = {1,2,3,4,5};
	list<int> ls1(at, at+5);
	list<int> ls2;
//	vector<int> ivec;
	replace_copy(ls1.begin(), ls2.end(),front_inserter(ls2),33,3);
	
	/*   test the above one code */
	cout << "the new vector: " ;
/*
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
*/
	return 0;
}
	
	

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<int>::iterator Iterator;

int main() {
	vector<int> ivec;
	int num;
	while(cin>>num) 
		ivec.push_back(num);

	vector<int>::size_type len = ivec.size();
	int *pa = new int[int(len)+1];
	int *p = pa;
	
	for(Iterator iter = ivec.begin(); iter != ivec.end(); ++iter,++pa)
		*pa = *iter;
/*
	size_t i = 0;
	for(Iterator iter = ivec.begin(); iter != ivec.end(); ++iter,++i)
		pa[i] = *iter;
	
	int *p = pa;
*/
	while(*p) {
		cout << *p << " ";
		++p;
	}
	cout << endl;
	pa = p;
	delete [] pa;
	return 0;
}


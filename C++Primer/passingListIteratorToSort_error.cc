#include <string> 
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std; 

typedef list<int>::iterator Iter;
int main() {
	int a[] = {4,5,6,7,3,34,6,4};
	list<int> ilist(a,a+sizeof(a)/sizeof(int));

	sort(ilist.begin(),ilist.end());

	return 0;
}


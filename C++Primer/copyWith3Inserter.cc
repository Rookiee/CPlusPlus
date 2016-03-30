#include <string> 
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std; 

typedef list<int>::iterator Iter;
int main() {
	list <int> ls1;
	for(int i=0; i!=4;++i)
		ls1.push_front(i);

	for(Iter iter = ls1.begin(); iter !=ls1.end(); ++iter)
		cout << *iter << " " ;

	cout << endl;

	list<int> ls2;
	copy(ls1.begin(), ls1.end(), front_inserter(ls2) );
	for(Iter iter = ls2.begin(); iter !=ls2.end(); ++iter)
		cout << *iter << " " ;
	cout << endl;

	
	list<int> ls3(5);
	copy(ls1.begin(), ls2.end(), inserter(ls3,ls3.begin()));
	for(Iter iter = ls3.begin(); iter !=ls3.end(); ++iter)
		cout << *iter << " " ;

	return 0;
}

	

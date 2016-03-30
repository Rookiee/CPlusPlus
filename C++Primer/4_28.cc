#include <iostream>
#include <vector>
#include <cstring>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<int>::iterator Iterator;
int main() {
	vector<int> ivec;
	int num;
	while(cin>>num) {
		ivec.push_back(num);
	}
/*
	int size = ivec.size();	
	int *ipa = new int[size+1];
	int *p = ipa;
	
	for(Iterator iter = ivec.begin(); iter != ivec.end(); ++iter,++p) 
		*p = *iter;
	while(*ipa) {
		cout << *ipa << " ";
		++ipa;
	}
*/
	int *pia = new int[ivec.size()];
	/* This step is necessary, otherwise pia will point to the last element and
can not be pointed to the fisrt, we have to save the original position in order to iterate the whole array */

	int *p = pia;
	for(Iterator iter = ivec.begin(); iter != ivec.end(); ++iter,++p)
		*p = *iter;
	while(*pia) {
		cout << *pia << endl;
		pia++;
	}



	delete [] pia;
	return 0;
}
	

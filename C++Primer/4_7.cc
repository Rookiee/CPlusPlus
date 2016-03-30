#include <iostream>
#include <vector>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;

int main() {
/*	using array------------------
	const size_t buf_len = 5;
	int arr1[buf_len] = {1,2,3,4,5};
	int arr2[buf_len];
	for(size_t index = 0; index != buf_len; ++ index) {
		arr2[index] = arr1[index];
	}
	for(size_t index = 0; index != buf_len; ++ index) {
		cout << arr2[index] << " ";
	}
	cout << endl;
------------------------------*/

/*---------using vector-------------*/
	vector<int> ivec1(10,5);
	vector<int> ivec2(5,0);
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;	
	for(iter1 = ivec1.begin(); iter1 != ivec1.end(); ++iter1)
		cout << *iter1 << " ";
	cout << endl;
	for(iter2 = ivec2.begin();iter2 != ivec2.end(); ++iter2)
		cout << *iter2 << " ";
	cout << endl;
	
	ivec2 = ivec1;
	for(iter2 = ivec2.begin();iter2 != ivec2.end(); ++iter2)
		cout << *iter2 << " ";
	cout << endl;

	
		

	return 0;
}

	
	

	

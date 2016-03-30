#include <iostream>
#include <vector>
#include <cstring>

using std::cout;
using std::endl;
using std::vector;

typedef vector<int>::iterator Iterator;

int main() {
	int arr[] = {1,2,3,4,5,6};
	cout << sizeof(arr) << endl;
//	int *arr (1,2,3,4,5,6);
	vector<int> ivec (arr,arr+sizeof(arr)/sizeof(int));
	for(Iterator iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}


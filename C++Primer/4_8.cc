#include <iostream>
#include <vector>
#include <cstddef>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
/*------------using array-----------------	
	const size_t len = 6;
	int arr1[len] = {1,2,3,4,5,6};
	int arr2[len] = {1,2,3,4,5};

	for(size_t index = 0; index != len; ++index) {
		if(arr1[index]==arr2[index])
			continue;
		else {
			cout << "These two arrays are not equal." << endl;
			return -1;
		}
	}
	cout << "These two arrays are equal." << endl;
----------------------------------------*/

/*-------------using vector------------*/

	typedef vector<int>::iterator Iterator;
	vector<int> ivec1;
	vector<int> ivec2;
	int num,num2;
	cout << "Enter ivec1:(q to stop)" << endl;
	while(cin >> num) {
		ivec1.push_back(num);
	}
	
	for(Iterator iter1 = ivec1.begin(); iter1 != ivec1.end(); ++iter1)
		cout << *iter1 << " ";
	cout << endl;
	
//	cin.clear();	cin.sync();
	while(cin.get() == 'q')
		break;
	while(cin >> num2) {
		ivec2.push_back(num2);
	}
	for(Iterator iter2 = ivec2.begin(); iter2 != ivec2.end(); ++iter2)
		cout << *iter2 << " ";
	cout << endl;


	return 0;
}



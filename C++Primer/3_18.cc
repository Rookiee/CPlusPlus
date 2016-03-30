#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main() {
	vector<int> ivec(5,0);
	typedef vector<int>::iterator Iterator;
	int num;
	for(Iterator iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cin >> num;
//		ivec.push_back(num);
		*iter = num;
	}

	for(vector<int>::const_iterator const_iter = ivec.begin(); const_iter != ivec.end(); ++const_iter) {
		cout << *const_iter * 2 << " ";
	}

	cout << endl;
	return 0;
}


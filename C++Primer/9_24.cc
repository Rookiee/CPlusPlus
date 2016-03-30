#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec;
	for(vector<int>::size_type index = 0; index != 5; ++index)
		vec.insert(vec.begin(),index);
	if(!vec.empty()) {
	cout << vec[0] << endl;
	cout << vec.at(0) << endl;
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	int a[] = {1,2,3,4,5,7,8};
	vector<int> vec(a, a+sizeof(a)/sizeof(int));
	for(vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); ++iter)
	cout << *iter << " ";

	cout << endl;
}


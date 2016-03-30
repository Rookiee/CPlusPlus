#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

int main() {
	const size_t len = 10;
	int arr[len];
	for(size_t index = 0; index != len; index++)
		arr[index] = size_t(index);

	for(size_t index = 0; index != len; index++)
		cout << arr[index] << " ";
	cout << endl;
	return 0;
}

		

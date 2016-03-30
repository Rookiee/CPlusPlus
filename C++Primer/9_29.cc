#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {
	const size_t LEN = 10;
	vector<int> ivec;
	cout << "size: " << ivec.size() << "; capacity: " << ivec.capacity()
	<< "; reserve: " << ivec.capacity()-ivec.size()  << endl;
	for(size_t i = 0; i<10;++i) {
		ivec.push_back(i);
		cout << "size: " << ivec.size() << "; capacity: " << ivec.capacity()
			<< "; reserve: " << ivec.capacity()-ivec.size() << endl;
	}
	return 0;
}

		

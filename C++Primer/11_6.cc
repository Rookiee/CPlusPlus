#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
int main() {
	int ai[] = {1,2,3,4,5,6};
	vector<int> ivec(ai, ai+sizeof(ai)/sizeof(int));
	fill_n(ivec.begin(), ivec.size(),0);
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << * iter << endl;
	}
	return 0;
}


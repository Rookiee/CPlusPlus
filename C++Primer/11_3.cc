#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	int ai[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> ivec(ai, ai+10);
	int cnt = accumulate(ivec.begin(), ivec.end(), 0);
	cout << cnt << endl;
	return 0;
}


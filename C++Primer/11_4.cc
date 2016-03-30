#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	double ai[] = {1,2.4,3.3,4,5.7,6,7,8,9,10};
	vector<double> ivec(ai, ai+10);
	double cnt = accumulate(ivec.begin(), ivec.end(), double(0));
	cout << cnt << endl;
	return 0;
}


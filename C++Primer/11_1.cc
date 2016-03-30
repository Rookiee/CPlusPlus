#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main() {
	int ai[10] = {1,2,3,1,2,3,1,2,3,1};
	vector<int> vec(ai,ai+10);
	int cnt = count(vec.begin(), vec.end(), 1);
	cout << cnt << endl;
	return 0;
}


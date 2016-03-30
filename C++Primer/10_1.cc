#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef pair<string, int> Pair;

int main() {
	vector<Pair> test;
	Pair nameAge;
	while( cin >> nameAge.first >> nameAge.second) {
		test.push_back(nameAge);
	}

	for(vector<Pair>::iterator iter = test.begin(); iter != test.end(); ++iter) {
		cout << (*iter).first << " " << (*iter).second << endl;
	}

	return 0;
}


#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string,int> wordCount;
	string word;
	while(cin >> word) {
		++wordCount[word];
	}

	for(map<string,int>::iterator iter = wordCount.begin(); iter != wordCount.end(); ++iter) {
		cout << iter->first;
		cout << " " << iter->second << endl;
	}

	return 0;
}


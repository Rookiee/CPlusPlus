#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
	map<string, int> wordCount;
	string word;
	while (cin >> word) {
		pair<map<string,int>::iterator,bool> ret = wordCount.insert(make_pair(word,1));
		if(!ret.second)
			++ret.first->second;
	}
	for(map<string,int>::iterator iter = wordCount.begin(); iter != wordCount.end(); ++iter){
//		cout << (*iter).first.first; 
		cout << iter->first;
//		cout  << " " << iter->second << endl;
		cout << " " << iter->second << endl;
	}

	return 0;
}


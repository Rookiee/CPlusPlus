#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

void restricted_wc(vector<string> strVec, map<string, int> &wordCount) {
	//create a set of excluded words
	set<string> excluded;
	for(vector<string>::iterator it = strVec.begin(); it != strVec.end(); ++it) {
		excluded.insert(*it);
	}

	string word;
	cout << "Input some words to count the words in wordCount(map)" << endl;
	cin.clear();

	while(cin >> word) {
		if(!excluded.count(word) )
			++wordCount[word];
	}
}

int main() {
	cout << "Input some words to vector<string, int> excluded " << endl;
	vector<string> excludedVec;
	string excludedWord;
//	map<string, int> excludedWord;
	while(cin >> excludedWord)
		excludedVec.push_back(excludedWord);
	restricted_wc(excudedVec, wordCount);

	//show out the map::wordCount
	cout << "\n\tShow out the map:wordCount: " << endl;
	for(map<string, int >::iterator it=wordCount.begin(); it != wordCount.end(); ++it) {
		cout << "The word'" << it->first << "'appers for " << it->second << "times." << endl;
	}

	return 0;
}




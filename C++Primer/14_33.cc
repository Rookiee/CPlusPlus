#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class GT_cls {
private:
	std::string givenWord;
public:
	GT_cls(const std::string &g = " ") : givenWord(g) {}
	
	bool operator() (const std::string &s) { return s > givenWord; }
};

int main() {
	using namespace std;
	cout << "Input words:" << endl;
	vector<string> text;
	string word;
	while(cin >> word) {
		text.push_back(word);
	}
	cin.clear();
//	cin.sync();

	cout << "Input a givenword: " ;
	string givenWord;
	cin >> givenWord;
	vector<string>::iterator iter = find_if(text.begin(), text.end(), GT_cls(givenWord));
	if( iter != text.end() )
		cout << "The first word in the text you input, which is bigger than the given word is: " << *iter << endl;
	return 0;
}


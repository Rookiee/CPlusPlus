#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;

int main() {
	vector<string> text;
	string word;
	while(cin >> word) {
		if(word[0] == 'q')
			break;
		text.push_back(word);
	}
	for(vector<string>::size_type i = 0; i!= text.size(); ++i) {
		for(string::size_type j=0;j != text[i].size(); j++) {
			text[i][j] = toupper(text[i][j]);
		}
	}
	for(vector<string>::size_type i = 0; i!= text.size();++i) {
		cout << text[i] << " ";
		if(i == 7)
			cout << endl;
	}
	cout << endl;
	return 0;
}

	

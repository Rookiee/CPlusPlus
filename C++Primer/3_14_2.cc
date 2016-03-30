#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
	string word;
	vector<string> text;

	while(cin >> word) {
		if(word[0] == 'q')
			break;
		text.push_back(word);
	}

	for(vector<string>::iterator iter = text.begin(); iter != text.end(); ++iter) {
		for(string::size_type i = 0; i != (*iter).size(); i++) {
		(*iter)[i] = toupper((*iter)[i]);
		}
	}
	unsigned cnt = 0;
	for(vector<string>::const_iterator iter = text.begin();iter != text.end();iter++ ) {
		
			cout << *iter << " ";
			cnt++;
		if(cnt % 8 == 0)
			cout << endl;
	}
	cout << endl;


	return 0;
}






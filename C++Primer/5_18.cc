#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
	vector<string> svec;
	string str;
	while(cin>>str) {
		string * ps = new string;
		*ps = str;
		svec.push_back(str);
	}
	vector<string>::iterator iter = svec.begin();
	while(iter != svec.end()) {
		cout << **iter << (**iter).size() << endl;
		iter ++;
	}


	iter = svec.begin();
	while(iter!=svec.end()) {
		delete *iter;
		iter++;
	}

	return 0;
}




#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> svec;
	string str;
	while(cin >> str) 
		svec.push_back(str);

//	vector<string>::const_iterator iter = svec.begin();
	for(vector<string>::const_iterator iter = svec.begin();iter != svec.end();++iter) {
		cout << *iter;
		if(iter != svec.end()-1) 
			cout << " ";
	}
	cout << "aaa" << endl;
	return 0;
}


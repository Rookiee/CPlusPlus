#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<char> vstr;
	char ch;
	while(cin >> ch)
		vstr.push_back(ch);

	string str(vstr.begin(), vstr.end());
	cout << str << endl;
	return 0;
}


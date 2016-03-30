#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

typedef list<char *>::iterator liIter;
typedef vector<string>::iterator veIter;

int main() {
	const size_t LEN = 4;
	char *arr[LEN] = {
			"Hello",
			"World",
			"Ni",
			"Hao" };
	list<char *> listChar(arr,arr+LEN);

	for(liIter iter = listChar.begin(); iter != listChar.end(); ++iter) {
		cout << *iter;
		if(iter != --listChar.end()) cout << " ";
	}
	
	cout << endl;

	vector<string> vecStr;
	vecStr.assign(listChar.begin(),listChar.end());
	
	cout << "vector of string: " << endl;
	for(veIter iter = vecStr.begin(); iter != vecStr.end(); ++iter) {
		cout << *iter;
		if(iter != --vecStr.end()) cout << " ";
	}
	return 0;
}



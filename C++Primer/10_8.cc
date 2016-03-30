#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string,int> map1;
	
	map<string,int>::iterator iter = map1.begin();
	cout << iter->first << endl;
//	iter->first = "ccc";
	iter->second = 9;
	cout << iter->second << endl;
	return 0;
}


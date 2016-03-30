#include <iostream>
#include <list>
#include <deque>
#include <string>

using namespace std;
typedef list<string>::iterator iterList;
typedef deque<string>::iterator iterDeque;

int main() {
	const size_t LEN = 4;
	string a[LEN] = {
			"Hello",
			"World",
			"Ni",
			"Hao" };
		
	deque<string> deStr(a,a+LEN);
	list<string> liStr(a,a+LEN);
	cout << "Enter the string you want to delete: ";
	string str;
	cin >> str;
/***********DEQUE***************/
/*
	iterDeque deIter;
	deIter = find(deStr.begin(),deStr.end(),str);
	if( *deIter == str )
		deStr.erase(deIter);
	else {
		cout << "No matching" << endl;
		return 0;
	}
*/
	/* test */
/*
	for(deIter = deStr.begin(); deIter != deStr.end(); ++deIter) {
		cout << *deIter;
		if(deIter != --deStr.end()) cout << " ";
	}
	cout << endl;
*/
/*********List******************/

	iterList liIter;
	liIter = find(liStr.begin(),liStr.end(),str);
	if( *liIter == str )
		liStr.erase(liIter);
	else {
		cout << "No matching" << endl;
		return 0;
	}

	/* test */
	for(liIter = liStr.begin(); liIter != liStr.end(); ++liIter) {
		cout << *liIter;
		if(liIter != --liStr.end()) cout << " ";
	}
	cout << endl;
	return 0;
}

	

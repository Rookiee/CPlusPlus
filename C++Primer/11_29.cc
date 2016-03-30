#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
typedef list<string>::iterator Iter;
bool isShorter(const string &s1, const string&s2) {
	return s1.size() < s2.size();
}

bool GT6(const string &s) {

	return s.size() > 6;
}
/*
void print(list<string> &strList) {
	for(Iter iter = strList.begin(); iter != strList.end(); ++iter) {
		cout << *iter ;
		if(iter != --strList.end() ) cout << " ";
	}
}
*/

int main() {
	string a[]= { "compare", "helloworld","seen","compare","five","five"};
	list<string> strList(a,a+6);
/*   print out the original list ***/
	cout << "The original list is: " << endl;
	for(Iter iter = strList.begin(); iter != strList.end(); ++iter) {
		cout << *iter ;
		if(iter != --strList.end() ) cout << " ";
	}
	cout << endl;	

/*      sort the list  */
	strList.sort();
	cout << "The sorted list is: " << endl;
	for(Iter iter = strList.begin(); iter != strList.end(); ++iter) {
		cout << *iter ;
		if(iter != --strList.end() ) cout << " ";
	}
	cout << endl;	


/*    unique the list: */
	cout << "After the unique operation: " << endl;
	strList.unique();
	for(Iter iter = strList.begin(); iter != strList.end(); ++iter) {
		cout << *iter ;
		if(iter != --strList.end() ) cout << " ";
	}
	cout << endl;

/*  count the number of word which are greater than or equal to 6 */
	list<string>::size_type cnt = count_if(strList.begin(), strList.end(),GT6);
	cout << cnt << "words BINGO" << endl;
	cout << endl << "DONE" << endl;
	return 0;
}


#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {
	string s1,s2;
/*
	cin >> s1 >> s2;
	string s3;
	s3 = s1 + s2;
*/
	getline(cin,s1);
	getline(cin,s2);
	string s3;
	s3 = s1 +" " +  s2;
	cout << s3 << endl;
	
	return 0;
}


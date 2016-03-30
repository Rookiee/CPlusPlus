#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string s1("Bye_Bye");
	string s2("Helloly");
	if(s1 == s2) 
		cout << "These two strings are equal!" << endl;
	else if (s1 > s2) 
			cout << s1 << " is larger." << endl;
		else
			cout << s2 << " is larger." << endl;
	if(s1.size() == s2.size())
			cout << "These two string have the same lenght." << endl;
	else if (s1.size() > s2.size()) {
			cout << s1 << " is longer" << endl;
			cout << s2 << " is shorter" << endl;
		}

	return 0;
}



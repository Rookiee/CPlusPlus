#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	string s1;
	while(getline(cin,s1)) {
//	getline(cin,s1);
		for(string::size_type index = 0; index != s1.size();index++) {
			if(ispunct(s1[index])) {
				for(string::size_type newIndex = index; newIndex < s1.size(); newIndex++)
				/*---Key Point---*/
					s1[newIndex] = s1[newIndex+1];		
			}
		}
		cout << s1 << endl;
		cin.clear();
		cin.sync();
		cout << "Enter another string: " << endl;
	}	
	return 0;
}

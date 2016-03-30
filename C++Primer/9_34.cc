#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cout;
using std::endl;
typedef string::iterator Iterator;

int main() {
	string str("Welcome to Bejing.");

/*
	for(Iterator iter = str.begin(); iter != str.end(); ++iter) {
		*iter = toupper(*iter);
	}
*/



	Iterator iter = str.begin();
	while(iter != str.end()) 
		*iter++ = toupper(*iter);

/*
	for(Iterator iter = str.begin(); iter != str.end(); ++iter) {
		if(islower(*iter))
			*iter -= 32;
	}
*/
	cout << str << endl;
	return 0;
}
	

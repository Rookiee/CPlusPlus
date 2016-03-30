#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main() {
	string str("Welcome to BeijingI");
	string::iterator iter = str.begin();
	while(iter != str.end() ) {
		if(isupper(*iter))
			str.erase(iter);
		else
			++iter;
	}
	cout << str << endl;
	return 0;
}


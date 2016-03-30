#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;
int main() {
/*----------using Library strings -----------
	string str1 = "Hello.";
	string str2 = "Hello.";

	if(str1 > str2)
		cout << str1 << " is larger." << endl;
	if(str1 < str2)
		cout << str2 << " is larger." << endl;
	else
		cout << str1 << " and " << str2 << " is equal." << endl;
--------------------------------------------*/

/*----------using C-style strings ------------*/
	char arr1[] = "Hello World.";
	char *arr2 = "Hello.";
	if(strcmp(arr1,arr2) > 0)
		cout << arr1 << " is larger." << endl;
	if(strcmp(arr1,arr2) < 0)
		cout << arr2 << " is larger." << endl;
	else
		cout << arr1 << " and " << arr2 << " are equal." << endl;


	return 0;
}

	

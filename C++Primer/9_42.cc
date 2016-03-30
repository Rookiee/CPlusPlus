#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


int main() {
	string word;
	const stack<string>::size_type tsize = 3;
	stack < string, vector<string> > strStack;
	while(cin >> word) {
		if(strStack.size() == tsize || strStack.size() > tsize) {
			for(stack<string>::size_type i = strStack.size(); i >= 0 ;--i)
				strStack.pop();
		}
	
		else {
			if(strStack.size() != tsize)
				strStack.push(word);
		}
	}

	while(! strStack.empty()) {
		cout <<	strStack.top() << endl;
		strStack.pop();
	};	
			
	return 0;
}
 

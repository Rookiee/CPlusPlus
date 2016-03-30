#include <iostream>
#include <string>
//#include <vector>
#include <list>

using namespace std;

int main() {
//    vector<string> svec;
	list<string> svec;
    string str;
    while(cin >> str)
        svec.push_back(str);

//  vector<string>::const_iterator iter = svec.begin();
//    for(vector<string>::const_iterator iter = svec.begin();iter != svec.end();++iter) {
	for(list<string>::const_iterator iter = svec.begin(); iter != svec.end();++iter) {
        cout << *iter;
        if(iter != svec.end())
            cout << " ";
    }
    cout << "aaa" << endl;
    return 0;
}


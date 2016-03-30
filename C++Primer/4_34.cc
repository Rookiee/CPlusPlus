#include <iostream>
#include <vector>
#include <cstring>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;

//typedef vector<char>::iterator Iterator;

int main() {
	vector<string> svec;
	string word;
	while(cin >> word){
		if(word[0] == 'q')
			break;
		svec.push_back(word);
	}

//	unsigned numOfArr = svec.size();
	char **p = new char*[svec.size()];
	size_t i = 0;
//	for(unsigned i = 0; i != numOfArr; ++i) {
	for(vector<string>::iterator iter = svec.begin(); iter != svec.end(); ++iter,++i) {
		char * tmp = new char[svec.size()+1];
		strcpy(tmp,(*iter).c_str());
		p[i] = tmp;
//		delete [] tmp;
	}

	cout << "Content of vector: " << endl;
	for(vector<string>::iterator iter2 = svec.begin(); iter2 != svec.end(); ++iter2) 
	cout << *iter2 << endl;

	cout << "Content of character array: " << endl;
	for(size_t j = 0 ; j!= svec.size(); ++j)
		cout << p[j] << endl;

	for(i=0; i!= svec.size(); ++i)
		delete [] p[i];

	delete [] p;
	return 0;
	
}


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<string>::iterator Iterator;
istream &r (istream & is) {
    string sval;
    while(is >> sval , !is.eof() ) {
        if(is.bad() )
            throw runtime_error(" IO stream corrupted.");
        if(is.fail() ) {
            cerr << "Bad data, try agais: ";
            is.clear ();
            is.setstate(istream::eofbit);
            continue;
        }
        cout << sval << endl;
    }
    is.clear();
    return is;
}

int main() {
	vector<string> files;
	string name;
	while(cin >> name) {
		if(name[0] == 'q')
			break;
		files.push_back(name);
	}
	Iterator iter = files.begin();
	ifstream input;
	while(iter != files.end()) {
		input.open(iter->c_str());
		if(!input) {
			cerr << "error continue the next file" << endl;
			input.clear();
			++iter;
			continue;
		}
		r(input);
		input.close();
		input.clear();
		++iter;
	}
	return 0;
}





#include <iostream>
#include <fstream>
#include <string>

using  namespace std;
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
	string fname;
	cout << "Enter name: ";
	cin >> fname;
	ifstream readfile;
	readfile.open(fname.c_str());
	if(!readfile) {
		cout << "error" << endl;
		return -1;
	}
	r(readfile);

	return 0;
}

		
				



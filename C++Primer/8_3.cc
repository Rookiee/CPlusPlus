#include <iostream>
using namespace std;
istream &r (istream & in) {
	int ival;
	while(in >> ival , !in.eof() ) {
		if(in.bad() )
			throw runtime_error(" IO stream corrupted.");
		if(in.fail() ) {
			cerr << "Bad data, try again: ";
			in.clear ();
			in.setstate(istream::eofbit);
			continue;
		}
		cout << ival << endl;
	}
	in.clear();
	return in;
}

int main() {
	r(cin);
	
	return 0;
}



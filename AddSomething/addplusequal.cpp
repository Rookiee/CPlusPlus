#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <fstream>
#include "Open_File.h"

using namespace std;


int main(int argc, char * argv[]) {
	if(argc != 2) {
		cout << "error" << endl;
		return -1;
	}

	std::deque<string> strDeque;
	ifstream infile;
	open_file(infile, argv[1]);
	string s;
// Read line by line, and store each line in s,
// then move forward to the next line
	while(getline(infile,s)) {
//	add "LIBS += /usr/local/lib/" to the head of each line
		strDeque.push_front("LIBS += /usr/local/lib/"+s);
	}

	ofstream ofile;
	ofile.open("new.txt",ios_base::out);
	

		
	

	for(deque<string>::iterator iter = strDeque.begin(); iter != strDeque.end(); ++iter) {
		ofile << *iter << endl;
		
	}

	infile.close();
	ofile.close();

	return 0;

}	

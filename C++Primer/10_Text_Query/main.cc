#include "TextQuery.h"
#include <iostream>
#include <cstdlib> // for exit
#include "Open_File.h"
using namespace std;

void print_results(const set<TextQuery::lineNo> & locs, const string &sought, const TextQuery &file);
using namespace std;
int main(int argc, char * argv[]) {
	ifstream inFile;
	if(argc < 2 || !open_file(inFile,argv[1])) {
		cerr << "No input file." << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.ReadFile(inFile);
	while(true) {
		cout << "Enter word to search , or q to quit: " ;
		string s;
		cin >> s;
		if( !cin || s == "q") break;
		set<TextQuery::lineNo> locs = tq.RunQuery(s);
		print_results(locs, s, tq);
	}

	return 0;
}

void print_results(const set<TextQuery::lineNo> & locs, const string &sought, const TextQuery &file) {
	typedef set<TextQuery::lineNo> line_nums;
	line_nums::size_type size = locs.size();
	cout << '\n' << sought << " occurs " << size << " " << endl;

	line_nums::const_iterator it = locs.begin();
	for( ; it != locs.end(); ++it) {
		cout << "\t (line " << (*it) + 1 << ") "
			<< file.TextLine(*it) << endl;
	}
}

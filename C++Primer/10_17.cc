#include <iostream>
#include <sstream> //istringstream 
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	map<string, string> trans_map;
	string key, value;
	if( argc != 3)
		throw runtime_error("wrong number of arguments.");
//	ifstream map_file;
//	if( ! map_file.open(map_file, argv[1])
	ifstream map_file(argv[1]);
//	if( ! map_file.open(argv[1])
	if( ! map_file.is_open())
		throw runtime_error("No such file.");
	while(map_file >> key >> value) 
		trans_map.insert(make_pair(key,value));

	ifstream input(argv[2]);
//	if( ! input.open(input,argv[2])
	
	if( ! input.is_open())
		throw runtime_error("Fail to open such file.");

	string line;
	while(getline(input,line) ){
		istringstream stream(line);
		
		string word;
		bool firstword = true;
		while(stream >> word) {
		map<string,string>::iterator iter = trans_map.find(word);
		if(iter != trans_map.end())
			word = iter->second;
		if(firstword)
			firstword = false;
		else
			cout << " ";
		cout << word;
		}
	}
	cout << endl;
	return 0;
}


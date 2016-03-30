#ifndef OPEN_FILE_H
#define OPEN_FILE_H

#include <iostream>
#include <fstream>

std::ifstream& open_file(std::ifstream &in, const std::string &file) {
	in.close();	//close in case it was already open
	in.clear(); // clear any existing errors
	// if the open fails, the stream will be in an invalid state
	in.open(file.c_str());	//open the file we were given
	return in;	// condition state is good if open succeeded
}

#endif

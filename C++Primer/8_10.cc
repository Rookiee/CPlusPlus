#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

int main() {
    ifstream input;
    string fileName;
    cout << "Enter a file name: ";
    cin >> fileName;
    input.open(fileName.c_str());
    if(!input) {
        std::cerr << "!!!" << endl;
        return -1;
    }
    vector<string> fileline;
/* reading contents for the file, 
	key poing of the code
							*/
/* a line as an input */
//    while(getline(input, fileName)){
//       fileline.push_back(fileName);
//    }

/* word by word */
	while(input >> fileName)
		fileline.push_back(fileName);
    input.close();

    vector<string>::iterator iter = fileline.begin();
    while(iter != fileline.end()) {
        cout << *iter << endl;
        ++iter;
    }

    return 0;
}


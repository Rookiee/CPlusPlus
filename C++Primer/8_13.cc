#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

using std::ofstream;

ofstream &open_file(ofstream & outFile,const string &fileName) {
//	ofstream outFile;
	outFile.close();
	outFile.clear();
	outFile.open(fileName, ofstream::app);
	return outFile;
}

int main() {
	string fileName;
	cout << "enter file name: ";
	cin >> fileName;
	ofstream ofile;
	if(!open_file(ofile,fileName)){
		cerr << "fail";
//		exit(1);
		return -1;
	}
	std::ifstream ifile("111.txt");
	int n1,n2,n3;
	ifile >> n1 >> n2 >> n3;
	ifile.close();
	ifile.clear();
	ofile << endl << n1+n2+n3 << endl;
	ofile.close();
	return 0;
}

	
	




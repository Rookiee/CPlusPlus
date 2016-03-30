#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	if(argc < 2) {
		std::cerr << "At least three arguments." << endl; 
		return -1;
	}
	size_t l1 = strlen(argv[1]);
	size_t l2 = strlen(argv[2]);
	char * c = new char[l1+l2+1];
	char * p = c; 	
	
	strcpy(c,argv[1]);
	strcat(c,argv[2]);
	

	while(p != (c+l1+l2+1) ) {
		cout << *p++ ;
	}

/*
	for(int i=0; i!=l1+l2+1; i++)	
		cout << *(p+i);
*/

	cout << endl;
	delete [] c;
	return 0;
	

}

		
		

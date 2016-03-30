#include <iostream>
#include <list>
#include <vector>
using namespace std;
typedef list<int>::iterator iterList;
typedef vector<int>::iterator iterVec;
int main() {
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	list<int> iList(ia,ia+sizeof(ia)/sizeof(int));
	vector<int> iVec(ia,ia+sizeof(ia)/sizeof(int));
	int *p = ia;
/*
	for(size_t i=0;i<sizeof(ia)/sizeof(int);++i)
		iList.push_back(ia[i]);
*/

/*
	while(p != ia + sizeof(ia)/sizeof(int)-1 ){
		iList.push_back(*p);
		++p;
	}
*/
	for(iterVec iter = iVec.begin(); iter != iVec.end(); ++iter) {
		if(*iter % 2 ==0 )
			iVec.erase(iter);
	}

	for(iterList iter = iList.begin(); iter != iList.end(); ++iter) {
		if(*iter % 2 != 0)
			iList.erase(iter);
	}
	cout << "the new list: " << endl;
	for(iterList iter = iList.begin(); iter != iList.end();++iter) {
		cout << *iter ;
		if(iter != --iList.end()) cout << " ";
	}
	cout << endl << "The new vector: " << endl;
	for(iterVec iter = iVec.begin(); iter != iVec.end(); ++iter) {
		cout << *iter;
		if(iter != --iVec.end()) cout << " ";
	}
	cout << endl;
	
	return 0;
}

	

	
	

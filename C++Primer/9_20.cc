#include <iostream>
#include <list>
#include <vector>

using namespace std;
int main() {
	int num;
	list<int> iList;
	while(cin >> num) {
		if(num == 9999)
			break;
		iList.push_back(num);
	}


	vector<int> iVec;
	while(cin >> num) {
		if (num==9999)
			break;
		iVec.push_back(num);
	}
	bool bSame = false;
	if(iList.size() != iVec.size())
		bSame = false;
	else {
		list<int>::iterator liter = iList.begin();
		vector<int>::iterator viter = iVec.begin();
		while( liter != iList.end() ) {
			if( *liter != *viter ) {
				bSame = false;
				break;
			}
			++liter; ++viter;
			bSame = true;
		}
	}
	if(bSame)
		cout << "The same" << endl;
	else
		cout << "Not the same." << endl;
}

				 
		

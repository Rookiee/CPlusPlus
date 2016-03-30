#include <iostream>
#include <vector>

using namespace std;
typedef vector<int>::iterator Iterator;
bool findint(Iterator beg, Iterator end, int n);

int main() {
	int a[5] = {1,2,3,4,5};
	vector<int> ivec(a,a+5);
	Iterator beg = ivec.begin();
	Iterator end = ivec.end();
	if(findint(beg,end,199))
		cout << "BINGO" << endl;
	else
		cout << "NONE" << endl;
	findint(end,beg,3);
	return 0;
}

	
	

bool findint(Iterator beg, Iterator end, int n) {
	if(beg > end)
		cout << "iterator error." << endl;
	while(beg != end) {
		if(*beg == n){
//			cout << "BINGO" << endl;
			return 1;
		}
		beg++;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<int>::iterator Iterator;

Iterator findint( Iterator beg, Iterator end, const int n);

int main() {
	int a[5] = {1,2,3,4,5};
	vector<int> ivec(a,a+5);
	Iterator beg = ivec.begin();
	Iterator end = ivec.end();
	vector<int>::const_iterator Iter;
	Iter = findint(beg,end,13);
	cout << *Iter << endl;
	return 0;
}


Iterator findint( Iterator beg, Iterator end, const int n) {
    if(beg > end)
        cout << "iterator error." << endl;
    while(beg != end) {
        if(*beg == n){
//          cout << "BINGO" << endl;
            return beg;
        }
        beg++;
    }
	cout << "NONE" << endl;
	exit(1);
//    return NULL;
}

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
typedef vector<int>::iterator Iterator;
int main() {
	vector<int> ivec(10,0);
//	vector<int> ivec;
	if(!ivec.empty()) {
		Iterator iter = ivec.end();
		cout << "This vector is not empty."
			<< "The last element is " << *(iter-1) << endl;
	}
	else 
		cout << "This vector is empty." << endl;
	int num;
	for(Iterator iter = ivec.begin(); iter != ivec.end(); ++ iter) {
		cin >> num;
		*iter = num;
	}

	for(vector<int>::const_iterator const_iter = ivec.begin(); const_iter != ivec.end(); ++ const_iter)
		cout << *const_iter << " ";
	
	cout << endl;	
	for(Iterator iter = ivec.begin(); iter != ivec.end(); ++iter) {
		if(iter == ivec.end()-1)
			break;
		cout << *iter + *(iter+1) << endl;
	}

	cout << endl;
/*	for(const_iter1 = ivec.begin(), const_iter2 = ivec.end()-1; const_iter1 != const_iter2; ++const_iter1, --const_iter2) {
*/
/*
	vector<int>::const_iterator const_iter2;
	for(vector<int>::const_iterator const_iter1 = ivec.begin(), const_iter2 = ivec.end()-1;const_iter1 != const_iter2; ++ const_iter1){

			cout <<	*const_iter1 + *const_iter2 << endl; 
			--const_iter2;
	}
		
*/		
	vector<int>::iterator iterf, itere;
	iterf = ivec.begin();
	itere = ivec.end();
	cout << *iterf << " " <<*(itere-1) << endl;
	while(iterf != itere) {
		cout << *iterf + *(itere-1) << endl;
		iterf++;
		itere--;
		if(iterf == itere)
			break;
	}




	return 0;
}
	

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> ivec1;
	int num, sum = 0;
	if(!ivec1.empty()){
		cout << "The vector container is not empty. "
			<< "The old elements are:" << endl;
		for(vector<int>::size_type i=0; i!= ivec1.size();++i)
			cout << ivec1[i];
		cout << endl << "The last element is " 
			<< ivec1[ivec1.size()-1] << endl;
	}
	else
		cout << "The container is empty." << endl;
		
	for(vector<int>::size_type i = 0;i != 10;i++) {
			cin >> num;
			ivec1.push_back(num);
			cin.clear();
			cin.sync();
			
	}
	for(vector<int>::size_type i = 0;i != 10;i++) {
			cout << ivec1[i] << " ";
	}
	cout << endl;
	for(vector<int>::size_type i = 0; i!=10;i++) {
			sum += ivec1[i];
	}
	cout << "The sum is " << sum << endl;
	if(ivec1.size()%2 == 0) {
	for(vector<int>::size_type i=0,j = ivec1.size()-1; i != (ivec1.size()/2);++i,--j) {
			cout << ivec1[i] + ivec1[j] << endl;
	}	
		}
	return 0;
}


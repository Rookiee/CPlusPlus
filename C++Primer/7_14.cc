#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

typedef vector<double>::iterator Iterator;
double Sum(Iterator beg, Iterator end);
//double Sum(vector<double>::iterator , vector<double>::iterator);

int main() {
	vector<double> dvec;
	double num=0;
	while(std::cin >> num) 
		dvec.push_back(num);
	double sum = 0;
	Iterator beg = dvec.begin();
	Iterator end = dvec.end();

	sum = Sum(beg,end);

	cout << "sum = " << sum << endl;
	return 0;
}

double Sum(Iterator beg, Iterator end) {
	double sum = 0;
	while(beg != end) 
		sum += *beg++;
	return sum;
}


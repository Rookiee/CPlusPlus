#include <iostream>
#include <cstddef>
using std::endl;
using std::cout;
using std::cin;
int sum1(int *, size_t );
int sum2(int *, int *);
int sum3(int *);

int main() {
	int arr[6] = {1,2,3,4,5,6};
	cout << sum1(arr,6) << " " 
		<< sum2(arr,arr+6) << " " << sum3(arr) << endl;	
	return 0;
}

int sum1(int * a, size_t n) {
	int sum = 0;
	for(size_t i = 0; i != n; i++)
		sum += *(a+i);
	return sum;
}

int sum2(int * beg, int * end) {
	int sum = 0;
	while( beg != end) {
		sum += *beg++;
	}
	return sum;
}

int sum3(int * a) {
	int sum  = 0;
	while(*a != 6 ) {
		sum += *a++;
	}
	return sum;
}


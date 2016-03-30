#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned);
int main()
{
//    cout << "Enter a number: ";
    unsigned n;
    cout << "Enter an non-negtive number: ";
    while(cin>>n && cin.good()) { //using cin.good()
        if(isPrime(n)) {
            cout << n << " is a prime.\n";
            /**********************/
            cin.clear();
            cin.sync();
            cout << "Enter another number: ";
            continue;
        }
        else {
            cout << n << " is not a prime.\n";
            cout << "Enter another number: ";
            continue;
        }
    }


    return 0;
}



bool isPrime(unsigned n) {
    unsigned i = 2;
    unsigned tmp = (unsigned)sqrt(n);
    while(i< tmp) {
        if( n % i == 0)
            return false;
        i++;
    }
    return true;
}

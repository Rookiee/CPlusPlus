#include <iostream>
#include <cmath>
bool isPrime(unsigned n);

using namespace std;

int main()
{
    unsigned int n;
    unsigned j = 0;
    unsigned a[50];
    unsigned t;
    cout << "Enter a number n: ";
    while(cin >> n && n >1 && cin.good()) {
        if(isPrime(n)){
            cout << n <<"=" << n << endl;
            break;
        }
        for(unsigned i = 2;i<n;i++){
            if(n % i == 0) {

                a[j] = i;
                j++;
                t = j;
            }
        }
        cout << n << "=";
        for(j=0;j<t-1;j++){
            cout << a[j] << "*" << a[j+1];
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

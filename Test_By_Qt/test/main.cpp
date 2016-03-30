#include <iostream>

using namespace std;

int main() {
    int i = 5;
    const int * a = &i;
//    int * const a = &i;
//    *a = 8;
    * (const_cast<int *>(a)) = 8;
    cout << *a << endl;
    cout << i << endl;
    return 0;
}

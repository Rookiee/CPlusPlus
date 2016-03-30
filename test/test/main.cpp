#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

int main() {
    int a = 10;
    int *p = new int();
    p = &a;
    cout << a << endl;
    cout << p << endl;
    int *q = p;
    delete p;
    cout << *q << endl;
    return 0;
}
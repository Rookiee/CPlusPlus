//
//  main.cpp
//  Stack
//
//  Created by XieHaoyang on 10/19/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>
#include "stack.hpp"
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::string;

int main() {
    Stack<std::string> st;
    char ch;
    string po;
    cout << "Enter A to add a purchase order,\n";
    cout << "P to process a PO, or Q to quit.\n";
    while(cin >> ch && std::toupper(ch) != 'Q') {
        while(cin.get() != '\n')
            continue;
        switch(ch) {
                case 'A':
                case 'a':   cout << "Enter a PO number to add: ";
                            cin >> po;
                            if(st.isFull())
                                cout << "Stack is full.\n";
                            else
                                st.push(po);
                            break;
                case 'p':
                case 'P':   if(st.isEmpty())
                            cout << "Stack already empty.\n";
                            else {
                                st.pop(po);
                                cout << "PO#" << po << " popped.\n";
                            }
                            break;
                
        }
        cout << "please enter another: ";
    }
    cout << "DONE.\n";
    return 0;
}

//
//  main.cpp
//  Student
//  包含对象成员的例子，代码重用，string 和 valvarray 是C++类，他们的对象作为Student的私有成员
//  Created by XieHaoyang on 10/17/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>
#include "studentc.h"
using namespace std;

void set(Student & s, int score);

const int pupils = 3;
const int quizzes = 5;

int main(int argc, const char * argv[]) {
    Student ada[pupils] = { Student(quizzes), Student(quizzes), Student(quizzes) };
    int i;
    for(i=0;i<pupils;i++) {
        set(ada[i],quizzes);
    }
    cout << "\nStudent List:\n";
    for(i=0;i<pupils;i++) {
        cout << endl << ada[i];
        cout << "Average: " << ada[i].Average() << endl;
    }
    cout << "Done\n";
    return 0;
}

void set(Student & s, int n) {
    cout << "Enter the student's name: ";
    getline(cin, s);
    cout << "Enter " << n << " quiz scores.\n";
    for(int i=0;i<n;i++)
        cin >> s[i];
    while(cin.get() != '\n')
        continue;
}
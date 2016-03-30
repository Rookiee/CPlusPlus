//
//  main.cpp
//  myCourseManager
//
//  Created by XieHaoyang on 11/23/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>
#include "Course.hpp"
#include "CourseManager.hpp"
#include <string>

using namespace std;
int main() {
    CourseManager test;
//    Course c1("yy");
//    test.AddCourse(c1);
    test.AddCourse("Yuwen");
    cout << test << endl;
    
    return 0;
    
}
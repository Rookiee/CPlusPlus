//
//  CourseManager.hpp
//  myCourseManager
//
//  Created by XieHaoyang on 11/23/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H
//课程列表用vector，每一个元素是一个Course，所以要inlude Course.h
#include "Course.hpp"
#include <vector>

class CourseManager {
private:
    std::vector<Course> vecCourse_;
    
    int FindCourse(std::string &);
    int FindCourse(size_t id);
    
public:
    //使用默认
    CourseManager() {}
    CourseManager(const std::vector<Course> &);
    //get the number of course ( acutally, the number of elements in vector )
    size_t GetNumOfCourse();
    
    //add course into a vector, constructor of Course class is necessary
    void AddCourseByName(std::string&);
    //overload the AddCourse, parameter is Course object
    void AddCourse(Course &);
    
    //remove the latest course
    void RemoveLateCourse();
    
    //remove special course
    //By name
    void RemoveCourse(std::string &);
    //By id
    void RemoveCourse(size_t);
    
    //Print all of the course
    void PrintInfo();
    //Print special course
    void PrintInfo(std::string &);
    //Print special course by id
    void PrintInfo(size_t);
    
    //PrintLongetsName
    void PrintLongest();
    
    friend std::ostream& operator<<(std::ostream &, const CourseManager&);
    
};

#endif




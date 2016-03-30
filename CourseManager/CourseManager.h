#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"

using std::vector;

class CourseManager {
private:
	//Course List by vector<course>
	vector<Course> courseList;

	//根据课程名字查找课程，返回索引下表，否则返回-1
	int FindCourse(const std::string &name);

	//根据ID查找课程，返回课程索引下表，否则返回-1
	int FindCourse(int id);

public:
	//default constructor
	//CourseManager() = default;
	CourseManager() {}

	//constructor: 根据课程vector， 创建CourseManager
	CourseManager(const vector<Course> &);

	//get the number of courses
	unsigned getCourseNum();

	//add course, parameter is name, or course object
	void addCourse(const std::string &name);
	void addCourse(const Course &);

	// delete the last course
	void delLast();


	// delete course, parameter is id or string
	// these two function need to check whether or not the parameter is in the list,
	// so we define two private functions to check if we coud find the element we want
	void delCourse(const int );
	void delCourse(const std::string &);

	//print the course list
	void PrintCourseList();

	//print the course, parameter is id, or name
	void PrintCourse( const int );
	void PrintCourse( const  std::string &);

	//print the longest course
	void PrintLongest();
};
	

#endif	
	

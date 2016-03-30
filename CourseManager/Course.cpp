#include <iostream>
#include <string>
#include "Course.h"

//初始化静态成员变量，默认第一个课程ID为1
int Course::currentId = 1;

//default constructor
Course::Course() {
	id_ = currentId ++;
	name_ = "";
}

//Constructor: Create a new object by a course name(string)
Course::Course(const std::string &name) {
	id_ = currentId++;
	name_ = name;
}

//copy constructor
Course::Course(const Course & course) {
	id_ = course.GetId();
	name_ = course.GetName();
}

//print course information (virtual)
void Course::PrintInfo() const {
	std::cout << "Name: " << id_ << ": " << name_ << std::endl;
}

//friend operator: overload operator <<
std::ostream & operator<<(std::ostream &os, const Course &course) {
	os << "Name: " << course.id_ << ": " << course.name_;
	return os;
}

//friend function, create a new object by input a string(name)
void read(std::istream & in, Course &course) {
	in >> course.name_;
}


	
/* functions for ProjectCourse */

void ProjectCourse::PrintInfo() const {
	std::cout << "Course: " << this->GetId() << ": " << GetName() << ", " << this->GetTag() << std::endl;
}


/* function for JudgeCourse */
void JudgeCourse::PrintInfo() const {
	std::cout << "Course: " << this->GetId() << ": " << GetName()  << ", " << this->GetTime() << std::endl;
}
	

	



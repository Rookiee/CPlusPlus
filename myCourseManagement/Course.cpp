#include "Course.h"

size_t Course::courseId_ = 1;

//Constructor
Course::Course(std::string name) {
	id_ = courseId_ ++;
	name_ = name;
}

//Copy COnstructor
Course::Course(const Course& rhs) {
	id_ = rhs.id_;
	name_ = rhs.name_;
}

//set name
void Course::SetName(const std::string name) {
	name_ = name;
}

std::ostream& operator<<(std::ostream& os, const Course& rhs) {
	os << "Course: " << rhs.id_ << " " << rhs.name_;
	return os;
}


#include "CourseManager.h"
#include <stdexcept>
//构造函数，参数为vector
CourseManager::CourseManager(const vector<Course> &course) {
	for(auto curs = course.begin(); curs != course.end(); ++curs)
		courseList.push_back(*curs);
}

//get the number of course
unsigned CourseManager::getCourseNum() {
	return courseList.size();
}

//add course, parameter is name, or course object
void CourseManager::addCourse(const std::string &name) {
	Course course(name);
	courseList.push_back(course);
}
void CourseManager::addCourse(const Course &course) {
	courseList.push_back(course);
}

//delete the last course
void CourseManager::delLast() {
	try {
		if( !courseList.empty() ){
			courseList.pop_back();
			std::cout << "Delete Done." << std::endl;
		}
		else {
			throw std::runtime_error("Delete error, there is no element in courseList.");
		}
	}

	catch (std::runtime_error err) {
		std::cout << err.what() << std::endl;
	}
}


//delete course, parameter is id or string
void CourseManager::delCourse(const int id){
	int index = FindCourse(id);
	if(index > 0) 
		courseList.erase(courseList.begin() + index);
	else
		std::cout << "Not Found" << std::endl;
}

void CourseManager::delCourse(const std::string & name) {
	int index = FindCourse(name);
	if(index > 0)
		courseList.erase(courseList.begin() + index);
	else
		std::cout << "Not Found" << std::endl;
}
		
//print the course list
void CourseManager::PrintCourseList() {
	std::cout << "Here is Course List: " << std::endl;
	for(auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		std::cout << '\t' << *iter << std::endl;
	}
}

//print the course, parameter is id or name
void CourseManager::PrintCourse(const int id) {
	int index = FindCourse(id);
	if( index > 0 ) {
		std::cout << "Information of ID " << id << ": " ;
		std::cout << courseList[index] << std::endl;
	}
	else
		std::cout << "This ID is not available." << std::endl;
}

void CourseManager::PrintCourse(const std::string & name) {
	int index = FindCourse(name);
	if(index > 0) {
		std::cout << "Information of Course " << name << ": ";
		std::cout << courseList[index] << std::endl;
	}
	else
		std::cout << "This course is not in the courselist." << std::endl;
}

//Print the course with the longest course name
void CourseManager::PrintLongest() {
	int maxLen = 0;
	for(auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		int currentLen = (iter->GetName()).size();
		if(currentLen > maxLen)
			maxLen = currentLen;
	}

	for(auto iter = courseList.begin(); iter != courseList.end(); ++iter) {
		if( (iter->GetName()).size() == maxLen )
			std::cout << *iter << std::endl;
	}
}


/* private operations */
// find the course by course name
int CourseManager::FindCourse(const std::string &name) {
	for(auto i=0; i< courseList.size(); ++i)
		if(courseList[i].GetName() == name)
			return i;
	return -1;
}


//find the course by course id
int CourseManager::FindCourse(const int id) {
	for(auto i = 0; i != courseList.size(); ++i)
		if(courseList[i].GetId() == id)
			return i;
	return -1;
}

	

	

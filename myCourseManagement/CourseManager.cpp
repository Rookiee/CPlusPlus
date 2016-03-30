#include "CourseManager.h"
#include <iostream>
CourseManager:: CourseManager(const std::vector<Course> &vecCourse) {
	for(auto  iter = vecCourse.begin();
		iter != vecCourse.end(); ++iter) {
			vecCourse_.push_back(*iter);
	}
}

/*	
size_t GetNumOfCourse() {

	return this->size();
}
*/


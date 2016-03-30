//
//  CourseManager.cpp
//  myCourseManager
//
//  Created by XieHaoyang on 11/23/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include "CourseManager.hpp"

CourseManager::CourseManager(const std::vector<Course> &vecCourse) {
    for(auto iter = vecCourse.begin(); iter != vecCourse.end(); ++iter) {
        vecCourse_.push_back(*iter);
    }
}

size_t CourseManager::GetNumOfCourse() {
    return vecCourse_.size();
}

void CourseManager::AddCourseByName(std::string &name) {
    Course course(name);
    vecCourse_.push_back(course);
}

void CourseManager::AddCourse(Course & course) {
    vecCourse_.push_back(course);
}

void CourseManager::RemoveLateCourse() {
    if (!vecCourse_.empty())
        vecCourse_.pop_back();
    else {
        std::cout << "No couse" << std::endl;
        exit(EXIT_FAILURE);
    }
}
int CourseManager::FindCourse(std::string & name) {
    int i ;
    for(i = 0; i != vecCourse_.size(); ++i) {
            if( name == vecCourse_[i].GetName())
                return i;
    }
    return -1;
}


int CourseManager::FindCourse(size_t id) {
    int i;
    for(i=0; i != vecCourse_.size(); ++i) {
        if( id == vecCourse_[i].GetId() )
            return i;
    }
    return -1;
}

void CourseManager::RemoveCourse(std::string & name) {
    int loc = FindCourse(name);
    if (loc > 0)
        vecCourse_.erase(vecCourse_.begin() + loc);
    else
        std::cout << "Not Found" << std::endl;
}

void CourseManager::RemoveCourse(size_t id) {
    int loc = FindCourse(id);
    if( loc > 0)
        vecCourse_.erase(vecCourse_.begin()+loc);
    else
        std::cout << "Not Found" << std::endl;
}

void CourseManager::PrintInfo() {
    for(auto iter = vecCourse_.begin(); iter != vecCourse_.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
}

void CourseManager::PrintInfo(std::string & name) {
    int loc = FindCourse(name);
    if(loc>0)
        std::cout << vecCourse_[loc] << std::endl;
    else
        std::cout << "No Course" << std::endl;
}

void CourseManager::PrintInfo(size_t id) {
    int loc = FindCourse(id);
    if(loc >0)
        std::cout << vecCourse_[loc] << std::endl;
    else
        std::cout << "No Course" << std::endl;
}

void CourseManager::PrintLongest(){
    typedef std::vector<Course>::size_type size;
    auto iter = vecCourse_.begin();
    size max = iter->GetName().size();
    for(; iter != vecCourse_.end(); ++iter) {
        if( max < iter->GetName().size())
            max = iter->GetName().size();
    }
    
    for( auto cur = vecCourse_.begin(); cur != vecCourse_.end(); ++cur) {
        if( max == cur->GetName().size() )
            std::cout << *cur << std::endl;
    }
}

std::ostream & operator << (std::ostream& os, const CourseManager& rhs) {
    for( auto iter = rhs.vecCourse_.begin(); iter != rhs.vecCourse_.end(); ++iter) {
        os << *iter << std::endl;
    }
    return os;
}



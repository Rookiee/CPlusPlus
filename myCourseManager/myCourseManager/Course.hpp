//
//  Course.hpp
//  myCourseManager
//
//  Created by XieHaoyang on 11/23/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course {
    
private:
    size_t id_;
    std::string name_;
public:
    Course(std::string name);
    Course(const Course&);
    
    //set and get name
    void SetName(const std::string name);
    std::string GetName() const { return name_; }
    
    // get id
    size_t GetId() const { return id_; }
private:
    static size_t courseId_;
    
    
    
    friend std::ostream& operator<<(std::ostream &, const Course &);
};

#endif





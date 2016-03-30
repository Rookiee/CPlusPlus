#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
/*为了支持自动生成不同的ID，我们定义一个int类型的静态成员变量，
	每次创建新的对象都自动加一 */
	static int currentId; //设置静态变量来唯一生成ID值

/* 为了子类能够访问课程ID及名称，将ID 和 name 设置为protected*/
/*
protected:
	int id_;
	std::string name_;
*/

//以上注释掉data member， 重新定义为private，如需访问，通过成员函数GetId() 和 GetName()
private:
	int id_;
	std::string name_;

public:
	// Constructor without parameter
	Course (); 
	
	//Constructor: Create a new object by a course name
//	Course (const std::string &name) : name_(name) {}
	Course (const std::string &);

	//copy constructor
	Course (const Course &);

	//print course information
	//virutal: because the derived class also needs to use PrintInfo
	//			with the same function name and same parameter
	virtual void PrintInfo() const;

	//return course name
	std::string GetName() const {return name_;}

	//set course name
	void SetName(const std::string & newName) {
		name_ = newName;
	}

	//get course ID
	inline int GetId() const { return id_;}

	//overload operator <<
	friend std::ostream & operator<<(std::ostream &os, const Course &);

	//friend, create a new course by inputing the name of the course
	friend void read(std::istream &, Course&);
};

/*
上述接口中有一个虚函数virtual void PrintInfo() const，之所以这样定义
是因为项目课及评估课对应的子类都含有新的成员需要显示，所以会在继承
Course后重新实现PrintInfo()
*/

/* 项目课：增加了标签 */
class ProjectCourse: public Course {
private:
	std::string tag_;
public:
	// set tag
	inline void SetTag(const std::string &tag) {
		tag_ = tag;
	}

	// in order to provide a method to access the private from outside
	// otherwise, we can not obtain the value of tag_ 
	// get tag
	std::string GetTag() const {
		return tag_;
	}
	//print course information,  PrintInof is virtual in base class
	// with the same function and same parameter
	void PrintInfo() const;
	
};


/* 评估课：增加时间限制 */
class JudgeCourse: public Course {
private:
	unsigned time_;
public:
	inline void SetTime(unsigned time) {
		time_ = time;
	}

	inline unsigned GetTime() const {
		return time_;
	}

	virtual void PrintInfo() const;

};


#endif

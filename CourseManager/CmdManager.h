#ifndef CMDMANAGER_H
#define CMDMANAGER_H

#include <map>
#include <utility>
#include <string>

// for CourseCmd ,,,, enum
#include "Cmd.h" 
// for private data member
#include "CourseManager.h" 

class CmdManager {
private:
	CourseManager manager;
	std::map<CourseCmd, std::string> cmdList;

public:
	// default constructor ?
	CmdManager() = default;

	//Init the course
	void Init();

	//print help information
	void PrintAllHelp() const;

	//print help information, parameter is enum
	void PrintHelp(const CourseCmd cmd) const;

	//process the cmd
	bool HandelCmd(const CourseCmd cmd);

	//Get the CourseManager object
	CourseManager & GetCourseManager() { return manager; }
};

#endif


	
	
	

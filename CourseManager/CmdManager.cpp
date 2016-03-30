#include "CmdManager.h"
#include <iostream>

using std::make_pair;
void CmdManager::Init() {
	manager.addCourse("Linux");
	manager.addCourse("NodeJS");
	manager.addCourse("C++");
	manager.addCourse("Python");
	manager.addCourse("Hadoop");
	manager.addCourse("Ruby");
	manager.addCourse("Java");

	cmdList.insert(make_pair(Cmd_PrintHelp,"Help Info"));
	cmdList.insert(make_pair(Cmd_PrintCourseList, "Course List"));
	cmdList.insert(make_pair(Cmd_PrintCourseNum, "Course Number"));
	cmdList.insert(make_pair(Cmd_PrintLongestName,"Longest Course Name"));
	cmdList.insert(make_pair(Cmd_RemoveLastCourse,"Remove Last Course"));
	cmdList.insert(make_pair(Cmd_Exit,"Exit"));
}

void CmdManager::PrintAllHelp() const {
	std::cout << "Cmd List: " << std::endl;
	for(auto iter = cmdList.begin(); iter != cmdList.end(); ++iter) {
		std::cout << iter->first << ": " << iter->second << std::endl;
	}
}

void CmdManager::PrintHelp(const CourseCmd cmd) const {
	auto iter = cmdList.find(cmd);
	if(iter != cmdList.end())
		std::cout << iter->first << ": " << iter->second << std::endl;
	else
		std::cout << "No Such Command" << std::endl;
}


bool CmdManager::HandelCmd(const CourseCmd cmd) {
	auto iter = cmdList.find(cmd);
	if( iter == cmdList.end() ) {
		std::cout << "No Such Command!" << std::endl;
		return true;
	}

	switch(cmd) {
		case Cmd_PrintHelp: PrintAllHelp(); break;
		case Cmd_PrintCourseList: manager.PrintCourseList(); break;
		case Cmd_PrintCourseNum: std::cout << manager.getCourseNum() << std::endl;
		case Cmd_PrintLongestName: manager.PrintLongest(); break;
		case Cmd_RemoveLastCourse: manager.delLast(); break;
		case Cmd_Exit: return false;
	}
	return true;
}






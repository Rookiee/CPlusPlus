#ifndef CMD_H
#define CMD_H

enum CourseCmd {
	// print help info
	Cmd_PrintHelp = 0,
	Cmd_PrintCourseList = 1,
	Cmd_PrintCourseNum = 2,
	Cmd_PrintLongestName = 3,
	Cmd_RemoveLastCourse = 4,
	Cmd_Exit = 5, // The last comma is necessary
};

#endif

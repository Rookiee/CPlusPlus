#include <iostream>
#include "CmdManager.h"
#include "Cmd.h"
#include "Course.h"
#include "CourseManager.h"
using namespace std;

int main() {
	CmdManager CmdM;
	CmdM.Init();
	CmdM.PrintAllHelp();

	cout << "New Command: ";

	int cmd;
	while(cin >> cmd) {
		if(cin.good()) {
			bool exitCode = CmdM.HandelCmd(CourseCmd(cmd));
			if( !exitCode )
				return 0;
			
		}
		cout << "----------" << endl;
		cout << "New Command: ";
		cin.clear();
		cin.sync();
		//cin.ignore();
	}
}


#include "Course.h"
#include "CourseManager.h"

using namespace std;
int main() {
	Course c1("shuxue");
	Course c2("Yuwen");
	cout << c1 << endl;
	cout << c2 << endl;
	vector<Course> bye;
	bye.push_back(c1);
	
	

	return 0;
}


#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	string ai[] = {
				"hello",
				"hello",
				"world",
				"world" };
	list<string> strList(ai,ai+4);
	int cnt = count(strList.begin(), strList.end(),"world");
	int cnt1 = count(strList.begin(), strList.end(),"wor");
	cout << cnt << endl;
	cout << cnt1 << endl;
	return 0;
}

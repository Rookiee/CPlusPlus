#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

bool GT4(const string &s){
	return s.size()>=4;
}

int main() {
	string word[] = {
				"hello", "world", "hello","bye","seen" };
	vector<string> strVec(word, word+5);

	sort(strVec.begin(), strVec.end());
/******** print out the sorted vector ************/	
	cout << "print out the sorted vector." << endl;
	for(vector<string>::iterator iter = strVec.begin(); iter != strVec.end(); ++iter) {
	cout << *iter << " ";
	}
	cout << endl;

/*******unique duplicated words so that each word appears only once,
		however, not real deleted the duplicated elements. ********/
	vector<string>::iterator end_iter = unique(strVec.begin(), strVec.end());
	cout << "vector after unique." << endl;
	for(vector<string>::iterator iter = strVec.begin(); iter != strVec.end(); ++iter) {
	cout << *iter << " ";
	}
	cout << endl;

/****elimite the duplicated words by container's operations, erase ***/
	strVec.erase(end_iter, strVec.end());
	cout << "vector after erase the duplicated wrod." << endl;
	for(vector<string>::iterator iter = strVec.begin(); iter != strVec.end(); ++iter) {
	cout << *iter << " ";
	}
	cout << endl;

/**** sort the vector by size, by maintain the alphabetic order ******/
	stable_sort(strVec.begin(), strVec.end(),isShorter);
	cout << "vector sorted by size."<< endl;
	for(vector<string>::iterator iter = strVec.begin(); iter != strVec.end(); ++iter) {
	cout << *iter << " ";
	}
	cout << endl;
/*
//  get the number of words which are greater than or equal 4 
	vector<string>::size_type cnt = count_if(strVec.begin(),strVec.end(),GT4);
	cout << cnt << " elements lenght are greather than or equal to 4." << endl;
	return 0;
*/


/*   using find_if   */
//	vector<string>::iterator findIter = find_if(strVec.begin(), strVec.end(),GT4);
//	cout << *findIter << endl;
	vector<string>::size_type findCnt = 0;
	for(vector<string>::iterator findIter = find_if(strVec.begin(), strVec.end(),GT4); findIter != strVec.end(); ++findIter) {
		++findCnt;
	}
	cout << findCnt << " elements lenght are greather than or equal to 4." << endl;
	
	
}


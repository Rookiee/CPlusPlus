#include <iostream>
#include "15_3-Item_base.h"
#include "15_6-Bulk_item.h"
#include "15_21-Disc_item.h"
#include <vector>
using namespace std;

int main() {

/* 15_20 test program */
/*
	Item_Base base1("999");
//	cout << base1 << endl;
	Bulk_item bulk1;
	cout << bulk1 << endl;
*/
//Disc_base a1;

/* 15.28 */
	Item_Base base1("999");
	Bulk_item bulk1;
	vector<Item_Base> bvec;
	
	bvec.push_back(base1);
	bvec.push_back(bulk1);
	for(vector<Item_Base>::iterator iter = bvec.begin(); iter != bvec.end(); ++iter) {
	cout << *iter << endl;
	if(iter != --bvec.end())
		cout << " ";
	}
	return 0;
}

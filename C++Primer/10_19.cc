#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int main() {
	map<string, vector< pair<string,string> > > info;
	string lastName, firstName, birthday;
	cout << "Enter lastname:(0 to quiz) " ;
	while(cin >> lastName) {
		if(lastName == "0")
			break;
		vector< pair<string, string> > firstNameAndBirth;
		pair< map<string, vector< pair<string, string> > >::iterator, bool> ret = info.insert(make_pair(lastName, firstNameAndBirth));
		if( !ret.second ) {
			cout << "\n Already exist." << endl;
			continue;
		}
	
		
		cout << "Enter the firstname and birthday: ";
		while(cin >> firstName >> birthday) {
			if( firstName == "0" || birthday =="0") {
				cout << "Enter another lastname: ";
				break;
			}
			ret.first->second.push_back(make_pair(firstName,birthday));
		}
	}

		cin.clear();
		cin.sync();
		while(true) {	
		cout << "Enter the lastname to search: " ;
		cin >> lastName;
//		bool again = true;
		
		map<string, vector< pair<string,string> > >::iterator iter = info.find(lastName);
		if(iter == info.end() ) {
			cout << "No matching" << endl;
			cout << "Try again ( y for yes, no for no): ";
			char c;
			cin >> c;
			if(c=='y')
				continue;
			else
				break;
		}
		else {
			vector< pair<string, string> > :: iterator itvec = iter->second.begin();
			while(itvec != iter->second.end() ) {
				cout << iter->first << " ";
				cout << itvec->first << " ";
				cout << itvec->second << endl;
				++itvec;
			}
			cout << "Another? ( y for yes, n for no ): ";
			char c;
			cin >>c;
			if(c == 'y')
				continue;
			else
				break;
		}
		}
		cout << "DONE" << endl;
		return 0;
}

				
		
		
			
			
		

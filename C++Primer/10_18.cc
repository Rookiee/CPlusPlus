#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>
using namespace std;

int main() {
	map<string, vector<string> > mapName;
	string surName;
	string firstName;
	cout << "Enter the surname: ";
	while(cin >> surName) {
		if(surName == "0") {
//			cout <<"Enter the surname: "
			break;
		}

		vector<string> firstVect;
/**********key point*************************/
		pair< map<string, vector<string> >::iterator, bool> ret = 
		mapName.insert(make_pair(surName,firstVect));
		if(!ret.second) {
			cout << "Alread exist." << endl;
			continue;
		}
		cout << "Enter the first name: ";
		while(cin >> firstName) {
			if(firstName == "0") {
				cout << "Enter the surname: ";
				break;
			}
			ret.first->second.push_back(firstName);
		}
	}


	cin.clear();
	cin.sync();
	cout << "\n Enter the name to search: " ;
	cin >> surName;
	map<string, vector<string> > :: iterator iter = mapName.find(surName);
	if(iter == mapName.end())
		cout << "No matching" << endl;
	else {
		vector<string>::iterator itvec = iter->second.begin();
		while(itvec != iter->second.end() ) {
			cout << *itvec++ << endl;
		}

	}
	return 0;
}

		

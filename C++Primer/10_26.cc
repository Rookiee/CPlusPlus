#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;
typedef multimap<string,string>::iterator multiIter;
typedef multimap<string,string>::size_type sizeT;
int main() {
	multimap <string, string> authorBooks;
	string author,book;
	cout << "Enter the author: ";

	while(cin >> author) {
		if(author == "0")
			break;
		cout << "Enther "<< author << "'s books:" ;
		while(cin >> book) {
			if(book == "0") {
				cout << "Enthor another author: ";
				break;
			}
			authorBooks.insert(make_pair(author,book));
			cout << "Enter another book: ";
		}
	}

	cin.clear();
	cin.sync();

	cout << "Enter the author to search: ";
	cin >> author;
	multiIter iter = authorBooks.find(author);
	if(iter == authorBooks.end()) {
		cout << "No matching."<< endl;
		exit(1);
	}
	else {
		sizeT entries = authorBooks.count(author);
		cout << "The following will be deleted." << endl;
		for(sizeT cnt = 0; cnt != entries; ++cnt,++iter) {
			cout << iter->second << endl;
		}
	}
	sizeT delCnt = authorBooks.erase(author);
	cout << "Total: " << delCnt << endl; 

	return 0;
}

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
	pair<multiIter, multiIter> getpos = authorBooks.equal_range(author);
	pair<multiIter, multiIter> pos = getpos;
	cout << "The following will be deleted." << endl;
	while(pos.first != pos.second) {
		cout << pos.first->second << endl;
		++pos.first;
	}
	authorBooks.erase(getpos.first,getpos.second);
/*     check whether or not the books have been deleted     */
	pair<multiIter, multiIter> check = authorBooks.equal_range(author);
	if(check.first == check.second)
		cout << "BINGO" << endl;
	while(check.first != check.second) {
		cout << check.first->second << endl;
		++check.first;
	}
		
	
	return 0;
}

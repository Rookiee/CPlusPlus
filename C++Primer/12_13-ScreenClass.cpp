#include <iostream>
#include <string>

class Screen {
public:
	typedef std::string::size_type index;
private:
	std::string content_;
	index height_, width_;
	mutable size_t access_ctr_;
	index cursor_;

public:
	Screen();
	Screen(index ht = 0, index wd = 0): content_(ht * wd, ' '), cursor_(0), height_(ht), width_(wd) { }
//	Screen(std::string content, index height, index width, mutable size_t access_ctr_ = 0) : content_(content), height_(height), width_(width) {}
	Screen(std::string content, index height, index width,  size_t access_ctr_ = 0) : content_(content), height_(height), width_(width) {}
	char get() const { return content_[cursor_]; }


	char get (index height, index width ) const {
		index row = height * width_;
		return content_[row + width];
	}


	index get_cursor() const { return cursor_; }
	Screen &set(char c);
	Screen &move(index r, index c);
	Screen &display(std::ostream &os) {do_display(os); return *this; }
	

private:
	void do_display (std::ostream &os) const {
		os << content_;
	}

};

Screen & Screen::set(char c) {
	content_[cursor_] = c;
	return *this;
}

Screen & Screen::move(index r, index c) {
	index row = r * width_;
	cursor_ = row +c ;
	return *this;
}

int main() {
	using namespace std;
//	Screen test("This is a test content.",2,2);
	Screen test(5,3);
	test.display(cout);
	test.move(2,2).set('C');
	test.move(3,3).set('A');
	test.display(cout);
//	cout << test.move(0,1) << endl;
	cout << endl;
	Screen blank(5,3);
	blank.move(2,2).set('W').display(cout);
//	blank.display(cout);
	return 0;
}

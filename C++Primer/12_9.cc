#include <iostream>
#include <string>


class Screen {
public:
	typedef std::string::size_type index;
private:
	std::string contents_;
	index cursor_;
	index height_, width_;
public:
	Screen(std::string contents, index height, index width);
	char get() const { return contents[cursor]; }
	char get(index ht, index wd) const;
};

inline Screen::Screen(std::string contents, index height, index width) {
	contents_ = contents;
	height_ = height;
	width_ = width;
}

inline Screen::get(index ht, index wd) const {
	index row = r*width;
	return contents_[row + wd];
}

	
	

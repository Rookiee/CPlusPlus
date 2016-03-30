#ifndef CHECKEDPTR_H
#define CHECKEDPTR_H

#include <iostream>
#include <stdexcept>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;
using std::out_of_range;


class CheckedPtr {
private:
	int *beg;
	int *end;
	int *curr;
public:
	CheckedPtr(int *b, int *e) : beg(b), end(e) {}
	CheckedPtr(const CheckedPtr& p):beg(p.beg),end(p.end),curr(p.curr) {}
	CheckedPtr& operator=(const CheckedPtr& p);
	CheckedPtr& operator++();
	CheckedPtr& operator--();
	CheckedPtr operator++(int); 
	CheckedPtr operator--(int);
	
	int& operator[] (const size_t);
	const int& operator[] (const size_t) const;

	int& operator*();
	const int& operator*() const;

friend bool operator==(const CheckedPtr&, const CheckedPtr&);
friend bool operator<(const CheckedPtr&, const CheckedPtr&);
friend bool operator>(const CheckedPtr&, const CheckedPtr&);
friend bool operator!=(const CheckedPtr&, const CheckedPtr&);
friend bool operator>=(const CheckedPtr&, const CheckedPtr&);
friend bool operator<=(const CheckedPtr&, const CheckedPtr&);

friend CheckedPtr operator+(const CheckedPtr&, const size_t);
friend CheckedPtr operator-(const CheckedPtr&, const size_t);

friend ostream& operator<<(ostream&, const CheckedPtr&);
};
CheckedPtr& CheckedPtr::operator=(const CheckedPtr& p) {
	beg = p.beg;
	end = p.end;
	curr = p.curr;
	return *this;
}

ostream& operator << (ostream& os, const CheckedPtr& p) {
	for(int *ptr = p.beg; ptr != p.end; ++ptr) {
		os << *ptr;
		if(ptr != p.end - 1) cout << " ";
	}
	return os;
}

CheckedPtr& CheckedPtr::operator++() {
	if(curr == end)
		throw out_of_range("Out of range");
	++curr;
	return *this;
}
CheckedPtr& CheckedPtr::operator--() {
	if(curr == beg)
		throw out_of_range("Out of range");
	--curr;
	return *this;
}

CheckedPtr CheckedPtr::operator++(int) {
	CheckedPtr tmp(*this);
	++(*this);
	return tmp;
}
CheckedPtr CheckedPtr::operator--(int) {
	CheckedPtr tmp(*this);
	--(*this);
	return tmp;
}

int& CheckedPtr::operator[] (const size_t index) {
//	return CheckedPtr[index];   error
	if((beg + index)>=end || (beg+index)<beg)
		throw out_of_range("Invalid index");
	return *(beg+index);
}

const int& CheckedPtr::operator[] (const size_t index) const {
	if((beg + index)>=end || (beg+index)<beg)
		throw out_of_range("Invalid index");
	return *(beg+index);
}

int& CheckedPtr::operator*() {
	if(curr == end)
		throw out_of_range("Invalid index");
	return *curr;
}

const int& CheckedPtr::operator*() const{
	if(curr == end)
		throw out_of_range("Invalid index");
	return *curr;
}	

bool operator==(const CheckedPtr& p1, const CheckedPtr& p2) {
	return p1.beg == p2.beg && p1.end == p2.end && p1.curr == p2.curr;
}
bool operator!=(const CheckedPtr& p1, const CheckedPtr& p2) {
	return !(p1==p2);
}
bool operator < (const CheckedPtr& p1, const CheckedPtr& p2) {
	return p1.beg == p2.beg && p1.end == p2.end && p1.curr < p2.curr;
}
bool operator > (const CheckedPtr& p1, const CheckedPtr& p2) {
	return p1.beg == p2.beg && p1.end == p2.end && p1.curr > p2.curr;
}
bool operator <= (const CheckedPtr& p1, const CheckedPtr& p2) {
	return !(p1 > p2); 
}	
bool operator >= (const CheckedPtr& p1, const CheckedPtr& p2) {
	return !(p1 < p2);
}

CheckedPtr operator+(const CheckedPtr&p, const size_t index) {
	CheckedPtr tmp(p);
	tmp.curr += index;
	if(tmp.curr > tmp.end)
		throw out_of_range("Too large");
	return tmp;
}

CheckedPtr operator-(const CheckedPtr& p, const size_t index) {
	CheckedPtr tmp(p);
	tmp.curr -= index;
	if(tmp.curr < tmp.beg)
		throw out_of_range("Out of range");
	return tmp;
}


#endif

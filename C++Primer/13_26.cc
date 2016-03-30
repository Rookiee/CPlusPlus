
#include <iostream>

class HasPtr {
private:
	int *ptr;
	int val;

public:
	HasPtr(const int &p, int i) : ptr(new int(p)), val(i) {}
	HasPtr(const HasPtr &rhs) : ptr(new int(*rhs.ptr)), val(i) {}
	HasPtr & operator=(const HasPtr &rhs) {
		*ptr = *rhs.ptr;
		val = rhs.val;
		return *this;
	}

	~HasPtr() { delete ptr; }

	int *get_ptr() const { return ptr; }
	int get_ptr_val() const { return *ptr; }
	
	void set_ptr ( int *p ) { ptr = p;}
	void set_int ( int i ) { val = i;}

	void set_ptr_val(int p) const { *ptr = p; }
};

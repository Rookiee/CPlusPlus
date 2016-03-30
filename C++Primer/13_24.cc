#include <iostream>

class U_Ptr {
private:
	int *ip;
	size_t use;
	U_Ptr( int *p) : ip(p), use(1) {}
	~U_Ptr() { delete ip; }
};

class HasPtr {
private:
	U_Ptr *ptr;
	int val;
public:
	HasPtr(int *p, int i):ptr(new U_Ptr(p), val(i) {}
	HasPtr(const HasPtr &rhs) : ptr(rhs.ptr), val(rhs.val) { ++ptr->use;}
	HasPtr & operator = (const HasPtr &);
	~HasPtr () { if(--ptr->use == 0) delete ptr; }

	int *get_ptr() const { return ptr->ip; }
	int get_int() const { return val; }
	void set_ptr(int *p) { ptr->ip = p; }
	void set_int(int i) { val = i; }
	int get_ptr_val { return * ptr->ip; }
	void set_ptr_val { *ptr->ip = i; }
};

HasPtr & HasPtr::operator = (const HasPtr &rhs) {
	++rhs.ptr->use;
	if(--ptr->use == 0)
		delete ptr;
	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}




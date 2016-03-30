#ifndef BULK_ITEM_H
#define BULK_ITEM_H

#include <iostream>
#include "15_3-Item_base.h"
class Bulk_item:public Item_Base {
private:
	std::size_t min_qty_;
	double discount_;
public:
	Bulk_item():min_qty_(0),discount_(0.0),Item_Base() {}
	/*   15_14 constructor with default value		*/
	Bulk_item(std::string isbn, double price, std::size_t qty = 0,
			 double discount = 0.0) : 
			Item_Base(isbn,price),// by Item_Base's constructor 
			min_qty_(qty), discount_(discount) {
/* print a statement to indicate which constructor is called */
		std::cout << "Derived Bulk Constructor" << std::endl;
}

	/* copy-constructor */
	Bulk_item(const Bulk_item &rhs) : Item_Base(rhs),
		min_qty_(rhs.min_qty_), discount_(rhs.discount_) {}

/* if the quaity is larger than min_qty_ , then enjoy the discount */
	/*virtual*/	double net_price(std::size_t) const;
/* 15_7's function */

	virtual ~Bulk_item() { std::cout << "Derived Destructor." << std::endl; }

friend std::ostream& operator<<(std::ostream &os, const Bulk_item &rhs);
};
	
std::ostream& operator << (std::ostream &os, const Bulk_item &rhs) {
	os << "The price is: " << rhs.read() << std::endl 
		<< "The discount is: " << rhs.discount_ << std::endl
		<< "The quality is: " << rhs.min_qty_  << std::endl
	/* the next statement is not allowed, 
		because ISBN_ is private member in Base, 
		Derived class can not access to that */
//		<< "The ISBN is: " << rhs.ISBN_ ;
		<< "The ISBN is: " << rhs.book() ;
	return os;
}


/*if data member "price_" is protected in base class, then net_price could be defined like the following */
/*
double Bulk_item::net_price(std::size_t qty) const {
	if(qty >= min_qty_)
		return qty * (1-discount_) * price_;
	else
		return qty * price_;
}
*/

/* now, price_ is defined in private as ISBN_, then the only way to access price_ is through the base's public function member (read() and write()) */
double Bulk_item::net_price(std::size_t qty) const {
	if(qty >= min_qty_)
		return qty * (1-discount_) * /*Item_Base::*/read();
	else
		return qty * Item_Base::read();
}


#endif 

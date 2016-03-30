#ifndef ITEM_BASE_H
#define ITEM_BASE_H
#include <iostream>
#include <string>

class Item_Base {
private:
	std::string ISBN_;
/*
protected:
	double price_;
*/
/* defien price_ as private either, then define functions to read and write to price_ */
private:
	double price_;
public:
/*
	Item_Base ():ISBN_(0) {}
	Item_Base (std::string isbn, double price) : ISBN_(isbn), price_(price) {}
*/

/* 15_14 using a single constructor to replace above two */
	Item_Base (std::string isbn = " ", double price = 0.0) : ISBN_(isbn), price_(price) {
	/* print a statement to indicate which constructor is called." */
		std::cout << "Base Constructor" << std::endl;
}

	std::string book() const {	return ISBN_;	}
	virtual double net_price (std::size_t n) const {
		return n * price_;
	}

/* copy-constructor */
	Item_Base (const Item_Base & rhs) : price_(rhs.price_), ISBN_(rhs.ISBN_) {}

/* define read and write function for price_ */
public:
	double read() const {	return price_;	}
	void write(double price) {	price_ = price;		}

	virtual ~Item_Base() { std::cout << "Base Destructor" << std::endl;}

friend std::ostream& operator << (std::ostream &, const Item_Base &);
};

std::ostream& operator << (std::ostream &os, const Item_Base &rhs) {
	os << "The price is: " << rhs.price_ << std::endl
		<< "The ISBN is: " << rhs.ISBN_ ;
	return os;
}



#endif

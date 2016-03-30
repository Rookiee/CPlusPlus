#ifndef DISC_ITEM_H
#define DISC_ITEM_H

#include <iostream>
#include <utility>
#include "15_3-Item_base.h"

class Disc_base : public Item_Base {
public:
	std::pair<size_t, double> discount_policy() const {
		return std::make_pair(quantity, discount);
	}
	double net_price (std::size_t n) const = 0;
private:
	size_t quantity;
	double discount;
};



#endif

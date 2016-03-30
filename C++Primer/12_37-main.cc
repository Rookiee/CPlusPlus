#include <iostream>
#include "12_37-AccountClass.h"

int main() {
	Account a1;
	a1.showAccount();
	Account *p = new Account("Haoyang",1000);
	p->showAccount();

	delete p;


	return 0;
}


class Sales_item {
/* 能否把友元函数直接定义为public成员函数 */	
	friend std::istream & operator >>(std::istream &is, Sales_item &);
	friend std::ostream & operator <<(std::ostream &os, Sales_item &);
public:
	Sales_item & operator += (const Sales_item &);
};

Sales_item operator + (const Sales_item &, const Sales_item &);


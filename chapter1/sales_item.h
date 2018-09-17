#pragma once
#include <string>
#include <iostream>

class Sales_item   
{
public:
    Sales_item(std::string &book):isbn(book), units_sold(0), revenue(0.0){}
	Sales_item(std::istream& is) { is >> *this; }
	Sales_item():units_sold(0), revenue(0.0){}
	friend std::istream& operator>>(std::istream &is, Sales_item &item);
	friend std::ostream& operator<<(std::ostream &os, Sales_item &item);
public:
    Sales_item& operator +=(const Sales_item&);
	double avg_price() const;
	bool same_isbn(const Sales_item &rhs) const
	{
		return rhs.isbn == isbn;
	}
	
private:
    std::string &isbn;
	unsigned units_sold;
	double   revenue;
};

inline std::istream& operator>>(std::istream &is, Sales_item &item)
{
	double price;
	is >> item.isbn;
	is >> item.units_sold;
	is >> price;
	if(is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_item();
		
	return is;
}

inline std::ostream& operator<<(std::ostream &os, Sales_item &item)
{
	os << "book: " << item.isbn;
	os << " units_sold: " << item.units_sold;
	os << " revenue: " << item.revenue;
	os << " avg price: " item.avg_price();
	return os;
}

inline Sales_item& Sales_item::operator+=(const Sales_item &rhs)
{
	if(!same_isbn(rhs)) return *this;
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

inline double Sales_item::avg_price() const
{
	if(units_sold)
		return revenue/units_sold;
	return 0;
}

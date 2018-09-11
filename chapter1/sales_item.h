#pragma once
#include <string>
#include <iostream>

class Sales_item   
{
	public:
	Sales_item(){}
	operator >> (std::cin in)
	{
		in >> book_name_;
		in >> price_;
	}
	private:
	std::string book_name_;
	int price_;
};
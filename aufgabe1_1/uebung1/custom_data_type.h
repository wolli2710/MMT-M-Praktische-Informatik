#ifndef Custom_Data_Type_H
#define Custom_Data_Type_H

#include <iostream>

class CustomDataType
{
	friend std::ostream& operator<<(std::ostream& out, CustomDataType& cdt) 
	{ 
			return out << cdt.number;
	}

public:
	CustomDataType(int n): number(n){}
	CustomDataType():number(0){}
	~CustomDataType(){}

	bool operator< (const CustomDataType &a){
		return number < a.number;
	}

private:
	int number;
};

#endif
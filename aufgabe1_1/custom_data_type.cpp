class CustomDataType{
	public:
		CustomDataType(int n): number(n){}
		CustomDataType():number(0){}
		~CustomDataType(){}

		bool operator< (const CustomDataType &a){
			return number < a.number;
		}

		int number;
	friend std::ostream& operator<<(std::ostream& out, CustomDataType& cdt) 
	{ 
			return out << cdt.number;
	}
};
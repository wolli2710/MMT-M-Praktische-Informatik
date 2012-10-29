class CustomDataType{
	public:
		CustomDataType(int n): number(n){}
		~CustomDataType(){}

		bool operator< (const CustomDataType &a){
			return number < a.number;
		}

		/*std::ostream& operator<<(std::ostream& out, CustomDataType& cdt) 
		{ 
  			return out << cdt.number;
		} 
*/
		int number;
};
class CustomDataType{
	public:
		CustomDataType(float n): number(n){}
		~CustomDataType(){}

		bool operator< (const CustomDataType &a){
			return number < a.number;
		}

/*		std::ostream& operator<<(std::ostream& out, const CustomDataType& obj) 
		{ 
  			// write obj to stream
  			out << obj.number;
  			return out;
		} 
*/
		float number;
};
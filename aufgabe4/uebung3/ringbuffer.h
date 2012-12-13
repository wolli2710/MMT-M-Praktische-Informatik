template <typename T, 
	typename WritePolicy,
	typename ReadPolicy
>

class RingBuffer:private WritePolicy, private ReadPolicy {

public:

	RingBuffer(unsigned n=10): size(n){
		data = new T[size];
	}

	~RingBuffer(){
		delete [] data;
	}

	T& operator=(const T &o){
		if(this == &o){
			return this;
		}
		delete [] data;
		start = o.start;
		end = o.end;
		size = o.size;
		data = new T[size];

		for(int i = 0; i<size; i++){
			data[i] = o.data[i];
		}

		return *this;
	} 


private:

	unsigned size;
	T *data;
	unsigned start;
	unsigned end;

}
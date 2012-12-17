#include <iostream>

using namespace std;

template <class T, 
	typename WritePolicy ,
	typename ReadPolicy  >
class RingBuffer:private WritePolicy, private ReadPolicy {

public:

	using WritePolicy::write;
	using ReadPolicy::read;

	RingBuffer(unsigned n=10): size(n), start(0), end(0){
		data = new T[size];
	}

	~RingBuffer(){
		delete [] data;
	}

	RingBuffer(const RingBuffer &o){
		start = o.start;
		end = o.end;
		size = o.size;
		data = new T[size];

		for(int i = 0; i<size; i++){
			data[i] = o.data[i];
		}
	}

	RingBuffer& operator=(const RingBuffer &o){
		if(this != &o){	
			delete [] data;
			start = o.start;
			end = o.end;
			size = o.size;
			data = new T[size];

			for(int i = 0; i<size; i++){
				data[i] = o.data[i];
			}
		}
		return *this;
	}

	void moveStart(){
		(start+1 < size) ? start+=1 : start=0;
		//TODO handling start == end
	}

	void moveEnd(){
		(end+1 < size) ? end+=1 : end=0;
		//TODO handling start == end
	}

	unsigned getSize(){
		return size;
	}


protected:

	unsigned size;
	T *data;
	unsigned start;
	unsigned end;

};


class ReadExceptionPolicy{
protected:
	template<typename T>
	T readException(RingBuffer<T> *rb){
		if(rb->start == rb->end){
			throw "Read Exception";
		}
		
		//moveEnd();
		//return data[end];
	}
};


class WriteExceptionPolicy{
protected:
	template<typename T>
	void write(T const &value){
		//cout << "ok";

		//throw "Ring Buffer Overflow";
	}
};


class ReadDefaultValuePolicy{
protected:
	template<typename T>
	void read(T const &value){
		cout<< value;
	}
};


class WriteOverwritePolicy{
protected:
	template<typename T>
	void write(T const &value){
		cout<< "ok";
	}
};


class WriteIgnorePolicy{
protected:
	template<typename T>
	void write(T const &value){
		cout<< "ok";

	}
};
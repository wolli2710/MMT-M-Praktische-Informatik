#include "ringbuffer.h"
#include <iostream>
#include <cassert>

using namespace std;

#define SIZE 5

int main(){
	RingBuffer<unsigned, WriteOverwritePolicy, ReadDefaultValuePolicy > rb1(SIZE);
	RingBuffer<unsigned, WriteOverwritePolicy, ReadDefaultValuePolicy > rb2(rb1);

	RingBuffer<unsigned, WriteExceptionPolicy, ReadExceptionPolicy > rb3(SIZE);
	RingBuffer<unsigned, WriteIgnorePolicy, ReadExceptionPolicy > rb4(SIZE);

	rb1 = rb1;
	assert( &rb1 == &rb1 );
	assert( &rb1 != &rb2 );

	try{
		rb1.read();
	}catch(const char *e){
		assert(e=="Read Exception");
	}


	for(int i = 0; i<SIZE; i++){
		rb1.write(i);
		rb3.write(i);
	}


	rb1.write( SIZE+1 );
	assert( rb1.getSize() == SIZE );
/*	
	try{ 
		rb3.write( SIZE+1 );
	}
	catch(...){ 
		cerr << "Exception";
	}
*/

	rb1.read();
	assert( rb1.getSize() == SIZE-1 );
	
	return 0;
}
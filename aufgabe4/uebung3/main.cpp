/*
* main.cpp
*
* Created on: Dec 13, 2012
* Author: Torghele
* Author: Hewer
* Author: Vogl
*/

#include <iostream>
#include <cassert>
#include <iostream>

#include "ringbuffer.h"
#include "readpolicy.h"
#include "writepolicy.h"

#define SIZE 10

int main() {
RingBuffer<unsigned, ReadErrorPolicyDefaultValue<unsigned>, WriteErrorPolicyOverwrite> rb1(SIZE);

//Create object with copy constructor
RingBuffer<unsigned, ReadErrorPolicyDefaultValue<unsigned>, WriteErrorPolicyOverwrite> rb2(rb1);

RingBuffer<unsigned, ReadErrorPolicyException<unsigned>, WriteErrorPolicyException> rb3(SIZE);

RingBuffer<unsigned, ReadErrorPolicyException<unsigned>, WriteErrorPolicyIgnore> rb4(SIZE);

//test if copy constructor works right
assert( &rb1 != &rb2);

//Test DefaultValue Policy on reading an empty RingBuffer
assert( rb1.read( ) == 0);

//Test Exception Policy on reading an empty RingBuffer
try {
	rb3.read();
} catch (exception& e) {
	//cout << e.what() << endl;
}

for (int i = 0; i < SIZE; i++) {
	rb1.write(i);
	rb3.write(i);
	rb4.write(i);
}

//Test Overwrite Policy on full Ring Buffer
rb1.write(SIZE);
assert( rb1.getSize() == SIZE);

//Test Exception Policy on full Ring Buffer
try {
	rb4.write(SIZE);
} catch (exception& e) {
	//cout << e.what() << endl;
}

for (int i = 0; i < SIZE; i++) {
	assert(rb1.read() == i+1);
	assert(rb3.read() == i);
	assert(rb4.read() == i);
}

//Test DefaultValue Policy on reading an empty RingBuffer
assert( rb1.read() == 0);

//Test Exception Policy on reading an empty RingBuffer
try {
	rb3.read();
} catch (exception& e) {
	//cout << e.what() << endl;
}

cout << "Tests finished" << endl;

return 0;
}


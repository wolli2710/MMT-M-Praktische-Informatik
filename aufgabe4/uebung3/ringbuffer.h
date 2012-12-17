/*
* ringbuffer.h
*
* Created on: Dec 13, 2012
* Author: Torghele
* Author: Hewer
* Author: Vogl
*/

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#define DEFAULT_SIZE 10

#include <iostream>
#include "readpolicy.h"
#include "writepolicy.h"

template <
    typename T,
    typename ReadErrorPolicy = ReadErrorPolicyDefaultValue<T>,
    typename WriteErrorPolicy = WriteErrorPolicyIgnore
>
class RingBuffer: private ReadErrorPolicy, private WriteErrorPolicy {

public:

RingBuffer(unsigned n = DEFAULT_SIZE) : size(n), start(0), end(0), currentSize(0) {
	data = new T[size];
}

~RingBuffer() {
	delete[] data;
}

RingBuffer(const RingBuffer &o) {

	start = o.start;
	end = o.end;
	size = o.size;
	currentSize = o.currentSize;

	data = new T[size];

	for (int i = 0; i < size; i++) {
		data[i] = o.data[i];
	}
}

RingBuffer& operator=(const RingBuffer &o) {
	if (this == &o) return *this;

	delete[] data;

	start = o.start;
	end = o.end;
	size = o.size;
	currentSize = o.currentSize;

	data = new T[size];

	for (int i = 0; i < size; i++) {
		data[i] = o.data[i];
	}

	return *this;

}

void clear() {
	start = end = currentSize = 0;
}

unsigned getSize() {
	return currentSize;
}

void increment_tail() {
	++end;
	++currentSize;
	if (end == size) end = 0;
}

void increment_head(){
	++start;
	--currentSize;
	if (start == size) start = 0;
}

T read() {
	if (!currentSize) {
		return ReadErrorPolicy::HANDLE_ERROR();
	} else {
		T value = data[start];
		increment_head();
		return value;
	}
}

void write(T value) {
	if (!currentSize) {
		data[start] = value;
		end = start;
		++currentSize;
	} else if (currentSize != size) {
		increment_tail();
		data[end] = value;
	} else {

		if (WriteErrorPolicy::HANDLE_ERROR()) return;
		increment_head();
		increment_tail();
		data[end] = value;
	}
}

private:

	unsigned size;
	unsigned currentSize;
	unsigned start;
	unsigned end;
	T *data;

};

#endif /* RINGBUFFER_H_ */
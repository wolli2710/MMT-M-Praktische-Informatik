/*
 * cache.h
 *
 *  Created on: Jan 5, 2013
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#ifndef CACHE_H_
#define CACHE_H_

#include <string>
#include <math.h>
#include <map>

typedef enum {
	direct_mapped, fully_associative, set_associative
} ASSOCIATIVITY;

struct CacheLine {
	CacheLine() : valid(0) {}
	bool valid;
};

class Cache {

public:

	Cache(unsigned _size, unsigned _lineSize, ASSOCIATIVITY _associativity,
			unsigned _associativityLevel = 1, unsigned _addrSize = 32) : size(_size), lineSize(_lineSize),
			associativity(_associativity), associativityLevel(_associativityLevel), addrSize(_addrSize) {

		numSets = (size/lineSize) / associativityLevel;
		numCacheLines = size / lineSize;

		switch(associativity){
			case direct_mapped : indexSize = log(numCacheLines) / log(2); break;
			case fully_associative : indexSize = 0; break;
			case set_associative : indexSize = (log(numCacheLines / numSets) / log(2));	break;
		}

		offsetSize = log(addrSize) / log(2);
		tagSize = addrSize - offsetSize - indexSize;

		hitRate = missRate = usedCacheLines = 0;

	}

	void read(std::string addr, unsigned size) {

		std::string tag = addr.substr(0, tagSize);
		std::string index = addr.substr(tagSize - 1, indexSize);
		std::string offset = addr.substr(tagSize + indexSize - 1, offsetSize);

		if(storage[index][tag].valid) hitRate++;
		else missRate++;
	}
	void store(std::string addr, unsigned size) {

		std::string tag = addr.substr(0, tagSize);
		std::string index = addr.substr(tagSize - 1, indexSize);
		std::string offset = addr.substr(tagSize + indexSize - 1, offsetSize);

		storage[index][tag].valid = true;

		usedCacheLines++;

	}
	void load(std::string addr, unsigned size) {

		read(addr, size);

	}
	void modify(std::string addr, unsigned size) {


		store(addr, size);

	}

	unsigned getHitRate() {
		return hitRate;
	}

	unsigned getMissRate() {
		return missRate;
	}

	unsigned getUsedCacheLines() {
		return usedCacheLines;
	}

private:

	std::map<std::string, std::map<std::string, CacheLine> > storage;

	unsigned size;
	unsigned lineSize;
	ASSOCIATIVITY associativity;
	unsigned associativityLevel;
	unsigned numSets;
	unsigned numCacheLines;

	unsigned addrSize, tagSize, indexSize, offsetSize;

	unsigned hitRate, missRate, usedCacheLines;

};

#endif /* CACHE_H_ */

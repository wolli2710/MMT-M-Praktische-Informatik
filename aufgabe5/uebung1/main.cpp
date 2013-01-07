/*
 * main.cpp
 *
 *  Created on: Jan 05, 2013
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#include <iostream>
#include <string>

#include "cache.h"
#include "cachesim.h"

int main(int argc, const char* argv[]) {

	// instruction cache: size 4096 Bytes, cache line size 32 Bytes, direct-mapped.
	Cache instructionCache(4096, 32, direct_mapped);
	// data cache: size 256 Kilobytes, cache line size 32 Bytes, 4x associative.
	Cache dataCache(256*1024, 32, set_associative, 4);
	// CacheSimulator
	Cachesim simulator(instructionCache, dataCache, argv[1]);

	if( !simulator.parse()) {

		std::cout << "Instruction Cache:" << std::endl;
		std::cout << "Hit Rate: " << instructionCache.getHitRate() << std::endl;
		std::cout << "Miss Rate: " << instructionCache.getMissRate() << std::endl;
		std::cout << "Cache Lines Used: " << instructionCache.getUsedCacheLines() << std::endl;

		std::cout << "Data Cache:" << std::endl;
		std::cout << "Hit Rate: " << dataCache.getHitRate() << std::endl;
		std::cout << "Miss Rate: " << dataCache.getMissRate() << std::endl;
		std::cout << "Cache Lines Used: " << dataCache.getUsedCacheLines() << std::endl;
	}

	return 0;
}
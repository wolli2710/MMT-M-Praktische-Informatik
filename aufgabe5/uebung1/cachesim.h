/*
 * cachesim.h
 *
 *  Created on: Jan 5, 2013
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#ifndef CACHESIM_H_
#define CACHESIM_H_

#include "cache.h"

#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class Cachesim {
public:
	Cachesim(Cache& _instructionCache, Cache& _dataCache, const char* _inputPath) :
			instructionCache(&_instructionCache), dataCache(&_dataCache), inputPath(_inputPath) {};

	int parse() {
		std::ifstream instructionFile(inputPath);
		std::string currentLine;

		if (instructionFile.is_open()) {
			std::vector<std::string> tokens;
			while (!instructionFile.eof()) {
				std::getline(instructionFile, currentLine);

				// Skip comments
				if(currentLine[0] == '#' || currentLine[0] == 'x' || currentLine == "") continue;

				std::replace( currentLine.begin(), currentLine.end(), ',', ' ');

				std::string token;
				std::stringstream line(currentLine);

				while (line >> token) {
					tokens.push_back(token);
				}

				std::string addr = tokens[1];
				unsigned size= atoi(tokens[2].c_str());

				if (currentLine.find("I") != std::string::npos) instructionCache->read(hex2bin(addr), size);
				if (currentLine.find("S") != std::string::npos) dataCache->store(hex2bin(addr), size);
				if (currentLine.find("L") != std::string::npos) dataCache->load(hex2bin(addr), size);
				if (currentLine.find("M") != std::string::npos) dataCache->modify(hex2bin(addr), size);

				tokens.clear();
			}
			instructionFile.close();

			return 0;

		} else {
			std::cout << "Unable to open instruction file" << std::endl;
			std::cout << "Usage: cachesim <instruction file>" << std::endl;

			return 1;
		}

	}

private:

	std::string hex2bin(std::string addr) {
		std::string str = "";
		for (unsigned i = 0; i < addr.length(); ++i) {
			switch (addr [i]) {
				case '0': str.append ("0000"); break;
				case '1': str.append ("0001"); break;
				case '2': str.append ("0010"); break;
				case '3': str.append ("0011"); break;
				case '4': str.append ("0100"); break;
				case '5': str.append ("0101"); break;
				case '6': str.append ("0110"); break;
				case '7': str.append ("0111"); break;
				case '8': str.append ("1000"); break;
				case '9': str.append ("1001"); break;
				case 'a': str.append ("1010"); break;
				case 'b': str.append ("1011"); break;
				case 'c': str.append ("1100"); break;
				case 'd': str.append ("1101"); break;
				case 'e': str.append ("1110"); break;
				case 'f': str.append ("1111"); break;
			}
		}
		return str;
	}

	const char* inputPath;
	Cache* instructionCache;
	Cache* dataCache;
};

#endif /* CACHESIM_H_ */

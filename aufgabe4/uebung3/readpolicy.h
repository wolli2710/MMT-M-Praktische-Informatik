/*
* readpolicy.h
*
* Created on: Dec 13, 2012
* Author: Torghele
* Author: Hewer
* Author: Vogl
*/

#ifndef READPOLICY_H_
#define READPOLICY_H_

#include <iostream>
#include <exception>

using namespace std;

class ReadErrorException: public exception {
	virtual const char* what() const throw () {
		return "reading error";
	}
} ReadErrorException;

template<typename T>
struct ReadErrorPolicyDefaultValue
{
    static T HANDLE_ERROR()
    {
        return T();
    }
};

template<typename T>
struct ReadErrorPolicyException
{
    static T HANDLE_ERROR()
    {
        throw ReadErrorException;
    }
};

#endif /* READPOLICY_H_ */
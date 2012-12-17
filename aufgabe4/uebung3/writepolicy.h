/*
* writepolicy.h
*
* Created on: Dec 13, 2012
* Author: Torghele
* Author: Hewer
* Author: Vogl
*/

#ifndef WRITEPOLICY_H_
#define WRITEPOLICY_H_

#include <exception>
using namespace std;

class WriteErrorException : public exception {
	virtual const char* what() const throw () {
		return "write error";
	}
} WriteErrorException;

struct WriteErrorPolicyIgnore
{
    static bool HANDLE_ERROR()
    {
        return true;
    }
};


struct WriteErrorPolicyOverwrite
{
    static bool HANDLE_ERROR()
    {
        return false;
    }
};


struct WriteErrorPolicyException
{
    static bool HANDLE_ERROR()
    {
        throw WriteErrorException;
    }
};

#endif /* WRITEPOLICY_H_ */
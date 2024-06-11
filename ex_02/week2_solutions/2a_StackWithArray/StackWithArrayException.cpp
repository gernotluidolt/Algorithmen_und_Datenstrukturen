#ifndef STACKWITHARRAYEXCEPTION_H // include guard
#define STACKWITHARRAYEXCEPTION_H

#include <iostream>
#include <string>

using namespace std;


class StackWithArrayException : public exception
{

	public:
   		StackWithArrayException(const string& msg) : message(msg) {}
  		~StackWithArrayException() {}

		virtual const char* what() const throw() 
  		{ 
    			return(message.c_str()); 
  		} 

		string getMessage() const { return(message); }
	private:
   		string message;
};

#endif /* STACKWITHARRAYEXCEPTION_H */
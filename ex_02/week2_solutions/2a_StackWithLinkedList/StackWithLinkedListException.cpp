#ifndef STACKWITHLINKEDLISTEXCEPTION_H // include guard
#define STACKWITHLINKEDLISTEXCEPTION_H

#include <iostream>
#include <string>

using namespace std;


class StackWithLinkedListException : public exception
{

	public:
   		StackWithLinkedListException(const string& msg) : message(msg) {}
  		~StackWithLinkedListException() {}

		virtual const char* what() const throw() 
  		{ 
    			return(message.c_str()); 
  		} 

		string getMessage() const { return(message); }
	private:
   		string message;
};

#endif /* STACKWITHLINKEDLISTEXCEPTION_H */
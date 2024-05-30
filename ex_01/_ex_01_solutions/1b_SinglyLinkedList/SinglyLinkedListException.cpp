#ifndef SINGLYLINKEDLISTEXCEPTION_H // include guard
#define SINGLYLINKEDLISTEXCEPTION_H

#include <iostream>
#include <string>

using namespace std;


class SinglyLinkedListException : public exception
{

	public:
   		SinglyLinkedListException(const string& msg) : message(msg) {}
  		~SinglyLinkedListException() {}

		virtual const char* what() const throw() 
  		{ 
    			return(message.c_str()); 
  		} 

		string getMessage() const { return(message); }
	private:
   		string message;
};

#endif /* SINGLYLINKEDLISTEXCEPTION_H */
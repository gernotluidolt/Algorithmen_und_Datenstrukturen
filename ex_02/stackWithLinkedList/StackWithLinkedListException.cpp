#include <iostream>
#include <exception>
#include <stdexcept>

class StackWithLinkedListException : public std::exception {
public:
    StackWithLinkedListException(const char* message) : msg_(message) {}
    virtual ~StackWithLinkedListException() throw () {}

    virtual const char* what() const throw () {
        return msg_;
    }

private:
    const char* msg_;
};
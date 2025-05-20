//InvalidEntryException.h

//include statements
#pragma once
#include <stdexcept> // stdexcept header contains runtime_error

class InvalidEntryException : public std::runtime_error {
public:
	// constructor specifies default error message
	InvalidEntryException();
};
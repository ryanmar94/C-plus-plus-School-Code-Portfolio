//InvalidEntryException.cpp

//include staments
#include "InvalidEntryException.h"

//lets the user know they entered in an invalid entry
InvalidEntryException::InvalidEntryException()
: std::runtime_error{ "You have entered in an invaild entry." } {}
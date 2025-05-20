//ABag.h
#pragma once
#include <iostream>
#include "bagADT.h"

template <typename E>
class ABag: public Bag <E>{
private:
	int bagSize = 0;
	int max = 10;
	E* myBag;
public:
	ABag() {
		myBag = new E[max];
	}

	~ABag() { delete[] myBag; }   // base destructor
	
	// Insert a new item into the bag -- return false if fails and true if
	// successful
	bool addItem(const E& item) {
		if (bagSize == max) {
			return false;
		}
		else {
			myBag[size()] = item;
			bagSize++;
			return true;
		}
	}

	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	bool remove(E& item) {
		if (size() != 0) {
			for (int i = 0; i < size(); i++) {
				if (item == myBag[i]) {
					if (i < size()) {
						for (int j = i; j < size(); j++) {
							if (j < size()) {
								myBag[j] = myBag[j+1];
							}
						}
						bagSize--;
					}
					else {
						bagSize--;
					}
					return true;
				}
			}
		}
		return false;
	}

	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	bool removeTop(E& returnValue) {
		if (inspectTop(returnValue)) {
			returnValue = myBag[size() - 1];
			bagSize--;
			return true;
		}
		else {
			return false;
		}
	}

	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	bool find(E& returnValue) const {
		if (size() != 0) {
			for (int i = 0; i < size(); i++) {
				if (returnValue == myBag[i]) {
					std::cout << myBag[i] << std::endl;
					return true;
				}
			}
		}
		return false;
	}

	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	bool inspectTop(E& item) const {
		if (size() == 0) {
			return false;
		}
		else {
			item = myBag[size() - 1];
			return true;
		}
	}

	// empties the bag
	void emptyBag() {
		delete[] myBag;
		bagSize = 0;
		myBag = new E[max];
	}

	// use the += operator to add an item to the bag
	bool operator+=(const E& addend) {
		return addItem(addend);
	}

	// get the size of the bag
	int size() const {
		return bagSize;
	}

	// get the capacity of the bag
	int bagCapacity() const {
		return max;
	}

	void print() {
		if (size() != 0) {
			for (int i = 0; i < size(); i++) {
				std::cout << myBag[i] << std::endl;
			}
		}
		else {
			std::cout << "Bag is empty" << std::endl;
		}
	}
};
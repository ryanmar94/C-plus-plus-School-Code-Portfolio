//BDictionary.h
#pragma once
#include <iostream>
#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : private Dictionary <Key, E>{

private:
	ABag<KVpair<Key, E>> dictBag;

public:
	BDictionary() {}  // Default constructor
	
	~BDictionary() {} // Base destructor

	// Reinitialize dictionary
	void clear() {
		dictBag.emptyBag();
	}

	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	// Return true if insert is successful and false otherwise
	bool insert(const Key& k, const E& e) {
		KVpair<Key, E> val(k, e);
		return dictBag += val;
		
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	bool remove(const Key& k, E& rtnVal) {
		KVpair<Key, E> val(k, rtnVal);
		return dictBag.remove(val);
	}

	// Takes an arbitrary record from the dictionary and does the following:
	// - updates the E& returnValue
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	bool removeAny(E& returnValue) {
		KVpair<Key, E> val;
		bool removed;
		removed = dictBag.removeTop(val);
		returnValue = val.value();
		return removed;
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& returnValue
	// - returns true
	// If the record is not found the function returns false.
	bool find(const Key& k, E& returnValue) const {

		KVpair<Key, E> val(k, returnValue);
		return dictBag.find(val);

	}

	// Return the number of records in the dictionary.
	int size() {
		return dictBag.size();
	}

	void print() {
		if (size() > 0) {
			dictBag.print();
		}
		else {
			std::cout << "Dictionary is empty!" << std::endl;
		}
	}
};
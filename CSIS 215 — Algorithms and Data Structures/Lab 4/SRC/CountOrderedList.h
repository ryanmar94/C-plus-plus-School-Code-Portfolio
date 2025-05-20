//CountOrderedList.h
#pragma once
#include<iostream>
#include"SelfOrderedListADT.h"
#include"llist.h"
#include"Count.h"

template <typename E>
class CountOrderedList: public SelfOrderedListADT<E> {
private:
	LList<count<E>>* list;
	int compare = 0;
	
public:
	//Default constructor/destructor
	CountOrderedList() { list = new LList<count<E>>(); }
	~CountOrderedList() {}

	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	bool find(const E& it) {
		bool found = false;
		count<E> temp;
		count<E> temp2;
		count<E> first;
		if (size() > 0) {
			first = list->getValue();
		}
		for (int i = 0; i < size(); i++) {
			compare++;
			temp = list->getValue();
			if (temp.getVal() == it) {
				found = true;
				break;
			}
			list->next();
		}
		if (found == true) {
			temp = list->remove();
			temp.setNum(temp.getNum() + 1);
			list->prev();
			while (true) {
				
				temp2 = list->getValue();
				
				//if count num is same
				if (temp.getNum() == temp2.getNum()) {
					list->next();
					list->insert(temp);
					break;
				}
				else if (temp.getNum() < temp2.getNum()) {
					list->next();
					list->insert(temp);
					break;
				}
				else if (first.getVal() == temp2.getVal()) {

					list->insert(temp);
					break;
				}
				else if (temp.getNum() > temp2.getNum()) {
					if (first.getVal() == temp.getVal()) {
						list->insert(temp);
						break;
					}
				}
				list->prev();
			}
		}
		else {
			temp.setVal(it);
			temp.setNum(0);
			list->append(temp);
		}
		list->moveToStart();
		return found;
	}

	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.
	//Add new 'it' to the list
	void add(const E& it) {
		count<E> var;
		var.setVal(it);
		list->append(var);
	}  

	//Returns the number of accumulated compares
	int getCompares() const { return compare; }

	//Returns the size of the list
	int size() const { return list->length(); }

	//Print the list
	//In order print of the list.  printlist() prints the entire list
	//whereas printlist(n) prints n nodes.
	void printlist() const {
		std::cout << std::endl << "Count Heuristic: Size of list: " << size() << endl;
		std::cout << "Number of compares: " << getCompares() << std::endl;
		for (int i = 0; i < size(); i++) {
			count<E> temp = list->getValue();
			std::cout << temp.getVal() << "=" << temp.getNum() << ", ";
			list->next();
		}
		std::cout << endl;
		list->moveToStart();
	}
	void printlist(int n) const {
		std::cout << std::endl << "Count Heuristic: Size of list: " << size() << endl;
		std::cout << "Number of compares: " << getCompares() << std::endl;
		for (int i = 0; i < n; i++) {
			count<E> temp = list->getValue();
			std::cout << temp.getVal() << "=" << temp.getNum() << ", ";
			list->next();
		}
		std::cout << endl;
		list->moveToStart();
	}

};
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

//BST.h

// This file includes all of the pieces of the Threaded BST implementation

// Include the node implementation
#include "BSTNode.h"

// Include the dictionary ADT
#include "dictionary.h"

#ifndef BST_H
#define BST_H

using namespace std;

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key,E> {
private:
  BSTNode<Key,E>* root;   // Root of the BST
  BSTNode<Key, E>* current;
  bool directionRight = false;
  bool directionLeft = false;
  int nodecount;         // Number of nodes in the BST


  // Private "helper" functions
  void clearhelp(BSTNode<Key, E>*);
  BSTNode<Key,E>* inserthelp(BSTNode<Key, E>*,
                              const Key&, const E&, BSTNode<Key, E>*);
  BSTNode<Key,E>* deletemin(BSTNode<Key, E>*);
  BSTNode<Key,E>* getmin(BSTNode<Key, E>*);
  BSTNode<Key,E>* removehelp(BSTNode<Key, E>*, const Key&);
  E* findhelp(BSTNode<Key, E>*, const Key&) const;
  void printhelp(BSTNode<Key, E>*, BSTNode<Key, E>*, int) const;
  void printReversehelp(BSTNode<Key, E>*, BSTNode<Key, E>*) const;
  void printInorderhelp(BSTNode<Key, E>*, BSTNode<Key, E>*) const;
  void visit(BSTNode<Key, E>*) const;
  BSTNode<Key, E>* nextInorder(BSTNode<Key, E>*) const;
  BSTNode<Key, E>* nextInReverse(BSTNode<Key, E>*) const;

public:
  BST(Key k, E e) { 
	  root = new BSTNode<Key, E>;
	  root->setKey(k);
	  root->setElement(e);
	  root->setLThread(0);
	  root->setRThread(1);
	  root->setLeft(root);
	  root->setRight(root);
  }  // Constructor
  
  //Note from Prof Sipantzi -- I've commented out the destructor
  //since you would have to change clearhelp() to make it work with
  //doubly-threaded trees and that is not part of the assignment.
  //~BST() { clearhelp(root); }            // Destructor

  void clear()   // Reinitialize tree
    { clearhelp(root); root = NULL; nodecount = 0; }

  // Insert a record into the tree.
  // k Key value of the record.
  // e The record to insert.
  void insert(const Key& k, const E& e) {
    root = inserthelp(root, k, e, current);
    nodecount++;
  }

  bool getDirectionRight() { return directionRight; }
  bool getDirectionLeft() { return directionLeft; }
  void setDirectionRight(bool r) { directionRight = r; }
  void setDirectionLeft(bool l) { directionLeft = l; }

  // Remove a record from the tree.
  // k Key value of record to remove.
  // Return: The record removed, or NULL if there is none.
  E* remove(const Key& k) {
    E* temp = findhelp(root, k);   // First find it
    if (temp != NULL) {
      root = removehelp(root, k);
      nodecount--;
    }
    return temp;
  }
  // Remove and return the root node from the dictionary.
  // Return: The record removed, null if tree is empty.
  E* removeAny() {  // Delete min value
    if (root != NULL) {
      E* temp = new E;
      *temp = root->element();
      root = removehelp(root, root->key());
      nodecount--;
      return temp;
    }
    else return NULL;
  }

  // Return Record with key value k, NULL if none exist.
  // k: The key value to find. */
  // Return some record matching "k".
  // Return true if such exists, false otherwise. If
  // multiple records match "k", return an arbitrary one.
  E* find(const Key& k) const { return findhelp(root, k); }

  // Return the number of records in the dictionary.
  int size() { return nodecount; }

  void print() const { // Print the contents of the BST
    if (root == NULL) cout << "The BST is empty.\n";
    else printhelp(root->left(), root, 0);
  }

  void printInorder() const { // Print the contents of the BST
	  if (root == NULL) cout << "The BST is empty.\n";
	  else printInorderhelp(root->left(), root);
  }

  void printReverse() const { // Print the contents of the BST
	  if (root == NULL) cout << "The BST is empty.\n";
	  else printReversehelp(root->left(), root);
  }

};

// Visit -- prints out root
template <typename Key, typename E>
void BST<Key, E>::visit(BSTNode<Key,E>* r) const {
    cout << "Node - " << r->element() << endl;
}

// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::
clearhelp(BSTNode<Key, E>* root) {
  if (root == NULL) return;
  clearhelp(root->left());
  clearhelp(root->right());
  delete root;
}

// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::inserthelp(
    BSTNode<Key, E>* root, const Key& k, const E& it, BSTNode<Key, E>* current) {

	BSTNode<Key, E>* node = new BSTNode<Key, E>;
	node->setKey(k);
	node->setElement(it);

	if (root->left() == root && root->right() == root) {
		node->setLThread(root->getLThread());
		node->setLeft(root->left());
		root->setLeft(node);
		root->setLThread(1);
		node->setRThread(0);
		node->setRight(root);
	}
	else {
		current = root->left();

		while (true) {
			if (node->key() < current->key()) {
				if (current->getLThread() == 0) {
					setDirectionLeft(true);
					setDirectionRight(false);
					break;
				}
				else {
					current = current->left();
				}
			}
			else if (current->getRThread() == 0) {
				setDirectionLeft(false);
				setDirectionRight(true);
				break;
			}
			else {
				current = current->right();
			}
		}
		if (getDirectionLeft()) {
			node->setLThread(current->getLThread());
			node->setLeft(current->left());
			current->setLeft(node);
			current->setLThread(1);
			node->setRThread(0);
			node->setRight(current);
		}
		else if (getDirectionRight()) {
			node->setRThread(current->getRThread());
			node->setRight(current->right());
			current->setRight(node);
			current->setRThread(1);
			node->setLThread(0);
			node->setLeft(current);
		}
	}
    
	return root;       // Return tree with node inserted
}


// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
getmin(BSTNode<Key, E>* rt) {
  if (rt->left() == NULL)
    return rt;
  else return getmin(rt->left());
}
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
deletemin(BSTNode<Key, E>* rt) {
  if (rt->left() == NULL) // Found min
    return rt->right();
  else {                      // Continue left
    rt->setLeft(deletemin(rt->left()));
    return rt;
  }
}

// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
removehelp(BSTNode<Key, E>* rt, const Key& k) {
  if (rt == NULL) return NULL;    // k is not in tree
  else if (k < rt->key())
    rt->setLeft(removehelp(rt->left(), k));
  else if (k > rt->key())
    rt->setRight(removehelp(rt->right(), k));
  else {                            // Found: remove it
    BSTNode<Key, E>* temp = rt;
    if (rt->left() == NULL) {     // Only a right child
      rt = rt->right();         //  so point to right
      delete temp;
    }
    else if (rt->right() == NULL) { // Only a left child
      rt = rt->left();          //  so point to left
      delete temp;
    }
    else {                    // Both children are non-empty
      BSTNode<Key, E>* temp = getmin(rt->right());
      rt->setElement(temp->element());
      rt->setKey(temp->key());
      rt->setRight(deletemin(rt->right()));
      delete temp;
    }
  }
  return rt;
}

// Find a node with the given key value
template <typename Key, typename E>
E* BST<Key, E>::findhelp(BSTNode<Key, E>* root,
                              const Key& k) const {
  if (root == NULL) return NULL;          // Empty tree
  if (k < root->key())
    return findhelp(root->left(), k);   // Check left
  else if (k > root->key())
    return findhelp(root->right(), k);  // Check right
  else {
      E* temp = new E;
      *temp = root->element();
      return temp;  // Found it
  }
}

// Print out a BST
template <typename Key, typename E>
void BST<Key, E>::
printhelp(BSTNode<Key, E>* current, BSTNode<Key, E>* root, int level) const {
	if (current != root) {
		if (current->getLThread() != 0) {
			printhelp(current->left(), root, level + 1); // Do left subtree
		}

		for (int i = 0; i < level; i++) {        // Indent to level
			cout << "  ";
		}
		cout << current->key() << "\n";
		// Print node value
		if (current->getRThread() != 0) {
			printhelp(current->right(), root, level + 1);  // Do right subtree
		}
	}
}


// Print out a BST Inorder
template <typename Key, typename E>
void BST<Key, E>::
printInorderhelp(BSTNode<Key, E>* current, BSTNode<Key, E>* root) const {
	
	while (current->getLThread() == 1) {
		current = current->left();
	}

	while (current != root) {
		visit(current);
		current = nextInorder(current);
	}
}

// Print out a BST Inorder
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
nextInorder(BSTNode<Key, E>* current) const {

	if (current->getRThread() == 0) {
		return current->right();
	}

	current = current->right();

	while (current->getLThread() == 1) {
		current = current->left();
	}

	return current;
}

// Print out a BST in reverse
template <typename Key, typename E>
void BST<Key, E>::
printReversehelp(BSTNode<Key, E>* current, BSTNode<Key, E>* root) const{
	while (current->getRThread() == 1) {
		current = current->right();
	}

	while (current != root) {
		visit(current);
		current = nextInReverse(current);
	}
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
nextInReverse(BSTNode<Key, E>* current) const {

	if (current->getLThread() == 0) {
		return current->left();
	}

	current = current->left();

	while (current->getRThread() == 1) {
		current = current->right();
	}

	return current;
}

#endif
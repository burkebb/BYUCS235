#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinkedListInterface.h"
using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T> // no <T> after LinkedList
{

private:
	struct Node {
		T item;
		Node* next;
		Node(const T& newItem, Node* next_val = NULL) : item(newItem), next(next_val) {} 
	};
	Node* head;
	Node* tail;
	int listSize;

	//return true if no duplicate, false if duplicate exists
	bool noDuplicate(T value) {
		Node* current = head;

		while(current != NULL) {
			if (current->item == value) {
				return false;
			}
			current=current->next;
		}

		return true;
		
	};

public:

	LinkedList(void) {
		head = NULL;
		tail = NULL;
		listSize = 0;
	};
	~LinkedList(void) {
		clear();
	};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/

	void insertHead(T value) {
		
		if(listSize == 0) {
			Node* temp = new Node(value);
			//temp->next = NULL; this is accomplished by default constructor
			head = temp;
			tail = temp;
			listSize++;
			return;
		}
		if(noDuplicate(value)) {
			Node* temp = new Node(value,head);
			head = temp;
			listSize++;
			return;
		}
	};

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value) {
		
		if(listSize == 0) {
			Node* temp = new Node(value);
			head = temp;
			tail = temp;
			listSize++;
			return;
		}
		if(noDuplicate(value)) {
			Node* temp = new Node(value);
			tail->next = temp;
			tail = temp;
			listSize++;
			return;
		}
	};

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode) {
		
		
		if (listSize == 0) {
			return;
		}
		Node* current = head;
		if (!noDuplicate(value)) {
			return;
		}
		else {
			while (current->next != NULL) {
				
				if (current->item == insertionNode) {
					
					Node* temp = new Node(value,current->next);
					current->next = temp;
					listSize++;
					return;
				}	
				current = current->next;		
			}
			if (current == tail && current->item == insertionNode) {

				Node* temp = new Node(value);
				tail->next = temp;
				tail = temp;
				listSize++;
				return;
			}
		}
		return;
	};

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value) {
		Node* current = head;
		Node* previous = NULL;

		if (listSize == 0) {
			return;
		}

		if (noDuplicate(value)) {
			return;
		}
		else {
			while (current->next != NULL) {
				if (current->item == value) {

					if (head == current) {
						head = head->next;
						delete current;
						listSize--;
						return;
					}
					else {
						previous->next = current->next;
						delete current;
						listSize--;
						return;
					}
				}

				previous = current;
				current = current->next;
			}
			
			if (listSize == 1) {
				previous = current;
			}
			tail = previous;
			tail->next = NULL;
			delete current;
			listSize--;

			if (listSize == 0) {
				head = NULL;
				tail = NULL;
			}
			return;
		}
	};

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear() {
		if (listSize == 0) return;

		Node* current = head;
		Node* previous;

		while (current->next != NULL) {
			previous = current;
			current = current->next;
			delete previous;
		}	

		delete current;
		head = NULL;
		tail = NULL;
		listSize = 0;
	};

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index) {
		
		Node* current;
		current = head;

		if (index >= listSize || index < 0) {
			//try {
			throw out_of_range("bad index");
			//}
			/*
			catch(out_of_range e) {
				cout << e.what() << endl;
			}
			*/
		}
		for (unsigned int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->item;
	};

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size() {
		return listSize;
	};

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString() {
		stringstream ss;
		Node* current = head;

		if (listSize == 0) {
			return ss.str();
		}
		ss << current->item;
		current = current->next;
		if (listSize == 1) {
			return ss.str();
		}

		while(current->next != NULL) {
			ss << " " << current->item;
			current = current->next;
		}
		ss << " " << current->item;

		return ss.str();

	};

};

#endif
#pragma once

#include "NodeInterface.h"

class Node : public NodeInterface {
	
public:

	int data;
	//Node* parent;
	Node* left;
	Node* right;
	Node(int num) : data(num) {
		left = NULL;
		right = NULL;
	}
	~Node() {
		left = NULL;
		right = NULL;
	};

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	Node* getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	Node* getRightChild() const;

};
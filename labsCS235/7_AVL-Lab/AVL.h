#pragma once
#include "AVLInterface.h"
#include "Node.h"

using namespace std;

class AVL : public AVLInterface {
private: 
	Node* root;
public:
	AVL() {root = NULL;}
	~AVL() {}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	Node* getRootNode() const;

	/*
	* Attempts to add the given int to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);
	bool addHelper(Node*& n, int value);

	/*
	* Attempts to remove the given int from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);
	bool removeHelper(Node*& n, int value);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	void clearHelper(Node*& n);

	//functions for AVL balancing
	void rebalance(Node*& n);
	void rotateLeft(Node*& n);
	void rotateRight(Node*& n);
	int checkBalance(Node* n);
	int height(Node* n);
};

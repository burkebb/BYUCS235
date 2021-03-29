#include "AVL.h"
#include <iostream>
#include <algorithm>

using namespace std;

Node* AVL::getRootNode() const {
	return this->root;
}

bool AVL::add(int data)
{
  return addHelper(root, data);
}

bool AVL::addHelper(Node*& n, int data)
{
  // Case: n == NULL
  //cout << "0\n";
  if(n == NULL)
  {
    n = new Node(data);
	//cout <<"addNULL\n";
    //n = newNode;
    return true;
  }

  // Case: n->data == data
  else if(n->data == data)
  {
	//cout <<"==\n";
    return false;
  }

  // Case: data < n->data
  else if(data < n->data)
  {
    bool isAdded = addHelper(n->left, data);
    if(isAdded) {
		n->height ++; //increments height
		//cout<<n->height<<endl;
    	rebalance(n);
	}
	//cout <<"<\n";
    return isAdded;
  }

  // Case: data > n->data
  else if(data > n->data)
  {
	//cout <<">\n";
    bool isAdded = addHelper(n->right, data);
	//cout <<"1\n";
    if(isAdded) {
		//cout << n->height << endl;
		n->height ++; //increments height
		//cout << n->height << endl;
    	rebalance(n);
	}
    return isAdded;
  }
}

bool AVL::remove(int data) {
	return removeHelper(root, data);
}

bool AVL::removeHelper(Node*& ptr, int data) {
	//rebalance(ptr); //???
	if (ptr == NULL) {
		return false;
	}
	else if (data < ptr->data) {
		bool isRemoved = removeHelper(ptr->left, data);
		if(isRemoved) {
			//n->height ++; //increments height
			//cout<<n->height<<endl;
			rebalance(ptr);
			//cout << "removerebalance\n";
		}
		//cout <<"<\n";
    	return isRemoved;
	}
	else if (data > ptr->data) {
		bool isRemoved = removeHelper(ptr->right, data);
		if(isRemoved) {
			//n->height ++; //increments height
			//cout<<n->height<<endl;
			rebalance(ptr);
			//cout << "removerebalance\n";
		}
		//cout <<"<\n";
		return isRemoved;
	}

	if (data == ptr->data) {
		if (ptr->left == NULL && ptr->right == NULL) { // no child
			delete ptr;
			ptr = NULL; //apparently this line fixed seg fault
			return true;
		}
		if (ptr->left != NULL && ptr->right == NULL) { // only left child
			Node* temp = ptr->left;
			delete ptr;
			ptr = temp;
			return true;
		}
		if (ptr->left == NULL && ptr->right != NULL) { // only right child
			Node* temp = ptr->right;
			delete ptr;
			ptr = temp;
			return true;
		}
		if (ptr->left != NULL && ptr->right != NULL) { //two children
			Node* local_root = ptr->left; // enter left subtree
			Node* parent = ptr;
			while(local_root->right != NULL) { //find rightmost node in left subtree
				parent = local_root;
				local_root = local_root->right;
			}
			if (ptr->data != parent->data) {
				parent->right = local_root->left;
			}
			else {
				parent->left = local_root->left;
			}

			ptr->data = local_root->data;
			delete local_root;
			rebalance(ptr); //???
			//rebalance(parent); //?????
			return true;
			/*
			int new_data = local_root->data;
			recursRemove(local_root, local_root->data);
			delete ptr;
			ptr = new Node(new_data);
			return true;
			*/
		}
	}
	cout << "failure\n";
}

void AVL::clear() {
	clearHelper(root);
}
void AVL::clearHelper(Node*& ptr) {
	if (ptr == NULL) {
		return;
	}
	if (ptr->left != NULL) {
		clearHelper(ptr->left);
	}
	if (ptr->right != NULL) {
		clearHelper(ptr->right);
	}
	delete ptr;
	ptr = NULL;
	return;
}

//
/*
balancing functions
*/
//

void AVL::rotateLeft(Node*& n)
{
  Node* temp = n;
  n = n->right; // Set pointer to n to point to k
  temp->right = n->left; // Set n's right to point to k's left
  n->left = temp; // Set k's left to point to n
}

void AVL::rotateRight(Node*& n)
{
  Node* temp = n;
  n = n->left; // Set pointer to n to point to k
  temp->left = n->right;// Set n's left to point to k's right
  n->right = temp; // Set k's right to point to n
}

void AVL::rebalance(Node*& n)
{
  // Check node's balance (should be -2, -1, 0, 1, or 2)
	int balance = checkBalance(n);
	//cout << balance << endl;
  // Case: balance == -2 (LL or LR tree)
	if (balance < -1) {
		int l_balance = checkBalance(n->left);
    // Case: LL tree (left balance is -1 or 0, so rotate right around n)
	//UPDATE TO ALGORITHM DONT SHIFT LL TREE WITH LBALANCE == 0
	
		if (l_balance == -1 || l_balance == 0) {
			rotateRight(n);
			return;
		}
	
	/*
		if (l_balance == -1) {
			rotateRight(n);
			return;
		}
		else if (l_balance == 0) {
			//cout << "LL TREE with lbalance == 0\n";
			return;
		}
	*/
    // Case: LR tree (left balance is 1, so rotate left around n->left, then rotate right around n)
		else if (l_balance == 1) {
			rotateLeft(n->left);
			rotateRight(n);
			return;
		}
		else cout << "failure\n";
		return;
	}
  // Case: balance == 2 (RR or RL tree)
	else if (balance > 1) {
		int r_balance = checkBalance(n->right);
    // Case: RR tree (right balance is 1 or 0, so rotate left around n)
	//UPDATE TO ALGORITHM DONT SHIFT RR TREE WITH RBALANCE == 0
	
		if (r_balance == 1 || r_balance == 0) {
			rotateLeft(n);
			return;
		}
	
	/*
		if (r_balance == 1) {
			rotateLeft(n);
			return;
		}
		else if (r_balance == 0) {
			//cout << "RR TREE with rbalance == 0\n";
			return;
		}
	*/
    // Case: RL tree (right balance is -1, so rotate right around n->right, then rotate left around n)
		else if (r_balance == -1) {
			rotateRight(n->right);
			rotateLeft(n);
			return;
		}
		else cout << "failure\n";
		return;
  // Case: else (do nothing, not unbalanced)
	}
	else return;
}

int AVL::checkBalance(Node* n) {
	//cout << r - l << endl;
	return height(n->right) - height(n->left);
}

int AVL::height(Node* n) {
	if (n == NULL) {
		return 0;
	}
	else {
		return max(height(n->left),height(n->right))+1;
	}
}
//note: look into difference between passing Node* and Node*&
//edit: pass Node*& if you want to change the pointer itself instead
//	of just what the pointer points to
#include "BST.h"

using namespace std;

BST::BST(Node* r) : root(r) {} // only use default parameter in declaration

BST::~BST() {
	clear();
}

Node* BST::getRootNode() const {
	return root;
}

bool BST::recursAdd(Node*& ptr, int data) {
	
	if (ptr == NULL) {
		ptr = new Node(data);
		//cout <<"add " << ptr->data << endl;;
		return true;
	}
	else if (data < ptr->data) {
		return recursAdd(ptr->left, data);
	}
	else if (data > ptr->data) {
		return recursAdd(ptr->right, data);
	}
	else {
		//cout << data << " already\n";
		return false;
	}
}

bool BST::add(int data) {
	//cout << "ADD\n";
	return recursAdd(root, data); // do i need "this->"? probably not unless recursAdd
}

bool BST::recursRemove(Node*& ptr, int data) {
	if (ptr == NULL) {
		return false;
	}
	else if (data < ptr->data) {
		return recursRemove(ptr->left, data);
	}
	else if (data > ptr->data) {
		return recursRemove(ptr->right, data);
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

bool BST::remove(int data) {
	return recursRemove(root, data);
}

void BST::recursClear(Node*& ptr) {
	if (ptr == NULL) {
		return;
	}
	if (ptr->left != NULL) {
		recursClear(ptr->left);
	}
	if (ptr->right != NULL) {
		recursClear(ptr->right);
	}
	delete ptr;
	ptr = NULL;
	return;
}

void BST::clear() {
	recursClear(root);
}
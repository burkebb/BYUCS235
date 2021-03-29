#include "Node.h"

	int Node::getData() const{
		return this->data;
	}
	void Node::setData(int ndata) {
		this->data = ndata;
	}

	Node * Node::getLeftChild() const {
		return this->left;
	}
	void Node::setLeftChild(Node* nleft) {
		this->left = nleft;
	}

	Node * Node::getRightChild() const {
		return this->right;
	}
	void Node::setRightChild(Node* nright) {
		this->right = nright;
	}

	int Node::getHeight() {
		return this->height;
	}
	void Node::setHeight(int nheight) {
		this->height = nheight;
	}
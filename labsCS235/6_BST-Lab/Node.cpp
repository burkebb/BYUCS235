#include "Node.h"

//Node::Node(int num = 0, /*Node* p = NULL,*/ Node* l = NULL, Node* r = NULL) : data(num), /*parent(p),*/ left(l), right(r) {}

//Node::~Node() {clear?}

int Node::getData() const {
	return data;
}

Node* Node::getLeftChild() const {
	return left;
}

Node* Node::getRightChild() const {
	return right;
}
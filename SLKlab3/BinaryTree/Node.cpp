#include "Node.h"



Node::Node()
{
}


Node::~Node()
{
}

int Node::getChildrenCount() {
	// - 
	int count = 0;
	if (this->left != nullptr)
		count++;
	if (this->right != nullptr)
		count++;
	return count;
}

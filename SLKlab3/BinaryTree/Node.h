#pragma once
class Node
{
	int key;
	int value;
	Node * left = nullptr;
	Node * right = nullptr;
public:
	Node(int key, int value) {
		this->key = key;
		this->value = value;
	};

	int getKey() { return this->key; }
	int getValue() { return this->value; }
	Node * getLeftChild() { return this->left; }
	Node * getRightChild() { return this->right; }
	void setLeftChild(Node * node) { this->left = node; }
	void setRightChild(Node * node) { this->right = node; }
	int getChildrenCount();
	Node();
	~Node();
};


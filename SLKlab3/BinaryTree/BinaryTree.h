#pragma once
#include "Node.h"
class BinaryTree
{
	Node * root;
	void preOrder(Node *);
	void postOrder(Node *);
	void inOrder(Node *);
	void clean(Node *);
	int getLeavesCount(Node *);

public:
	void add(int key, float value);
	void addList();
	void remove(int key);
	void inOrder();
	void preOrder();
	void postOrder();

	int find(int key);
	BinaryTree();
	~BinaryTree();
	void clean();
	int getLeavesCount();
};


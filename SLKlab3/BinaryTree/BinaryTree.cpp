#include "BinaryTree.h"
#include "NodeCreator.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	this->root = nullptr;
}

void BinaryTree::add(int key, float value) {
	Node* node = new Node(key, value);
	if (this->root == nullptr)
		this->root = node;
	else {
		int key = node->getKey();
		Node * currentNode = this->root;
		Node * temp;
		while (true) {
			if (key > currentNode->getKey()) {
				temp = currentNode->getRightChild();
				if (temp == nullptr) {
					currentNode->setRightChild(node);
					break;
				}
			}
			else {
				temp = currentNode->getLeftChild();
				if (temp == nullptr) {
					currentNode->setLeftChild(node);
					break;
				}
			}

			currentNode = temp;
		
		}
		
	}
}

void BinaryTree::addList() {
	Node* nodeList[30];
	int lnth, value, key;
	cout << "Please enter your list length \n";
	cin >> lnth;
	for (int i = 0; i < lnth; i++) {
		cout << "Enter key: ";
		cin >> key;
		cout << "Enter value: ";
		cin >> value;
		this->add(key, value);
	}
}

int BinaryTree::find(int key) {
	Node * currentNode = this->root;
	while (true) {
		if (currentNode == nullptr)
			return -99;
		if (key == currentNode->getKey())
			return currentNode->getValue();
		if (key > currentNode->getKey())
			currentNode = currentNode->getRightChild();
		else
			currentNode = currentNode->getLeftChild();
	}
}

void BinaryTree::remove(int key) {
	if (this->find(key) == -99) {
		cout << "Key not found" << endl;
		return;
	}
	Node * parent = this->root;
	Node * currentNode = parent;
	Node * replace;
	bool isLeft = false;
	while (true) {

		if (key == currentNode->getKey()) {
			break;
		}
		parent = currentNode;
		if (key > parent->getKey()) {
			isLeft = false;
			currentNode = parent->getRightChild();
		}
		else {
			currentNode = parent->getLeftChild();
			isLeft = true;
		}
	}
	if (currentNode->getChildrenCount() == 0) {
		if (currentNode == this->root) {
			this->root = nullptr;
			return;
		}
		if (isLeft)
			parent->setLeftChild(nullptr);
		else
			parent->setRightChild(nullptr);
	}
	else if (currentNode->getChildrenCount() == 1) {

		if (currentNode->getLeftChild() != nullptr) {
			replace = currentNode->getLeftChild();
			if (currentNode == this->root) {
				this->root = replace;
				return;
			}
			if (isLeft)
				parent->setLeftChild(replace);
			else
				parent->setRightChild(replace);

		}
		else {
			replace = currentNode->getRightChild();
			if (currentNode == this->root) {
				this->root = replace;
				return;
			}
			if (isLeft)
				parent->setLeftChild(replace);
			else
				parent->setRightChild(replace);
		}
			
	}
	else {
		Node* left = currentNode->getLeftChild();
		Node* right = currentNode->getRightChild();
 		Node* replace = right;
		while (replace->getLeftChild() != nullptr) {
			replace = replace->getLeftChild();
		}
		if(replace != left)
		replace->setLeftChild(left);
		if (replace != right)
		replace->setRightChild(right);
		if (currentNode == this->root) {
			this->root = replace;
			return;
		}
		if (isLeft)
			parent->setLeftChild(replace);
		else
			parent->setRightChild(replace);
	}
}

void BinaryTree::preOrder(Node * node) {
	if (node != nullptr) {
		preOrder(node->getLeftChild());
		cout << "Key: " << node->getKey() << " Value: " 
			 << node->getValue() << endl;
		preOrder(node->getRightChild());
	}
}


void BinaryTree::preOrder() {
	cout << "Root: " << this->root->getKey() << endl;
	preOrder(this->root);
}

void BinaryTree::inOrder(Node * node) {
	if (node != nullptr) {
		cout << "Key: " << node->getKey() << " Value: "
			 << node->getValue() << endl;
		inOrder(node->getLeftChild());
		inOrder(node->getRightChild());
	}
}


void BinaryTree::inOrder() {
	cout << "Root: " << this->root->getKey() << endl;
	inOrder(this->root);
}

void BinaryTree::postOrder(Node * node) {
	if (node != nullptr) {
		postOrder(node->getRightChild());
		cout << "Key: " << node->getKey() << " Value: "
			 << node->getValue() << endl;
		postOrder(node->getLeftChild());
	}
}


void BinaryTree::postOrder() {
	cout << "Root: " << this->root->getKey() << endl;
	postOrder(this->root);
}

int BinaryTree::getLeavesCount(Node * node) {
	int count = 0;
	if (node != nullptr) {
		if (node->getChildrenCount() == 0) {
			count++;
		}
		if (node->getLeftChild()!= nullptr) {
			count += getLeavesCount(node->getLeftChild());
		}
		if (node->getRightChild() != nullptr) {
			count += getLeavesCount(node->getRightChild());
		}
	}
	return count;
}

int BinaryTree::getLeavesCount() {
	return getLeavesCount(this->root);
}

void BinaryTree::clean() {
	clean(this->root);
}

void BinaryTree::clean(Node * node) {
	if (node != nullptr) {
		clean(node->getLeftChild());
		clean(node->getRightChild());
		delete node;
	}
}

BinaryTree::~BinaryTree() {
	clean();
}
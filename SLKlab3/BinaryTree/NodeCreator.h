#pragma once
#include "Node.h";
#include <iostream>

using namespace std;
class NodeCreator
{
public:
	static Node * createNode() {
		int key;
		int value;

		cout << "enter key: ";
		cin >> key;
		cout << "enter value: ";
		cin >> value;
		return new Node(key, value);
	}
};


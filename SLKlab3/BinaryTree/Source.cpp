#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
	BinaryTree tree;

	int key, value, point = 0, c = 0;

	while (point != 8) {
		system("cls");

		cout << "0. Add listed nodes" << endl;
		cout << "1. Add node" << endl;
		cout << "2. Find node" << endl;
		cout << "3. Get leaves count" << endl;
		cout << "4. Preorder" << endl;
		cout << "5. Postorder" << endl;
		cout << "6. In order" << endl;
		cout << "7. Delete by key" << endl;
		cout << "8. Exit" << endl << endl;

		cin >> point;
		switch (point) {
		case 0:
			system("cls");
			tree.addList();
			system("pause");
			break;
		case 1:
			system("cls");
			cout << "key: ";
			cin >> key;
			cout << "value: ";
			cin >> value;
			tree.add(key, value);
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "key: ";
			cin >> key;
			if (tree.find(key) != -99) {
				cout << tree.find(key) << endl;
			}
			else {
				cout << "key not found!" << endl;
			}
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "leaves count: " << tree.getLeavesCount() << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			tree.preOrder();
			system("pause");
			break;
		case 5:
			system("cls");
			tree.postOrder();
			system("pause");
			break;
		case 6:
			system("cls");
			tree.inOrder();
			system("pause");
			break;
		case 7:
			system("cls");
			cout << "Choose key to delete: ";
			cin >> c;
			tree.remove(c);
			system("pause");
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
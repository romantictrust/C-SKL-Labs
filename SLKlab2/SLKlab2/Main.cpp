#include <iostream>
#include <ctime>
#include "BoolMatrix.h"
#include "FinalFunction.h"
#include "Helper.h"
using namespace std;

int main() {
	srand(time(0));

	int point = 0, counter = 0, curMatr1 = 0, curMatr2 = 0;
	BoolMatrix* object[20];

	/*BoolMatrix a(5, 7), b(2, 4), c(4, 4), d(4, 4);*/
	/*a.fillMatrix(),
	b.fillMatrix(),
	c.fillMatrix(),
	d.fillMatrix();*/

	// Переделать интерфейс под выбор матрицы чтобы можно было работать с конкретными
	// объектами и заполнять их с клавы !!OK!!


	while (point != 9) {
		system("cls");

		cout << "__________ CHOOSE OPTION __________" << endl
			<< "0.Create object" << endl
			<< "1.Show matrices" << endl
			<< "2.Addition" << endl
			<< "3.Multiplication" << endl
			<< "4.Inverse" << endl
			<< "5.Count units" << endl
			<< "6.Ordering" << endl
			<< "7.Assignment" << endl
			<< "8.Function" << endl
			<< "9.Exit" << endl << endl;

		cin >> point;

		switch (point)
		{
		case 0: {
			system("cls");
			int n = 0, m = 0;
			cout << "Choose n: ";
			cin >> n;
			cout << "Choose m: ";
			cin >> m;
			object[counter] = new BoolMatrix(n, m);
			cin >> *object[counter];
			//object[counter]->createMatrix();
			cout << endl;
			counter++;
			system("pause");
			break;
		}
		case 1: {
			for (int i = 0; i < counter; i++) {
				cout << *object[i] << endl;
			}
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			cout << "--- ADDITION ---" << endl;
			cout << "Choose first matrix: " << endl;
			for (int i = 0; i < counter; i++) {
				cout << endl << i << ".";
				object[i]->showMatrix();
			}
			cout << endl;
			cin >> curMatr1;
			cout << endl << "And another" << endl;
			cin >> curMatr2;
			(*object[curMatr1]) = (*object[curMatr1]) + (*object[curMatr2]);
			object[curMatr1]->showMatrix();
			object[curMatr2]->showMatrix();
			cout << endl;
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			cout << "--- MULTIPLICATION ---" << endl;
			cout << "Choose first matrix: " << endl;
			for (int i = 0; i < counter; i++) {
				cout << endl << i << ".";
				object[i]->showMatrix();
			}
			cout << endl;
			cin >> curMatr1;
			cout << endl << "And another" << endl;
			cin >> curMatr2;
			(*object[curMatr1]) = (*object[curMatr1]) * (*object[curMatr2]);
			object[curMatr1]->showMatrix();
			object[curMatr2]->showMatrix();
			cout << endl;
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			cout << "--- REVERSE MATRIX ---" << endl;
			cout << "Choose matrix: " << endl;
			for (int i = 0; i < counter; i++) {
				cout << endl << i << ".";
				object[i]->showMatrix();
			}
			cout << endl;
			cin >> curMatr1;
			object[curMatr1]->showMatrix();
			--(*object[curMatr1]);
			object[curMatr1]->showMatrix();
			cout << endl;
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			cout << "--- COUNT UNITS ---" << endl;
			cout << "Choose matrix: " << endl;
			for (int i = 0; i < counter; i++) {
				cout << endl << i << ".";
				object[i]->showMatrix();
			}
			cout << endl;
			cin >> curMatr1;
			object[curMatr1]->showMatrix();
			cout << endl << "There are " << (*object[curMatr1]).countUnits() <<
				" units in the matrix" << endl << endl;
			cout << endl;
			system("pause");
			break;
		}
		case 6: {
			system("cls");
			cout << "--- REVERSE MATRIX ---" << endl;
			cout << "Choose  matrix: " << endl;
			for (int i = 0; i < counter; i++) {
				cout << endl << i << ".";
				object[i]->showMatrix();
			}
			cout << endl;
			cin >> curMatr1;
			object[curMatr1]->showMatrix();
			object[curMatr1]->ordering();
			object[curMatr1]->showMatrix();
			cout << endl;
			system("pause");
			break;
		}
		case 7: {
			system("cls");
			cout << "--- MAKE EQUAL ---" << endl;
			cout << "Choose first matrix: " << endl;
			for (int i = 0; i < counter; i++) {
				object[i]->showMatrix();
			}
			cout << endl;
			cin >> curMatr1;
			cout << endl << "And another" << endl;
			cin >> curMatr2;
			object[curMatr1] = object[curMatr2];
			for (int i = 0; i < counter; i++) {
				object[i]->showMatrix();
			}
			cout << endl;
			system("pause");
			break;
		}
		case 8: {
			system("cls");
			cout << "--- FINAL FUNCTION ---" << endl;
			cout << "Choose first matrix: " << endl;
			for (int i = 0; i < counter; i++) {
				cout << endl << i << ".";
				object[i]->showMatrix();
			}
			cout << endl;
			cin >> curMatr1;
			cout << endl << "And another" << endl << endl;
			cin >> curMatr2;
			BoolMatrixWorker::finFunction((*object[curMatr1]),(*object[curMatr2]));
			object[curMatr1]->showMatrix();
			object[curMatr2]->showMatrix();
			cout << endl;
			system("pause");
			break;
		}
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
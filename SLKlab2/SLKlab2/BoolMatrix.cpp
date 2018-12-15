#define _CRT_SECURE_NO_WARNINGS
#include "BoolMatrix.h"
#include <iostream>
#include <ctime>
using namespace std;

BoolMatrix::~BoolMatrix()
{
	if (matrix != NULL) {
		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

int BoolMatrix::getRowNum()const {
	return rows;
};
int BoolMatrix::getCellNum()const {
	return cols;
}

BoolMatrix::BoolMatrix(){
	matrix = nullptr;
	rows = 0;
	cols = 0;
}

BoolMatrix::BoolMatrix(int n, int m) {
	try {
		if (n <= 0) {
			throw 'n';
		}
	}
	catch (char i) {
		cout << "!!! Wrong matrix parameter " << i << " <= 0 !!!" << endl << endl;
	}
	try {
		if (m <= 0) {
			throw 'm';
		}
	}
	catch (char i) {
		cout << "!!! Wrong matrix parameter " << i << " <= 0 !!!" << endl << endl;
	}
		rows = n;
		cols = m;
		matrix = new int*[rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[cols];
		}
}
//validation ok/

/*
void BoolMatrix::createMatrix() {
	cout << "Enter matrix: ";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
			while (matrix[i][j] != 1 && matrix[i][j] != 0) {
				cout << endl << "Sorry, but it's not a binary cell \r" << endl;
				cin >> matrix[i][j];
			}
		}
	}
	cout << endl;
	cout << "Your matrix: ";
	for (int i = 0; i < rows; i++) {
		cout << endl;
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
}
*/

BoolMatrix::BoolMatrix(const BoolMatrix &anotherMatrxObj) {
	rows = anotherMatrxObj.rows;
	cols = anotherMatrxObj.cols;
	matrix = new int*[anotherMatrxObj.rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[anotherMatrxObj.cols];
	}
	for (int i = 0; i < anotherMatrxObj.rows; i++) {
		for (int j = 0; j < anotherMatrxObj.cols; j++) {
			this->matrix[i][j] = anotherMatrxObj.matrix[i][j];
		}
	}
}

void BoolMatrix::fillMatrix() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 2;
		}
	}
}

void BoolMatrix::showMatrix() {
	cout << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

char* BoolMatrix::toString()const {
	int lnth = rows * cols, counter = 0;
	char* string = new char[lnth - 1];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sprintf(&string[counter], "%d", matrix[i][j]);
			counter++;
		}
		strcat(string, "\n");
	}
	return string;
}
//реализовать ok/

int BoolMatrix::countUnits() {
	int counter = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 1)
				counter++;
		}
	}
	return counter;
}
//return amount ok.

void BoolMatrix::ordering() {
	BoolMatrix tmp(rows, cols);
	int sum1 = 1, sum2 = 0;
	int counter = 0;
	for (int i = 0; i < cols; i++) {
		counter++;
		for (int j = 0; j < rows; j++) {
			if (j != rows - 1) {
				if (i != 0) {
					for (int z = 0; z < counter; z++) {
						sum1 += matrix[j][z];
						sum2 += matrix[j + 1][z];
					}
				}
				else sum1 = 1;
			}
			else sum1 = 1;
			if (sum1 == sum2) {
				if (j != rows - 1) {
					int s = 0;
					for (int z = 0; z < counter - 1; z++) {
						if ((matrix[j][z] > matrix[j + 1][z]) || matrix[j][z] == matrix[j + 1][z]) {
							s++;
						}
					}
					if (s == counter) {
						if (matrix[j][i] > matrix[j + 1][i]) {
							for (int k = 0; k < rows; k++) {
								tmp.matrix[j + 1][k] = matrix[j + 1][k];
								matrix[j + 1][k] = matrix[j][k];
								matrix[j][k] = tmp.matrix[j + 1][k];
							}
							j = -1;
						}
						sum1 = 0;
						sum2 = 0;
					}
				}
			}
			if (sum2<sum1) {
				if (j != rows - 1) {
					int s = 0;
					if (i != 0) {
						for (int z = 0; z < counter; z++) {
							if ((matrix[j][z] > matrix[j + 1][z]) || matrix[j][z] == matrix[j + 1][z]) {
								s++;
							}
						}
					}
					else s = counter;
					if (s == counter) {
						if (matrix[j][i] > matrix[j + 1][i]) {
							for (int k = 0; k < rows; k++) {
								tmp.matrix[j + 1][k] = matrix[j + 1][k];
								matrix[j + 1][k] = matrix[j][k];
								matrix[j][k] = tmp.matrix[j + 1][k];
							}
							j = -1;
						}
					}
					sum1 = 0;
					sum2 = 0;
				}
				sum1 = 0;
				sum2 = 0;
			}
			else {
				sum1 = 0;
				sum2 = 0;
			}
		}
	}
}


BoolMatrix BoolMatrix::operator =(const BoolMatrix &anotherMatrxObj) {
	if (this != &anotherMatrxObj) {
		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		this->rows = anotherMatrxObj.rows;
		this->cols = anotherMatrxObj.cols;
		this->matrix = new int*[anotherMatrxObj.rows];
		for (int i = 0; i < anotherMatrxObj.rows; i++) {
			this->matrix[i] = new int[anotherMatrxObj.cols];
		}
		for (int i = 0; i < anotherMatrxObj.rows; i++) {
			for (int j = 0; j < anotherMatrxObj.cols; j++) {
				this->matrix[i][j] = anotherMatrxObj.matrix[i][j];
			}
		}
	}
	return *this;
}
//method ok/
BoolMatrix BoolMatrix::operator +(const BoolMatrix &anotherMatrxObj) {
	BoolMatrix temp(rows, cols);
	if (this->rows == anotherMatrxObj.rows && this->cols == anotherMatrxObj.cols) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (this->matrix[i][j] == 1 && anotherMatrxObj.matrix[i][j] == 1)
					temp.matrix[i][j] = 1;
				else temp.matrix[i][j] = this->matrix[i][j] + anotherMatrxObj.matrix[i][j];
			}
		}
		return temp;
	}
	else {
		cout << "Wrong matrices" << endl;
		return *this;
	}
}
//method ok/
BoolMatrix BoolMatrix::operator *(const BoolMatrix &anotherMatrxObj) {
	BoolMatrix temp(this->rows, anotherMatrxObj.cols);
	if (this->cols == anotherMatrxObj.rows) {
		for (int i = 0; i <this->rows; i++) {
			for (int j = 0; j < anotherMatrxObj.cols; j++) {
				temp.matrix[i][j] = 0;
				for (int k = 0; k < anotherMatrxObj.rows; k++) {
					temp.matrix[i][j] += this->matrix[i][k] * anotherMatrxObj.matrix[k][j];
					if (temp.matrix[i][j] == 1) k = anotherMatrxObj.rows;
				}
			}
		}
		return temp;
	}
	else {
		cout << "Wrong matrices" << endl;
		return *this;
	}
}
//method ok/
BoolMatrix BoolMatrix::operator --() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			//if (this->matrix[i][j] == 1)
			//	this->matrix[i][j] = 0;
			//else this->matrix[i][j] = 1;
			matrix[i][j] = !matrix[i][j];
		}
	}
	return *this;
}

BoolMatrix BoolMatrix::operator +=(const BoolMatrix &anotherMatrxObj) {
	*this = *this + anotherMatrxObj;
	return *this;
}

BoolMatrix BoolMatrix::operator *=(const BoolMatrix &anotherMatrxObj) {
	*this = *this * anotherMatrxObj;
	return *this;
}

BoolMatrix BoolMatrix::operator ++() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == 0) matrix[i][j] = 1;
		}
	}
	return *this;
}

BoolMatrix BoolMatrix::operator *() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == 0) matrix[i][j] *= 1;
		}
	}
	return *this;
}

// Перегруженный оператор ничего не делает, но он есть ¯\_(ツ)_/¯ 

BoolMatrix BoolMatrix::turnEqual (const BoolMatrix &anotherMatrxObj) {
	*this = anotherMatrxObj;
	return *this;
}

BoolMatrix BoolMatrix::sumMatrix(const BoolMatrix &anotherMatrxObj) {
	*this = *this + anotherMatrxObj;
	return *this;
}

BoolMatrix BoolMatrix::multiplyMatrix(const BoolMatrix &anotherMatrxObj) {
	*this = *this * anotherMatrxObj;
	return *this;
}

istream& operator >> (istream& is, BoolMatrix &m) {
	Helper ch;
	int rows = m.getRowNum();
	int cols = m.getCellNum();
	cout << "Enter matrix: ";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			m.matrix[i][j] = ch.intEnter();
			while (m.matrix[i][j] != 1 && m.matrix[i][j] != 0) {
				cout << endl << "Sorry, but it's not a binary cell \r" << endl;
				m.matrix[i][j] = ch.intEnter();
			}
		}
	}
	cout << endl;
	cout << "Your matrix: ";
	m.showMatrix();
	return is;
}

ostream& operator<<(ostream& os, const BoolMatrix&m) {
	for (int i = 0; i<m.getRowNum(); i++)
	{
		for (int j = 0; j<m.getCellNum(); j++)
			os << m(i, j) << " ";
		os<< "\n";
	}
	return os;
}

int& BoolMatrix::operator()(int row, int col){                            
	return (matrix[row][col]);
}

int BoolMatrix::operator()(int row, int col) const{                             
	return (matrix[row][col]);  
}
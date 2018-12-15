#pragma once
#include <iostream>
#include "Helper.h"
using namespace std;

class BoolMatrix
{
private: 
	int rows, cols;
	int **matrix;

public:
	BoolMatrix();
	BoolMatrix(int n, int m);
	BoolMatrix(const BoolMatrix &anotherMatrxObj);

	int getRowNum()const;
	int getCellNum()const;

	void createMatrix();
	void fillMatrix();
	void showMatrix();
	int countUnits();
	char* toString()const;
	void ordering();

	BoolMatrix operator =(const BoolMatrix &anotherMatrxObj);
	BoolMatrix operator +(const BoolMatrix &anotherMatrxObj);
	BoolMatrix operator *(const BoolMatrix &anotherMatrxObj);

	BoolMatrix operator +=(const BoolMatrix &anotherMatrxObj);
	BoolMatrix operator *=(const BoolMatrix &anotherMatrxObj);

	BoolMatrix operator --();
	BoolMatrix operator ++();
	BoolMatrix operator *();
	
	BoolMatrix turnEqual(const BoolMatrix &anotherMatrxObj);
	BoolMatrix sumMatrix(const BoolMatrix &anotherMatrxObj);
	BoolMatrix multiplyMatrix(const BoolMatrix &anotherMatrxObj);

	~BoolMatrix();

	friend istream & operator >> (istream&, BoolMatrix&);
	friend ostream& operator<<(ostream& os, const BoolMatrix&);

	int& operator()(int, int);
	int operator()(int, int) const;
};


#define _CRT_SECURE_NO_WARNINGS
#include "FinalFunction.h"
#include <iostream>
using namespace std;

BoolMatrix& BoolMatrixWorker::finFunction(BoolMatrix first, BoolMatrix second){
	if (first.getRowNum() != second.getRowNum() && first.getCellNum() != second.getCellNum()) {
		cout << endl << "Matrices have different dimensions";
	}
	else {/*
		cout << endl << "First matrix" << " : ";
		first.showMatrix();
		--first;
		cout << endl << "Inverse first matrix" << " : ";
		first.showMatrix();
		cout << endl << "Second matrix" << " : " << endl;
		second.showMatrix();
		--second;
		cout << endl << "Inverse second matrix" << " : ";
		second.showMatrix();
		cout << endl << "Binary sum: ";
		first = first + second;
		first.showMatrix();
		BoolMatrix tmp(first.getRowNum(), first.getCellNum());
		tmp = first;
		return tmp;*/

		// Нужно короче:
		first = --first + --second;
		return first;
	}
}


BoolMatrixWorker::~BoolMatrixWorker()
{
}

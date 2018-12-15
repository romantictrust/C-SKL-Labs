#pragma once
#include <iostream>
#include "BoolMatrix.h"

class BoolMatrixWorker
{
public:
	static BoolMatrix& finFunction(BoolMatrix first, BoolMatrix second);
	BoolMatrixWorker();
	~BoolMatrixWorker();
};


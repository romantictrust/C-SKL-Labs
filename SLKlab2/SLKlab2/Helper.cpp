#include "Helper.h"
#include <iostream>
using namespace std;

Helper::Helper()
{
}


Helper::~Helper()
{
}

int Helper::intEnter() {
	int n;
	cin >> n;
	while (cin.fail()) {
		cin.clear();
		char c;
		cin >> c;
		cin >> n;
	}
	
	return n;
}


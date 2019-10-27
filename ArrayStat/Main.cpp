#include "ArrayStat.h"
#include "VecArrayStat.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ArrayStat arr("Input.txt");
	arr.print();
	VecArrayStat varr("Input.txt");
	varr.print();
	system("pause");
	return 0;
}
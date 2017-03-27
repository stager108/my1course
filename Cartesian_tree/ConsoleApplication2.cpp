// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "algorithm"
#include "Header1.h"
#include "IStructure.h"
#include "Header2.h"
#include "Tester.h"
int main()
{
	bool result = false;
	MyStrangeTest Tester;
	CartesianTree Tree1;
	StupidTree Tree2;
	//result = Tester.ToTest(dynamic_cast<IStructure*>(&Tree1), dynamic_cast<IStructure*>(&Tree2));
	int a[10];
	for (int i = 0; i < 7; i++)a[i] = i;
	a[7] = 10;
	a[8] = 10;
	a[9] = 8;
	Tree1.Create(a,10);
	Tree2.Create(a, 10);
	for (int j = 0; j < 30; j++) {
		Tree1.NextPermutation(0, 10);
		Tree2.NextPermutation(0, 10);
	}

	std::cout << result;
	return 0;
}




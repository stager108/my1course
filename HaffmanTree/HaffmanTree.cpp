// HaffmanTree.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <fstream>
//#include <cstdio>
#include <clocale>
#include <stdio.h>
#include <iostream>
#include <ios>
#include <stack>
#include "myheap.h"
#include "cinbitstream.h"
#include "coutbitstream.h"

#include "haffmancoder.h"
#include "haffmandecoder.h"

int main()
{
	setlocale(LC_ALL, "ru");
	HaffmanCoder A;
	HaffmanDecoder B;
	int e;
	std::cin >> e;
	if (e == 0) { A.CodeFile(); }
	else { B.DecodeFile(); }
	std::cin >> e;
    return 0;
}


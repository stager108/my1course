#pragma once
#pragma once
#include "stddef.h"
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
class IStructure {
public:
	virtual void Insert(int pos, int key) = 0;
	virtual void Create(int* arr, int count) = 0;
	virtual void ChangeKey(int pos, int key) = 0;
	virtual int SubSumma(int l, int r) = 0;
	virtual void NextPermutation(int l, int r) = 0;
	virtual ~IStructure() {}
};
#pragma once
#include "stddef.h"
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
template <typename T>
class IHeap {
public:
	virtual int Min() const = 0;
	virtual void Insert(int key) = 0;
	virtual void ExtractMin() = 0;
	virtual T* Meld(T* &index1, T* &index2) = 0;
	virtual ~IHeap() {}
};
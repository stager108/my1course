#pragma once
#include "stddef.h"
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
class IHeap {
public:
	virtual int Min() const = 0;
	virtual void Insert(int key) = 0;
	virtual void ExtractMin() = 0;
	virtual void Meld(std::shared_ptr<IHeap> &other) = 0;
	virtual ~IHeap() {}
};
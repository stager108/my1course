#pragma once
#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "algorithm"
#include <vector>
#include <algorithm>
#include "IStructure.h"
#include <functional>
#include <numeric> 

class StupidTree : public IStructure {
private:
	std::vector<int> myArray;
public:
	StupidTree() {}
	~StupidTree() {}

	void Create(int* Arr, int count) {
		for (int i = 0; i < count; i++) {
			myArray.push_back(Arr[i]);
		}
	}
	void ChangeKey(int pos, int key) {
		myArray[pos] = key;
	}
	void Insert(int pos, int key) {
		myArray.insert(myArray.begin() + pos, key);
	}
	void NextPermutation(int l, int r) {
		std::next_permutation(myArray.begin() + l, myArray.begin() + r);
		WriteTree();
		std::cout << "\n";
	}
	void WriteTree() {
		for (int i = 0; i < myArray.size(); i++)
			std::cout << myArray[i] << " ";
	}
	int SubSumma(int l, int r) {
		return std::accumulate(myArray.begin() + l, myArray.begin() + r, 0, std::plus<int>());
		
	
	}
};
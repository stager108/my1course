#pragma once
#include "IStructure.h"
#include <cstdlib>
#include <ctime>
class MyStrangeTest {
	enum TestNumbers { Change = 0, Insert = 1, Sum = 2, NPerm = 3 };
public:
	MyStrangeTest() {}
	~MyStrangeTest() {}

	std::vector<int> GenerateTest(int count, int l, int r) {
		std::vector<int> result;
		int a, b, rr;
		r--;
		r = r - l;
		for (int i = 0; i < count; i++) {
			rr = rand();
			result.push_back(rr);
			a = rand() % r + l;
			
			b = rand() % r + l;
			if ((rr % 4 > 1) && (a > b)) { std::swap(a, b); }
			result.push_back(a);
			result.push_back(b);
		}

		return result;
	}
	bool ToTest(IStructure* S1, IStructure* S2) {
		bool ok = true;
		std::vector<int> result1;
		std::vector<int> result2;
		std::vector<int> test;
		srand(clock());
		int r = abs(rand())+10000;
		int rr = r;
		//std::cout << r;
		int a = rand();
		int b = rand();
		if (a > b)std::swap(a, b);
		test = GenerateTest(r, a, b);


		int* c = new int[b];
		for (int j = 0; j < b; j++) {
			c[j] = rand();
		}
		S1->Create(c, b);
		S2->Create(c, b);
		for (int i = 0; i < rr; i++) {
			r = test[3 * i];
			a = test[3 * i + 1];
			b = test[3 * i + 2];
			switch (r % 4) {
			case Change: S1->ChangeKey(a, b); S2->ChangeKey(a, b);	break;
			case Insert: S1->Insert(a, b); S2->Insert(a, b); break;
			case Sum: result1.push_back(S1->SubSumma(a, b)); result2.push_back(S2->SubSumma(a, b)); break;
			default:  S1->NextPermutation(a, b); S2->NextPermutation(a, b); break;
			}
		}
			for (int i = 0; i < result1.size(); i++) {
				ok = ok && (result1[i] == result2[i]);
			}
			for (int i = 0; i < result2.size(); i++) {
				ok = ok && (result1[i] == result2[i]);
			}
		
		delete c;
		std::cout << result1.size() << '\n';
		std::cout << result2.size() << '\n';
		return ok;
	}
};
#pragma once
#include "BinomialHeap.h"
#include "LeftistHeap.h"
#include "SkewHeap.h"
#include "HeapTester.h"
#include "mytestheader.h"
#include <gtest.h>
#include <queue>

enum TestNumbers { Add = 0, Insert = 1, Meld = 2 };

int MyRand() {
	return rand()*rand();
}
std::vector<int> GenerateTest() {
	std::vector<int> TestSequence;
	int r, a, b;
	for (int i = 0; i < 40000; i++) {
		r = rand() % 6;
		a = MyRand();
		b = MyRand();
		TestSequence.push_back(r);
		switch (r) {
		case Add: TestSequence.push_back(a);	break;
		case Insert: TestSequence.push_back(a); TestSequence.push_back(b); break;
		case Meld: TestSequence.push_back(a); TestSequence.push_back(b); break;
		default:TestSequence.push_back(a); break;
		}
	}
	for (int i = 0; i < 3000; i++) {
		r = rand() % 110;
		a = MyRand();
		b = MyRand();
		TestSequence.push_back(r);
		switch (r) {
		case Add: TestSequence.push_back(a);	break;
		case Insert: TestSequence.push_back(a); TestSequence.push_back(b); break;
		case Meld: TestSequence.push_back(a); TestSequence.push_back(b); break;
		default:TestSequence.push_back(a); break;
		}
	}
	return TestSequence;
}
template <class C>
std::vector<int> MyVectorAnswer(std::vector<int> &Tests){
	MyStrangeTest <C> TestHeap;
	std::vector <int> Answers;
	double time;
	time = clock();
	int r, a, b, min;
	r = 0;
	while (r < Tests.size()) {
		switch (Tests[r]) {
		case Add: 
			TestHeap.AddHeap(Tests[r + 1]);
			r += 2;
			break;
		case Insert: 
			TestHeap.Insert(Tests[r + 1], Tests[r + 2]);
			r += 3;
			break;
		case Meld:
			TestHeap.Meld(Tests[r + 1], Tests[r + 2]);
			r += 3;
			break;
		default:
			min = TestHeap.ExtractMin(Tests[r + 1]);
			r+=2;
			Answers.push_back(min);
			break;
		}
	}
	return Answers;
}

std::vector<int> GetRightAnswer(std::vector <int> &Tests) {
	std::vector <std::priority_queue <int>> Ans;
	std::vector <int> Answers;
	std::priority_queue <int>* NewHeap = nullptr;
	int r = 0, a = 0, b = 0, min = 0;
	while (r < Tests.size()) {
		switch (Tests[r]) {
		case Add:
			a = Tests[r + 1];
			//NewHeap = new std::priority_queue <int>;
			Ans.push_back(std::priority_queue <int>());
			Ans.back().push(-a);
			r += 2;
			NewHeap = nullptr;
			break;
		case Insert:
			if (Ans.size()>0) {
				a = Tests[r + 1];
				b = Tests[r + 2];
				a %= Ans.size();
				Ans[a].push(-b);
			}
			r += 3;
			break;
		case Meld:
			if (Ans.size() > 0) {
				a = Tests[r + 1];
				b = Tests[r + 2];
				a %= Ans.size();
				b %= Ans.size();
				if (a != b){
					while (!(Ans[b].empty())) {
						min = Ans[b].top();
						Ans[b].pop();
						Ans[a].push(min);
					}
					std::swap(Ans[b], Ans.back());
					Ans.pop_back();
				}
			}
			r += 3;
			break;
		default:
			min = 0;
			if (Ans.size() > 0) {
				a = Tests[r + 1];
				a %= Ans.size();
				if (!Ans[a].empty()) { min = -Ans[a].top();
				}
				else {
					min = 0; 
				}
				if(!Ans[a].empty())Ans[a].pop();
				
			}
			Answers.push_back(min);
			r += 2;
			break;
		}
	}
	return Answers;
}

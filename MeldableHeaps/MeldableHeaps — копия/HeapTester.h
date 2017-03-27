#pragma once
template <class C>
class MyStrangeTest {
	std::vector <C*> TestVector;

	MyStrangeTest() {}
	~MyStrangeTest() {}

	void AddHeap(int key) {
		C* NewHeap = new C;
		NewHeap.Insert(key);
		TestVector.push_back(NewHeap);
	}

	void Insert(C* index, int key) {
		TestVector[index]->Insert(key);
	}

	void ExtractMin(C* index, int key) {
		key = TestVector[index]->ExtractMin();
	}

	void Meld(C* index1, C* index2) {
		index1 = Meld(TestVector[index1]->Root, TestVector[index2]->Root);
		TestVector[index2] = TestVector[TestVector.size() - 1];
		TestVector.pop_back();
	}
};
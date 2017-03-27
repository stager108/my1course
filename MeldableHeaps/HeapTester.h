#pragma once
template <class C>
class MyStrangeTest {
public:
	std::vector <std::shared_ptr<C>> TestVector;
	//std::vector<int> result;
	MyStrangeTest() {}
	~MyStrangeTest() {
		//for (int i = 0; i < TestVector.size(); i++)
			//delete TestVector[i];
		TestVector.clear();
	//	result.clear();
		
	}

	void AddHeap(int key) {
		std::shared_ptr <C> NewHeap(new C);
		NewHeap->Insert(key);
		TestVector.push_back(NewHeap);
	}

	void Insert(int index, int key) {
		if (TestVector.size() > 0) {
			index %= TestVector.size();
			TestVector[index]->Insert(key);
		}
	}

	int ExtractMin(int index) {
		int ans = 0;
		if (TestVector.size() > 0) {
			index %= TestVector.size();
			ans = (TestVector[index]->Min());
			TestVector[index]->ExtractMin();
		}
		return ans;
	}

	void Meld(int index1, int index2) {
		if (TestVector.size() > 0) {
			index1 %= TestVector.size();
			index2 %= TestVector.size();
			if (index1 != index2) {
				TestVector[index1]->Meld(TestVector[index2]);
				std::swap(TestVector[index2], TestVector.back());
				TestVector.pop_back();
			}
		}
	}

	void MyStrangeTestClear() {
		//for (int i = 0; i < TestVector.size(); i++)
			//if(TestVector[i] != nullptr )delete TestVector[i];
		TestVector.clear();
	}
};
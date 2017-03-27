#pragma once
#include "IHeap.h"

struct BNode {
	~BNode() {
		delete child;
		delete brother;
		delete parent;
	}
	int value = 0;
	int rang = 0;
	BNode* brother = nullptr;
	BNode* child = nullptr;
	BNode* parent = nullptr;
};

class BinomialHeap : public IHeap <BNode> {
	//private:
public:
	BNode* Root;
	int MaxTree = 1;
	BinomialHeap() {}
	~BinomialHeap() {}
	//BinomialHeap(BinomialHeap* OldHeap) {}//copy

	//BinomialHeap(BinomialHeap* &&OldHeap) {
	//Forest = OldHeap->Forest;
	//}//move

	void Insert(int key) override {
		BNode* N = new BNode;
		N->value = key;
		N->rang = 0;
		Root = Meld(Root, N);
	}


	BNode* Meld(BNode* &index1, BNode* &index2) {
		if (index1 == nullptr) {
			std::swap(index1, index2);
			return index1;
		}
		if (index2 == nullptr) return index1;
		BNode* NewHeap;
		BNode* NewHeapBegin;

		NewHeapBegin = UnionHeap(index1, index2);

		NewHeap = NewHeapBegin;
		while (NewHeap != nullptr) {
			if (NewHeap->brother != nullptr) {
				if (NewHeap->brother->rang == NewHeap->rang) {
					if ((NewHeap->brother->brother != nullptr) && (NewHeap->brother->brother->rang == NewHeap->rang)) {
						NewHeap = NewHeap->brother;
					}
					if (NewHeap->value > NewHeap->brother->value) {
						std::swap(NewHeap->value, NewHeap->brother->value);
						std::swap(NewHeap->child, NewHeap->brother->child);
					}
					BNode* Next = NewHeap->brother->brother;
					NewHeap = SmallMeld(NewHeap, NewHeap->brother);
					NewHeap->brother = Next;
				}
			}
			if ((NewHeap->brother == nullptr) || (NewHeap->rang != NewHeap->brother->rang)) NewHeap = NewHeap->brother;
		}
		return NewHeapBegin;
	}

	BNode* UnionHeap(BNode* index1, BNode* index2) {
		BNode* NewHeap;
		BNode* NewHeapBegin;
		if (index1->rang < index2->rang) {
			NewHeapBegin = index1;
			index1 = index1->brother;
		}
		else {
			NewHeapBegin = index2;
			index2 = index2->brother;
		}
		NewHeap = NewHeapBegin;
		while ((index1 != nullptr) && (index2 != nullptr)) {
			if (index2->rang >= index1->rang) {
				NewHeap->brother = index1;
				NewHeap = NewHeap->brother;
				index1 = index1->brother;
			}
			else {
				NewHeap->brother = index2;
				NewHeap = NewHeap->brother;
				index2 = index2->brother;
			}
		}
		if (index1 != nullptr) {
			NewHeap->brother = index1;
		}
		else {
			NewHeap->brother = index2;
		}
		NewHeap = nullptr;
		return NewHeapBegin;
	}
	BNode* SmallMeld(BNode* &index1, BNode* &index2) {
		index2->brother = index1->child;
		index1->child = index2;
		index1->rang++;
		return index1;
	}
	void PrintForest() {
		BNode* PrintNode = Root;
		while (PrintNode != nullptr) {
			std::cout << PrintNode->value << " ";
			PrintNode = PrintNode->brother;
		}
		std::cout << std::endl;
	}
	int Min() const {
		BNode* min = Root;
		BNode* Next = Root;
		while (Next != nullptr) {
			if ((Next->value < min->value)) {
				min = Next;
			}
			Next = Next->brother;
		}
		if (min == nullptr) { return 0; }
		else {
			return min->value;
		}
	}
	BNode* Min1(BNode* &Previous) {
		BNode* min = Root;
		BNode* Next = Root;
		BNode* Answer = min;
		BNode* Prev = nullptr;
		if (Next != nullptr) {
			while (Next != nullptr) {
				if ((Next->value < min->value)) {
					min = Next;
					Previous = Prev;
				}
				Prev = Next;
				Next = Next->brother;
			}
		}
		return Answer;
	}
	void ExtractMin() {
		BNode* Previous = nullptr;
		BNode* Next = Min1(Previous);
		BNode* Medium;

		if (Next != nullptr) {

			if (Previous != nullptr) {
				Previous->brother = Next->brother;
			}
			else {
				Root = Next->brother;
			}

			BNode* NextNode = Next;

			Next->brother = nullptr;

			std::vector <BNode*> List;
			Next = Next->child;
			while (Next != nullptr) {
				List.push_back(Next);
				Next = Next->brother;
			}
			BNode* LittleHeap = nullptr;
			std::reverse(List.begin(), List.end());
			if (List.size() > 0) {
				for (int i = 1; i < List.size(); i++) {
					List[i - 1]->brother = List[i];
				}
				List[List.size() - 1]->brother = nullptr;
			}
			else {
				List.push_back(nullptr);
			}

			if (List.size() > 0) { Root = Meld(Root, List[0]); }
		}
	}
};

#pragma once
#include "IHeap.h"

class BinomialHeap : public IHeap {
private:
	struct BinomialHeapNode {
		int value = 0;
		int rang = 0;
		std::shared_ptr <BinomialHeapNode> brother = nullptr;
		std::shared_ptr <BinomialHeapNode> child = nullptr;
	};
	std::shared_ptr <BinomialHeapNode> UnionHeap(std::shared_ptr <BinomialHeapNode> &index1, std::shared_ptr <BinomialHeapNode> &index2) {
		if (index1 == nullptr) return index2;
		if (index2 == nullptr) return index1;
		std::shared_ptr <BinomialHeapNode> NewHeap;
		std::shared_ptr <BinomialHeapNode> NewHeapBegin;
		if (index1->rang < index2->rang) {
			NewHeapBegin = index1;
			index1 = NewHeapBegin->brother;
		}
		else {
			NewHeapBegin = (index2);
			index2 = NewHeapBegin->brother;
		}
		NewHeap = NewHeapBegin;
		while ((index1 != nullptr) && (index2 != nullptr)) {
			if (index2->rang >= index1->rang) {
				NewHeap->brother = index1;
				NewHeap = NewHeap->brother;
				index1 = index1->brother;
			}
			else {
				NewHeap->brother =  (index2);
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
		//NewHeap = nullptr;
		return NewHeapBegin;
	}

	std::shared_ptr <BinomialHeapNode>& SmallMeld(std::shared_ptr <BinomialHeapNode> &index1, std::shared_ptr <BinomialHeapNode> &index2) {
		index2->brother = index1->child;
		index1->child = index2;
		index1->rang++;
		return index1;
	}

	void PrintForest() {
		std::shared_ptr <BinomialHeapNode> PrintNode =  (Root);
		while (PrintNode != nullptr) {
			std::cout << PrintNode->value << " ";
			PrintNode = PrintNode->brother;
		}
		std::cout << std::endl;
	}

	std::shared_ptr <BinomialHeapNode> Min1(std::shared_ptr <BinomialHeapNode> &Previous) {
		std::shared_ptr <BinomialHeapNode> min = Root;
		std::shared_ptr <BinomialHeapNode> Next = Root;
		std::shared_ptr <BinomialHeapNode> Prev = nullptr;
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
		return min;
	}
protected:
	std::shared_ptr <BinomialHeapNode> Root;
public:

	explicit BinomialHeap() {}
	~BinomialHeap() {
		//DeleteBinomialHeapNode(Root);
		//delete Root;
	}
	//BinomialHeap(BinomialHeap* OldHeap) {}//copy

	//BinomialHeap(BinomialHeap* &&OldHeap) {
	//Forest = OldHeap->Forest;
	//}//move

	void Insert(int key) override {
		std::shared_ptr <BinomialHeapNode> New(new BinomialHeapNode);
		New->value = key;
		New->rang = 0;
		Root = subMeld(Root, New);
	}


	std::shared_ptr<BinomialHeapNode> subMeld(std::shared_ptr<BinomialHeapNode> &index1, std::shared_ptr<BinomialHeapNode> &index2) {
		if (index1 == nullptr) {
			return index2;
		}
		if (index2 == nullptr) { 
			return index1;
		}
		std::shared_ptr<BinomialHeapNode> NewHeap;
		std::shared_ptr<BinomialHeapNode> NewHeapBegin;

		NewHeap = UnionHeap(index1, index2);

		NewHeapBegin = NewHeap;
		while (NewHeap != nullptr) {
			if (NewHeap->brother != nullptr) {
				if (NewHeap->brother->rang == NewHeap->rang) {
					if ((NewHeap->brother->brother != nullptr) && (NewHeap->brother->brother->rang == NewHeap->rang)) {
						NewHeap =  (NewHeap->brother);
					}
					if (NewHeap->value > NewHeap->brother->value) {
						std::swap(NewHeap->value, NewHeap->brother->value);
						std::swap(NewHeap->child, NewHeap->brother->child);
					}
					std::shared_ptr<BinomialHeapNode> Next = NewHeap->brother->brother;
					NewHeap = SmallMeld(NewHeap, NewHeap->brother);
					NewHeap->brother = Next;
				}
			}
			if ((NewHeap->brother == nullptr) || (NewHeap->rang != NewHeap->brother->rang)) NewHeap = NewHeap->brother;
		}
		return NewHeapBegin;
	}

	
	void Meld(std::shared_ptr<BinomialHeap> &other)
	{
		//BinomialHeap* tmp = dynamic_cast<BinomialHeap*>(other);
		Root = subMeld(Root, other->Root);
		other->Root = nullptr;
		//return this;
	}

	virtual void Meld(std::shared_ptr <IHeap> &other)
	{
		//std::shared_ptr <BinomialHeap> tmp =  (dynamic_cast<std::shared_ptr<BinomialHeap>>(other));
		//Root =  (subMeld(Root, tmp->Root));
		//tmp->Root = nullptr;
	}
	int Min() const {
		std::shared_ptr <BinomialHeapNode> min = Root;
		std::shared_ptr <BinomialHeapNode> Next = Root;
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

	void ExtractMin() {
		std::shared_ptr <BinomialHeapNode> Previous = nullptr;
		std::shared_ptr <BinomialHeapNode> Next = Min1(Previous);

		if (Next != nullptr) {

			if (Previous != nullptr) {
				Previous->brother = Next->brother;
			}
			else {
				Root =  (Next->brother);
			}
			std::shared_ptr <BinomialHeapNode> NextNode = Next;
			std::vector <std::shared_ptr <BinomialHeapNode>> List;
			Next = Next->child;
			while (Next != nullptr) {
				List.push_back(Next);
				Next = Next->brother;
			}
			std::reverse(List.begin(), List.end());
			if (List.size() > 0) {
				for (int i = 1; i < List.size(); i++) {
					List[i - 1]->brother = List[i];
				}
				List.back()->brother = nullptr;
			}
			else {
				List.push_back(nullptr);
			}
			if (List.size() > 0) { Root = subMeld(Root, List[0]); }
			List.clear();
			NextNode->brother = nullptr;
			NextNode->child = nullptr;
		}
	}
};

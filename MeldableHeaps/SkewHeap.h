#pragma once
#include "BaseHeap.h"
struct SkewHeapNode {
	int value = 0;
	std::shared_ptr <SkewHeapNode> left = nullptr;
	std::shared_ptr <SkewHeapNode> right = nullptr;
};

class SkewHeap : public BaseHeap <SkewHeapNode> {
protected:
	void ChildrenSwap(std::shared_ptr <SkewHeapNode> &index1) {
		std::swap(index1->right, index1->left);
	}

public:

	SkewHeap() : BaseHeap() {}

	~SkewHeap() {}
    void Meld(std::shared_ptr<SkewHeap> &other){
		Root = subMeld(Root, other->Root);
		other->Root = nullptr;
	}

};
/*std::shared_ptr <SkewHeapNode>& subMeld(std::shared_ptr <SkewHeapNode> &index1, std::shared_ptr <SkewHeapNode> &index2) {
if (index1 == nullptr) {
return index2;
}
if (index2 == nullptr) {
return index1;
}
if (index1->value > index2->value)
std::swap(index1, index2);
index1->right = (subMeld(index2, index1->right));
std::swap(index1->right, index1->left);
return index1;
}*/
/*
class SkewHeap : public LeftistHeap {
private:
	struct Node {
		~Node() {
			delete left;
			delete right;
		}
		int value = 0;
		Node* left = nullptr;
		Node* right = nullptr;
	};

public:
	Node* Root = nullptr;
	SkewHeap() {}
	~SkewHeap() {
	delete Root;
	}
	//SkewHeap(SkewHeap* OldHeap) {}//copy

	//	SkewHeap(SkewHeap* &&OldHeap) {
	//		Root = OldHeap->Root;
	//	}//move

protected:
	Node* subMeld(Node* &index1, Node* &index2) {
	    if (index1 == nullptr) {
	        return index2;
     	}
	    if (index2 == nullptr) {
	        return index1;
	    }
	    if (index1->value > index2->value)
	        std::swap(index1, index2);
        index1->right = subMeld(index2, index1->right);
	    std::swap(index1->right, index1->left);
	    return index1;
	}


	};
*/
/*
class SkewHeap : public IHeap {
	private:
	struct Node {
		~Node() {
			delete left;
			delete right;
		}
		int value = 0;
		Node* left = nullptr;
		Node* right = nullptr;
	};
public:
	SkewHeap() {}
	~SkewHeap() {
		//DeleteNode(Root);
		delete Root;
	}
	//SkewHeap(SkewHeap* OldHeap) {}//copy

	//	SkewHeap(SkewHeap* &&OldHeap) {
	//		Root = OldHeap->Root;
	//	}//move

	void Insert(int key) {
		Node* N = new Node;
		N->value = key;
		Root = subMeld(Root, N);
	}

	virtual void Meld(IHeap* other)
	{
		SkewHeap* tmp = dynamic_cast<SkewHeap*>(other);
		Root = subMeld(Root, tmp->Root);
		tmp->Root = nullptr;
		//return this;
	}

	int Min() const {
		if (Root != nullptr) {
			return Root->value;
		}
		else return 0;
	}

	void ExtractMin() {
		Node* DeLeftistHeapNode = Root;
		if (Root != nullptr) {
			Root = subMeld(Root->left, Root->right);
			DeLeftistHeapNode->left = nullptr;
			DeLeftistHeapNode->right = nullptr;
			delete DeLeftistHeapNode;
		}
	}
private:
	Node* subMeld(Node* &index1, Node* &index2) {
		if (index1 == nullptr) {
			return index2;
		}
		if (index2 == nullptr) {
			return index1;
		}
		if (index1->value > index2->value)
			std::swap(index1, index2);
		index1->right = subMeld(index2, index1->right);
		std::swap(index1->right, index1->left);
		return index1;
	}

	Node* Root = nullptr;
};*/
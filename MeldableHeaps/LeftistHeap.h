#pragma once
#include "BaseHeap.h"

struct LeftistHeapNode {
	int value = 0;
	int rang = 0;
	std::shared_ptr <LeftistHeapNode> left = nullptr;
	std::shared_ptr <LeftistHeapNode> right = nullptr;
};

class LeftistHeap : public BaseHeap <LeftistHeapNode> {
protected:
	 void ChildrenSwap(std::shared_ptr <LeftistHeapNode> &index1) {
		if ((index1->right != nullptr) && (index1->left != nullptr)) {
			index1->rang = std::min(index1->right->rang, index1->left->rang) + 1;
			if ((index1->right->rang) > (index1->left->rang))
				std::swap(index1->right, index1->left);
		}
		else {
			if (index1->right != nullptr)std::swap(index1->right, index1->left);
		}
	}
public:

	LeftistHeap(): BaseHeap() {}

	~LeftistHeap(){}
	
	virtual void Meld(std::shared_ptr<LeftistHeap> &other)
	{
	//	LeftistHeap* tmp = dynamic_cast<LeftistHeap*>(other);
		Root =  ( subMeld(Root, other->Root));
		other->Root = nullptr;
	}
	
};
/*virtual std::shared_ptr <Node>& subMeld(std::shared_ptr <Node> &index1, std::shared_ptr <Node> &index2) {

if (index1 == nullptr) {
return index2;
}

if (index2 == nullptr) {
return index1;
}

if (index1->value > index2->value)
std::swap(index1, index2);
index1->right =  (subMeld(index2, index1->right));

if ((index1->right != nullptr) && (index1->left != nullptr)) {
index1->rang = std::min(index1->right->rang, index1->left->rang) + 1;
if ((index1->right->rang) > (index1->left->rang))
std::swap(index1->right, index1->left);
}
else {
if (index1->right != nullptr)std::swap(index1->right, index1->left);
}
return index1;
}
*/



/*
class LeftistHeap : public IHeap {
private:
	struct Node {
		~Node() {
			delete left;
			delete right;
		}
		int value = 0;
		int rang = 0;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	virtual Node* subMeld(Node* index1, Node* index2) {

		if (index1 == nullptr) {
			return index2;
		}

		if (index2 == nullptr) {
			return index1;
		}

		if (index1->value > index2->value) std::swap(index1, index2);
		index1->right = subMeld(index2, index1->right);

		if ((index1->right != nullptr) && (index1->left != nullptr)) {
			index1->rang = std::min(index1->right->rang, index1->left->rang) + 1;
			if ((index1->right->rang) > (index1->left->rang))
				std::swap(index1->right, index1->left);
		}
		else {
			if (index1->right != nullptr)std::swap(index1->right, index1->left);
		}
		return index1;
	}

public:
	/*void DeleteNode(Node* NewNode) {
		if (NewNode != nullptr) {
			if (NewNode->left != nullptr) {
				DeleteNode(NewNode->left);
				NewNode->left = nullptr;
			}
			if (NewNode->right != nullptr) {
				DeleteNode(NewNode->right);
				NewNode->right = nullptr;
			}
		}
		if (NewNode != nullptr) delete NewNode;
	}

	Node* Root = nullptr;

	LeftistHeap() {}

	//LeftistHeap(LeftistHeap* OldHeap) {}//copy
	//LeftistHeap() {}//move

	~LeftistHeap() {
		//DeleteNode(Root);
		delete Root;
	}

	void Insert(int key) override {
		Node* N = new Node;
		N->value = key;
		Root = subMeld(Root, N);
	}

	
	virtual void Meld(IHeap* other)
	{
		LeftistHeap* tmp = dynamic_cast<LeftistHeap*>(other);
		Root = subMeld(Root, tmp->Root);
		tmp->Root = nullptr;
//		return this;
	}

	int Min() const override {
		if (Root != nullptr) { return Root->value; }
		else return 0;
	}

	void ExtractMin() override {
		Node* DeLeftistHeapNode = Root;
		if (Root != nullptr) {
			Root = subMeld(Root->left, Root->right);
			DeLeftistHeapNode->left = nullptr;
			DeLeftistHeapNode->right = nullptr;
			delete DeLeftistHeapNode;
		}
	}
};*/
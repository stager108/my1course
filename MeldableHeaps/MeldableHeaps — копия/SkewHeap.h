#pragma once
#include "IHeap.h"

class SkewHeap : public IHeap <Node> {
	private:
	struct Node {
		~Node() {
			//	std::cout << "I delete a node " << "!!" << std::endl; 
			delete left;
			delete right;
		}
		int value = 0;
		int rang = 0;
		Node* left = nullptr;
		Node* right = nullptr;
	};
public:
	void DeleteNode(Node* NewNode) {
		if (NewNode != nullptr) {
			//	std::cout << "I delete a node " << NewNode->value << "!!" << std::endl;
			if (NewNode->left != nullptr) {
				DeleteNode(NewNode->left);
			}
			if (NewNode->right != nullptr) {
				DeleteNode(NewNode->right);
			}
		}
		//if (NewNode != nullptrptr) delete NewNode;
	}

	Node* Root = nullptr;

	SkewHeap() {}
	~SkewHeap() {
		//DeleteNode(Root);
	}
	//SkewHeap(SkewHeap* OldHeap) {}//copy

	//	SkewHeap(SkewHeap* &&OldHeap) {
	//		Root = OldHeap->Root;
	//	}//move

	void Insert(int key) {
		Node* N = new Node;
		N->value = key;
		Root = Meld(Root, N);
	}

	Node* Meld(Node* &index1, Node* &index2) {
		if (index1 == nullptr) {
			return index2;
		}
		if (index2 == nullptr) {
			return index1;
		}
		if (index1->value > index2->value)
			std::swap(index1, index2);
		index1->right = Meld(index2, index1->right);
		std::swap(index1->right, index1->left);
		return index1;
	}

	int Min() const {
		if (Root != nullptr) {
			return Root->value;
		}
		else return 0;
	}

	void ExtractMin() {
		Node* DelNode = Root;
		if (Root != nullptr) {
			Root = Meld(Root->left, Root->right);
		}
	}
};
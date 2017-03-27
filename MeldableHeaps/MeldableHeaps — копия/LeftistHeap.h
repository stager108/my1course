#pragma once
#include "IHeap.h"

class LeftistHeap : public IHeap <Node> {
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
			std::cout << "I delete a node " << NewNode->value << "!!" << std::endl;
			std::cout << "Rang " << NewNode->rang << "!!" << std::endl;
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

	LeftistHeap() {}

	//LeftistHeap(LeftistHeap* OldHeap) {}//copy
	//LeftistHeap() {}//move

	~LeftistHeap() {
		//DeleteNode(Root);
		//delete Root;
	}


	void Insert(int key) override {
		Node* N = new Node;
		//	std::cout << "I insert a node !!" << std::endl;
		N->value = key;
		//	std::cout << "I insert a node !!" << std::endl;
		Root = Meld(Root, N);
	}

	Node* Meld(Node* &index1, Node* &index2) override {

		if (index1 == nullptr) {
			//	std::cout << "I insert a node !!" << std::endl;

			return index2;

		}

		if (index2 == nullptr) {
			//	std::cout << "I insert a node !!" << std::endl;

			return index1;
		}

		if (index1->value > index2->value) std::swap(index1, index2);
		index1->right = Meld(index2, index1->right);


		if ((index1->right != nullptr) && (index1->left != nullptr)) {
			index1->rang = std::min(index1->right->rang, index1->left->rang) + 1;
			if ((index1->right->rang) > (index1->left->rang))
				std::swap(index1->right, index1->left);
		}
		else {
			if (index1->right != nullptr)std::swap(index1->right, index1->left);
		}
		//	std::cout << "I insert a node !!" << std::endl;

		return index1;
	}


	int Min() const override {
		return Root->value;
	}

	void ExtractMin() override {
		Node* DelNode = Root;
		if (Root != nullptr) {
			Root = Meld(Root->left, Root->right);
		}

		//if (DelNode != nullptrptr) delete DelNode;
	}


};
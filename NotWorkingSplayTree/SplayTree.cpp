// SplayTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>
class SplayTree {
private:
	struct Node {
		int key = 0;
		Node* left = nullptr;
		Node* right = nullptr;
		Node* parent = nullptr;
		int h = 0;
		int subTreeSize = 0;
		int subTreeSum = 0;
		Node() {
			int key;
		    left = nullptr;
			right = nullptr;
			parent = nullptr;
			h = 0;
			subTreeSize = 0;
			subTreeSum = 0;
		}
		Node(int vkey) {
			int key = vkey;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
			h = 0;
			subTreeSize = 0;
			subTreeSum = vkey;
		}
	};
	Node* TreeRoot;
	void myswap(Node* First, Node* Second) {
		std::swap(First->key, Second->key);
	}
public:
	
	SplayTree() {}
	~SplayTree() {}
	int LeftSubTreeSize(Node* N) {
		if (N == nullptr) { return 0; }
		else {
			if (N->left != nullptr) {
				return N->left->subTreeSize;
			}
			else {
				return 0;
			}
		}
	}
	int LeftSubTreeSum(Node* N) {
		if (N == nullptr) { return 0; }
		else {
			if (N->left != nullptr) {
				return N->left->subTreeSum;
			}
			else {
				return 0;
			}
		}
	}
	int RightSubTreeSize(Node* N) {
		if (N == nullptr) { return 0; }
		else {
			if (N->right != nullptr) {
				return N->right->subTreeSize;
			}
			else {
				return 0;
			}
		}
	}
	int RightSubTreeSum(Node* N) {
		if (N == nullptr) { return 0; }
		else {
			if (N->right != nullptr) {
				return N->right->subTreeSum;
			}
			else {
				return 0;
			}
		}
	}
    void CreateTree(int* data, int n) {
		Node* Root;
		if (n == 0) {
			Root = nullptr;
		}
		else {
			Root = new Node;
			Root->key = data[0];
			Root->h = 0;
			Root->subTreeSize = 1;
			Root->subTreeSum = data[0];
			Node* Element;
			for (int i = 1; i < n; i++) {
				Element = new Node;
				Element->key = i;
				Element->left = Root;
				Element->subTreeSum = data[i];
				Root->parent = Element;
				Root->h = 0;
				Root = Element;				
				Root->subTreeSize = LeftSubTreeSize(Root) + 1;
				Root->subTreeSum = LeftSubTreeSum(Root) + data[i];
			}
			TreeRoot = Root;
			Node* First = Search(Root,0);
			Splay(Root, First);

		}

		TreeRoot = Root;
	}
	Node* Search(Node* Root, int pos) {
		Node* SearchNode = Root;
		if (Root != nullptr) {
			int j = Root->subTreeSize - 1;
			int IsLefter = LeftSubTreeSize(Root);
			while ((IsLefter != pos) && (SearchNode != nullptr)) {
				if (IsLefter < pos) {
					if (SearchNode->right != nullptr) {
						SearchNode = SearchNode->right;
						IsLefter += LeftSubTreeSize(SearchNode) + 1;
					}
				}
				else {
					if (IsLefter > pos) {
						if (SearchNode->left != nullptr) {
							SearchNode = SearchNode->left;
							IsLefter -= RightSubTreeSize(SearchNode) + 1;
							
						}
					}
				}
			}
			Splay(Root,SearchNode);
		}
		return SearchNode;
	}
	void Split(Node* &Root, Node* &Tree1, Node* &Tree2, int key) {
		if (Root != nullptr) {
			int e = Root->subTreeSize;
			Node* Need = Search(Root, key);
			Tree1 = Root->left;
			if (Tree1 != nullptr) { 
				Tree1->parent = nullptr;
			}
			Root->left = nullptr;
			Tree2 = Root;
			Root = nullptr;
			if ((Tree2 != nullptr)) {
				Tree2->subTreeSize = RightSubTreeSize(Tree2) + 1;
				Tree2->subTreeSum = RightSubTreeSum(Tree2) + Tree2->key;
			}
		}
		else {
			Tree1 = nullptr;
			Tree2 = nullptr;
		}
	}
	void Insert(Node* &Root, int pos, int key) {
		Node *Tree1 = nullptr, *Tree2 = nullptr;
		Node* NewNode = new Node;
		NewNode->key = key;
		NewNode->subTreeSize = 1;
		NewNode->subTreeSum = key;
		if ((Root != nullptr) && (pos < Root->subTreeSize) && (pos >= 0)) {
			Split(Root, Tree1, Tree2, pos);
			Root = Merge(Tree1, NewNode);
			Root = Merge(Root, Tree2);
			Splay(Root, NewNode);
		}
		else {
			if((Root != nullptr) && (pos >= Root->subTreeSize)) {
				Root = Merge(Root, NewNode);
			}
			else { Root = NewNode; }
		}
	}
	void Insert(int pos, int key) {
		Insert(TreeRoot, pos, key);
		WriteAll(TreeRoot);
	}

	Node* Merge(Node* First, Node* Second) {
		if (First == nullptr) return Second;
		Node* Top = Search(Second, 0);
		Splay(Second, Top);
		Second->left = First;
		First->parent = Second;
		Second->parent = nullptr;
		First->h = 0;
		Second->subTreeSize += First->subTreeSize;
		Second->subTreeSum += First->subTreeSum;
		return Second;
	}
	void Delete(int pos) {
		Node* DeleteNode = Search(TreeRoot, pos);
		Splay(TreeRoot, DeleteNode);
		TreeRoot = Merge(TreeRoot->left, TreeRoot->right);
		delete DeleteNode;
	}
	void Splay(Node* Root, Node* N) {
		Node* R = Root;
		if ((N == R) || (N == nullptr) || (R == nullptr)) { int e; }
		else {
			while ((N->parent != Root)&&(N != Root)) {
				if (N->h == 0) {
					if (N->parent->h == 0) {
						zigzig(N);
					}
					else {
						zagzig(N);
					}
				}
				else {
					if (N->parent->h == 0) {
						zigzag(N);
					}
					else {
						zagzag(N);
					}
				}
				if ((N->parent != nullptr))N = N->parent;
			}
			if (N->parent == Root) {
				if (N->h == 0) {
					zig(N);
				}
				else {
					zag(N);
				}
			}
		}
	}
	void zig(Node* X) {//левое вращение
		if (X != nullptr) {
			Node* W = X->parent;
			std::swap(X->key, W->key);
			std::swap(W->left, W->right);
			std::swap(W->left, W->right->left);
			std::swap(W->right->left, W->right->right);
			W->right->h = 1;
			if (W->left != nullptr) { 
				W->left->parent = W;
				W->left->h = 0;
			}
			if (W->right->right != nullptr) { 
				W->right->right->parent = W->right;
				W->right->right->h = 1;
			}
			if (W->right->left != nullptr) {
				W->right->left->parent = W->right;
				W->right->left->h = 0;
			}
			W->right->subTreeSize = LeftSubTreeSize(W->right) + RightSubTreeSize(W->right) + 1;
			W->right->subTreeSum = LeftSubTreeSum(W->right) + RightSubTreeSum(W->right) + W->right->key;
			if (W->left != nullptr) {
				W->left->subTreeSize = LeftSubTreeSize(W->left) + RightSubTreeSize(W->left) + 1;
				W->left->subTreeSum = LeftSubTreeSum(W->left) + RightSubTreeSum(W->left) + W->left->key;
			}
			W->subTreeSum = LeftSubTreeSum(W) + RightSubTreeSum(W) + W->key;
			W->subTreeSize = LeftSubTreeSize(W) + RightSubTreeSize(W) + 1;
		}

	}
	void zag(Node* X) {//правое вращение
		if (X != nullptr) {
			Node* W = X->parent;
			std::swap(X->key, W->key);
			std::swap(W->left, W->right);
			std::swap(W->right, W->left->right);
			std::swap(W->left->left, W->left->right);
			W->left->h = 0;
			if (W->right != nullptr) {
				W->right->parent = W;
				W->right->h = 1;
			}
			if (W->left->right != nullptr) {
				W->left->right->parent = W->left;
				W->left->right->h = 1;

			}
			if (W->left->left != nullptr) {
				W->left->left->parent = W->left;
				W->left->left->h = 0;
			}
			W->left->subTreeSize = LeftSubTreeSize(W->left) + RightSubTreeSize(W->left) + 1;
			W->left->subTreeSum = LeftSubTreeSum(W->left) + RightSubTreeSum(W->left) + W->left->key;
			if (W->right != nullptr) {
				W->right->subTreeSize = LeftSubTreeSize(W->right) + RightSubTreeSize(W->right) + 1;
				W->right->subTreeSum = LeftSubTreeSum(W->right) + RightSubTreeSum(W->right) + W->right->key;
			}
			W->subTreeSize = LeftSubTreeSize(W) + RightSubTreeSize(W) + 1;
			W->subTreeSum = LeftSubTreeSum(W) + RightSubTreeSum(W) + W->key;
		}
	}
	void zigzig(Node* X) {
		zig(X->parent);
		zig(X);
	}
	void zigzag(Node* X) {
		zig(X);
		zag(X->parent);
	}
	void zagzig(Node* X) {
		zag(X);
		zig(X->parent);
	}
	void zagzag(Node* X) {
		zag(X->parent);
		zag(X);
	}
	void WriteAll(Node* Root) {
		Node* V;
		int j = Root->subTreeSize;
		for (int i = 0; i < j; i++) {
			V = Search(Root, i);
			std::cout << V->key<<" "<<V->subTreeSize<<" "<<V->subTreeSum<<" \n";
		}
	}
};

int main()
{
	SplayTree MyTree;
	int a[6];
	for (int i = 0; i < 6; i++) {a[i] = i;}
	MyTree.CreateTree(a, 6);
	MyTree.Insert(0, 9);
	MyTree.Insert(6, 10);
	int y;
	std::cin >> y;
    return 0;
}


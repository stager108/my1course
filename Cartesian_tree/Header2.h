#pragma once
#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "algorithm"
#include "IStructure.h"
#include <ctime>

class CartesianTree: public IStructure {
	struct Node {
		int value = 0;
		int key = 0;
		int subTreeSize = 0;
		int subTreeSum = 0;
		int Min = INT_MAX;
		int Max = INT_MIN;
		bool isReversed = false;
		Node* left = nullptr;
		Node* right = nullptr;
		bool sBig = true;
		bool pBig = true;
		~Node(){
			delete left;
			delete right;
		}
	};
public:
	Node* TreeRoot;
public:
	CartesianTree() {}
	~CartesianTree() {
		delete TreeRoot;
	}
	int LeftSubTreeSize(Node* N) {
		if (N == nullptr) { return 0; }
		else {
			push(N);
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
			push(N);
			if (N->left != nullptr) {
				return N->left->subTreeSum;
			}
			else {
				return 0;
			}
		}
	}
	int LeftSubTreeMin(Node* N) {
		if (N == nullptr) { return INT_MAX; }
		else {
			push(N);
			if (N->left != nullptr) {
				push(N);
				return N->left->Min;
			}
			else {
				return INT_MAX;
			}
		}
	}
	int RightSubTreeMin(Node* N) {
		if (N == nullptr) { return INT_MAX; }
		else {
			push(N);
			if (N->right != nullptr) {
				return N->right->Min;
			}
			else {
				return INT_MAX;
			}
		}
	}
	int RightSubTreeMax(Node* N) {
		if (N == nullptr) { return INT_MIN; }
		else {
			push(N);
			if (N->right != nullptr) {
				return N->right->Max;
			}
			else {
				return INT_MIN;
			}
		}
	}
	int SubTreePref(Node* N) {
		if (N == nullptr) { return true; }
		else {
			push(N);
			return N->pBig;
		}
	}
	int SubTreeSuff(Node* N) {
		if (N == nullptr) { return true; }
		else {
			push(N);
			return N->sBig;
		}
	}
	int RightSubTreeSize(Node* N) {
		if (N == nullptr) { return 0; }
		else {
			push(N);
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
			push(N);
			if (N->right != nullptr) {
				return N->right->subTreeSum;
			}
			else {
				return 0;
			}
		}
	}
	void Create(int* Arr, int count) {
		Node* NewNode;
		srand(clock());
		for (int i = 0; i < count; i++) {
			NewNode = new Node;
			NewNode->value = Arr[i];
			NewNode->key = rand();
			NewNode->subTreeSize = 1;
			NewNode->subTreeSum = Arr[i];
			TreeRoot = Merge(TreeRoot, NewNode);
		}
	}
	void push(Node* V) {
		if (V != nullptr) {
			if (V->isReversed) {
				std::swap(V->left, V->right);
				if (V->left != nullptr) {
					V->left->isReversed = !(V->left->isReversed);
				}
				if (V->right != nullptr) {
					V->right->isReversed = !(V->right->isReversed);
				}
				V->isReversed = false;
				std::swap(V->sBig, V->pBig);
			}
		}
	}
	bool GetpBig(Node* N) {
		if (N == nullptr) { return true; }
		else {
			push(N);
			if ((N->left == nullptr) && (N->right == nullptr)) {
				return true;
			}
			else {
				if (N->left == nullptr) {
					return((N->value < N->right->Min) && (N->right->pBig));
				}
				else {
					if (N->right == nullptr) {
						return((N->value > N->left->Max) && (N->left->pBig));
					}
					else {
						return ((N->value < N->right->Min) && (N->left->pBig) && (N->value > N->left->Max) && (N->right->pBig));
					}
				}

			}

		}
	}
	bool GetsBig(Node* N)   {
		if (N == nullptr) {
			return true;
		}
		else {
			push(N);
			if ((N->left == nullptr) && (N->right == nullptr)) { return true; }
			else {
				if (N->left == nullptr) {
					return((N->value > N->right->Max) && (N->right->sBig));
				}
				else {
					if (N->right == nullptr) {
						return((N->value < N->left->Min) && (N->left->sBig));
					}
					else {
						return ((N->value > N->right->Max) && (N->left->sBig) && (N->value < N->left->Min) && (N->right->sBig));
					}
				}

			}

		}
	}
	void NewInformation(Node* N) {
		if (N != nullptr) {
			N->subTreeSize = LeftSubTreeSize(N) + RightSubTreeSize(N) + 1;
			N->subTreeSum = LeftSubTreeSum(N) + RightSubTreeSum(N) + N->value;
			N->pBig = GetpBig(N);
			N->sBig = GetsBig(N);
			if ((N->left == nullptr) && (N->right == nullptr)) {
				N->Min = N->value;
			}
			else {
				if ((N->left != nullptr) && (N->right != nullptr)) {
					N->Min = std::min(std::min(N->left->Min, N->right->Min), N->value);
				}
				else {
					if (N->left != nullptr) { N->Min = std::min(N->left->Min, N->value); }
					else { N->Min = std::min(N->right->Min, N->value); }
				}
			}

			if ((N->left == nullptr) && (N->right == nullptr)) {
				N->Max = N->value;
			}
			else {
				if ((N->left != nullptr) && (N->right != nullptr)) {
					N->Max = std::max(std::max(N->left->Max, N->right->Max), N->value);
				}
				else {
					if (N->left != nullptr) { N->Min = std::max(N->left->Max, N->value); }
					else { N->Max = std::max(N->right->Max, N->value); }
				}
			}
		}
	}
	void Split(Node* Root, Node* &Tree1, Node* &Tree2, int key) {
		  //  Tree1 = Tree2 = nullptr;
			if (Root == nullptr) {
				Tree1 = Tree2 = nullptr;
				return;
			}
			push(Root);
			if (LeftSubTreeSize(Root) + 1 > key) {
				Split(Root->left, Tree1, Root->left, key);

				NewInformation(Tree1);
				NewInformation(Tree2);
				Tree2 = Root;
			}
			else {
				Split(Root->right, Root->right, Tree2, key - LeftSubTreeSize(Root) - 1);

				NewInformation(Tree1);
				NewInformation(Tree2);
				Tree1 = Root;
			}
			NewInformation(Tree1);
			NewInformation(Tree2);
		

	}
	Node* Merge(Node* First, Node* Second) {
		push(First);
		push(Second);
		if (First == nullptr) return Second;
		if (Second == nullptr) return First;
		Node* Nn;

		if (First->key < Second->key) {
			Second->left = Merge(First, Second->left);
			Nn = Second;
		}
		else {
			Nn = First;
			First->right = Merge(First->right, Second);
			Nn = First;
		}
		NewInformation(Nn);
		return Nn;
	}
	void Insert(int pos, int key) {
		Node* NewNode = new Node;
		NewNode->value = key;
		NewNode->key = rand();
		NewNode->subTreeSize = 1;
		NewNode->subTreeSum = key;
		NewNode->Min = key;
		NewNode->Max = key;
		Node* First = nullptr;
		Node* Second = nullptr;
		Split(TreeRoot, First, Second, pos);
		First = Merge(First, NewNode);
		TreeRoot = Merge(First, Second);
//		std::cout << TreeRoot->subTreeSize<<'\n';
	}
	void Delete(int key) {
		Node* NewNode = nullptr;
		Node* First = nullptr;
		Node* Second = nullptr;
		Node* Second1 = nullptr;
		Split(TreeRoot, First, Second, key);
		Split(Second, NewNode, Second1, 1);
		TreeRoot = Merge(First, NewNode);
		TreeRoot = Merge(First, Second1);
		delete NewNode;

	}
	Node* Search(int key) {
		Node* NewNode = nullptr;
		Node* First = nullptr;
		Node* Second = nullptr;
		Node* Second1 = nullptr;
		Split(TreeRoot, First, Second, key);
		Split(Second, NewNode, Second1, 1);
		TreeRoot = Merge(First, NewNode);
		TreeRoot = Merge(First, Second1);
		return NewNode;
	}
	void ChangeKey(int pos, int key) {
		Node* NewNode = nullptr;
		Node* First = nullptr;
		Node* Second = nullptr;
		Node* Second1 = nullptr;
		Split(TreeRoot, First, Second, pos);
		Split(Second, NewNode, Second1, 1);
		NewNode->value = key;
		NewInformation(NewNode);
		First = Merge(First, NewNode);
		TreeRoot = Merge(First, Second1);
//		std::cout << TreeRoot->subTreeSize << '\n';
	}
	int SubSumma(int l, int r) {
		l++;
		Node *First=nullptr, *Middle=nullptr, *Part=nullptr, *Second=nullptr;
		int ans = 0;
		if (l <= r) {
			Split(TreeRoot, Middle, Second, r);
			Split(Middle, First, Part, l - 1);
			ans = Part->subTreeSum;
			Middle = Merge(First, Part);
			TreeRoot = Merge(Middle, Second);
		}
	//	std::cout << TreeRoot->subTreeSize << '\n';
		return ans;

	}
	void NextPermutation(int l, int r) {
		l;
		Node *First = nullptr, *Middle = nullptr, *Part = nullptr, *Second = nullptr;
		if (l < r) {
			Split(TreeRoot, Middle, Second, r);
			Split(Middle, First, Part, l - 1);
			if (Part->sBig) { Part->isReversed = !Part->isReversed; }
			else {
				Node* Top = Part;
				Node* Reserved;
				Node* LPart = nullptr;
				Node* LLPart = nullptr;
				Node* LRPart = nullptr;
				Node* RPart = nullptr;
				Node* RRPart = nullptr;
				Node* RLPart = nullptr;
				Node* RRLPart = nullptr;
				Node* RRRPart = nullptr;
				Node* FirstBigger = nullptr;
				Node* SecondBigger = nullptr;
				int isLefter = 0;
				int needvalue;

				push(Top);
				bool Flag = true;
				int Min = INT_MIN;
				while (Flag) {
					push(Top);
					if (SubTreeSuff(Top->right) && (RightSubTreeMin(Top) > Min)) {
						if ((Top->value > RightSubTreeMax(Top)) && (Top->value > Min)) {
							Min = Top->value;
							if (Top->left != nullptr) { Top = Top->left; }
							else {
								Flag = false;
							}
						}
						else {
						//	Min = INT_MIN;
							isLefter += LeftSubTreeSize(Top);
							Flag = false;
						}
					}
					else {
				//		Min = INT_MIN;
						isLefter += 1 + LeftSubTreeSize(Top);
						if (Top->right != nullptr) { Top = Top->right; }
						else { Flag = false; }
					}

				}
				
				
				Split(Part, LPart, RPart, isLefter + 1);
				Split(LPart, LLPart, LRPart, isLefter);
				//Top = RightPart;
				needvalue = LRPart->value;
				std::cout << needvalue << " il "<<isLefter<<" ";
				LPart = Merge(LLPart, LRPart);
				Part = Merge(LPart, RPart);
				FirstBigger = RPart;
				SecondBigger = FirstBigger;
				isLefter = 0;
				while (FirstBigger != nullptr) {
					push(FirstBigger);
					if (FirstBigger->value > needvalue) {
						SecondBigger = FirstBigger;
						isLefter += 1 + LeftSubTreeSize(FirstBigger);
						FirstBigger = FirstBigger->right;
					}
					else {
						FirstBigger = FirstBigger->left;
					}
				}
				needvalue = SecondBigger->value;
				std::cout << needvalue << " \n";
				isLefter = 0;
				FirstBigger = RPart;
				SecondBigger = FirstBigger;
				while (FirstBigger != nullptr) {
					push(FirstBigger);
					if (FirstBigger->value >= needvalue) {
						SecondBigger = FirstBigger;
						isLefter += 1 + LeftSubTreeSize(FirstBigger);
						FirstBigger = FirstBigger->right;
					}
					else {
						FirstBigger = FirstBigger->left;
					}
				}
				isLefter--;
				Split(RPart, RLPart, RRPart, isLefter);
				Split(RRPart, RRLPart, RRRPart, 1);
				//if (RRRPart != nullptr) { RRRPart->isReversed = true; }
				LPart = Merge(LLPart, RRLPart);
				RRPart = Merge(LRPart, RRRPart);
				RPart = Merge(RLPart, RRPart);
				if (RPart != nullptr) {
					RPart->isReversed = !RPart->isReversed;
				}
				Part = Merge(LPart, RPart);
			}




			Middle = Merge(First, Part);
			TreeRoot = Merge(Middle, Second);
			WriteTree(TreeRoot);
			std::cout << "\n";
		}
	//	std::cout << TreeRoot->subTreeSize << '\n';
	}
	void WriteTree(Node* R) {
		if (R != nullptr) {
			push(R);
			WriteTree(R->left);
			std::cout << R->value << " ";
			WriteTree(R->right);

		}

	}
};
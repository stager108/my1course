#pragma once
#include "cinbitstream.h"
#include "coutbitstream.h"
#include <vector>

class HaffmanDecoder {
public:
	std::fstream OutFile;
	CInBitStream InFile;
	struct Node {
		Node* Left = nullptr;
		Node* Right = nullptr;
		char Symbol;
	};

	HaffmanDecoder() {}
	~HaffmanDecoder() {}

	Node* ReadHaffmanTree() {
		std::vector<Node*> TreeMaker;
		Node* NewNode = nullptr;
		Node* First;
		Node* Second;
		int treesize;
		unsigned char u;
		unsigned char u1;
		treesize = InFile.ReadInt();
		std::cout << treesize << "\n ";
		treesize = treesize * 2 - 1;
		for (int m = 0; m < treesize; m++) {
			u = InFile.ReadChar();
			if (u == (unsigned char)0) {
				NewNode = new Node;
				u = InFile.ReadChar();
			/*	if (u == (unsigned char)'\r') {
				     u1 = InFile.ReadChar();
					 if (u1 != (unsigned char)'\n') { InFile.UnReadChar(u1); }
					 else { u = (unsigned char)'\n'; }
				}*/
				NewNode->Symbol = u;
				TreeMaker.push_back(NewNode);
			}
			else {
				NewNode = new Node;
				First = TreeMaker.back();
				TreeMaker.pop_back();
				Second = TreeMaker.back();
				TreeMaker.pop_back();
				NewNode->Symbol = '0';
				NewNode->Left = Second;
				NewNode->Right = First;
				TreeMaker.push_back(NewNode);
			}
		}
		return TreeMaker.back();
	}

	void DecodeFile() {
		int newbit;
		bool flag = false;
		InFile.OpenDecodingFile();
		Node* Tree = ReadHaffmanTree();
	//	WriteHaffmanTree(Tree);
		Node* TreeList = Tree;
		//InFile.ReadBuffer();
		while (InFile.IsInFile()) {
			newbit = InFile.GetNextBit();
			//std::cout << newbit;
			if (newbit == 0) {
				if (TreeList->Left == nullptr) {
					/*if (TreeList->Symbol == '\r') {
						if (flag)	InFile.WriteNextSymbol((unsigned char)'\r');
						flag = true;
					}
					else {
						if (TreeList->Symbol == '\n') { InFile.WriteNextSymbol((unsigned char)'\n'); flag = false; }
						else {
							if(flag) InFile.WriteNextSymbol((unsigned char)'\r');*/
							InFile.WriteNextSymbol(TreeList->Symbol);
							/*flag = false;
						}
					}*/
					InFile.Incr();
					TreeList = Tree;
				}
				TreeList = TreeList->Left;
			}
			else {
			     if (TreeList->Right == nullptr) {
					/*if (TreeList->Symbol == '\r') {
						if(flag)	InFile.WriteNextSymbol((unsigned char)'\r');
						flag = true;
					}
					else {
						if (TreeList->Symbol == '\n') { InFile.WriteNextSymbol((unsigned char)'\n'); flag = false; }
						else {
							if(flag)InFile.WriteNextSymbol((unsigned char)'\r');*/
							InFile.WriteNextSymbol(TreeList->Symbol);
							flag = false;
						//}
					//}
					InFile.Incr();
					TreeList = Tree;
				}
				TreeList = TreeList->Right;
			}
		}
		InFile.Incr();
		InFile.CloseFile();
	}
};
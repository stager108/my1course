#pragma once
#include "cinbitstream.h"
#include "coutbitstream.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <ios>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class HaffmanCoder {
private:
	struct HaffCode {
		int length = 0;
		unsigned char code[256];
	};

	COutBitStream OutStream;
	//CInBitStream InFile;
	unsigned char a[256];
	unsigned char b[256];
	HaffCode CodeSeq[256];
	int j = 0;
	int FileSize;
	int SymbolsInText = 0;
	FILE* InFile;
	std::string aa;
public:

	HaffmanCoder() {}
	~HaffmanCoder() {}
	void getFrequencies(int* &Counter) {
		unsigned char sym = 0;
		unsigned char next;
		FileSize = 0;
		std::cout << "Enter coding file's name:" << std::endl;
		std::cin >> aa;
		InFile = fopen(aa.c_str(), "rb");
		next = getc(InFile);
		while (!feof(InFile)) {

			sym = next;
			Counter[sym]++;
			FileSize++;
			next = getc(InFile);
		}

		fclose(InFile);
	}
	void createSequensies(Node* NowNode) {
		if (NowNode != nullptr) {
			j++;
			if ((NowNode->Left == nullptr) && (NowNode->Right == nullptr)) {
			//	std::cout << NowNode->Symbol;
				for (int ii = 0; ii < j; ii++) {
					CodeSeq[NowNode->Symbol].code[ii] = a[ii];
					//std::cout << a[ii];
				}
				//std::cout << '\n';
				CodeSeq[NowNode->Symbol].length = j;
			}
			if (NowNode->Left != nullptr) {
				a[j] = 0;
				createSequensies(NowNode->Left);
			}
			if (NowNode->Right != nullptr) {
				a[j] = 1;
				createSequensies(NowNode->Right);
			}
			j--;
		}
	}
	Node* CreateHaffmanTree(Heap &HaffmanTree) {

		int* Counter = new int[260];
		for (int i = 0; i < 260; i++) { Counter[i] = 0; }
		getFrequencies(Counter);
		Node* First = nullptr;
		Node* Second = nullptr;
		Node* NewNode = nullptr;
		for (int s = 0; s < 256; s++) {//пихаем буквы в кучу
			if (Counter[s] > 0) {
				NewNode = new Node;
				NewNode->Frequency = Counter[s];
				NewNode->Symbol = s;
				//std::cout << s;
				HaffmanTree.push(NewNode);
				SymbolsInText++;
			}
		}
		for (int i = SymbolsInText - 1; i > 0; i--) {
			First = HaffmanTree.min();
			HaffmanTree.extractMin();
			Second = HaffmanTree.min();
			HaffmanTree.extractMin();
			NewNode = new Node;
			NewNode->Left = First;
			NewNode->Right = Second;
			NewNode->Symbol = 0;
			NewNode->Frequency = First->Frequency + Second->Frequency;
			HaffmanTree.push(NewNode);
		}
		delete Counter;
		NewNode = HaffmanTree.min();
		HaffmanTree.extractMin();
		return NewNode;
	}
	void WriteHaffmanTree(Node* Nd) {

		if ((Nd->Left != nullptr) && (Nd->Right != nullptr)) {
			WriteHaffmanTree(Nd->Left);
			WriteHaffmanTree(Nd->Right);
			OutStream.WriteByte((unsigned char)1);
		//	std::cout << 1;
		}
		else {
			OutStream.WriteByte((unsigned char)0);
			OutStream.WriteByte((unsigned char)Nd->Symbol);
		//	std::cout << 0;
			std::cout << Nd->Symbol;
		//	std::cout << Nd->Symbol;
		}
	}
	void CodeFile() {
		unsigned char c;
		Heap HaffmanTree;
		Node* root;
		FILE* InFile;
		j = -1;
		root = CreateHaffmanTree(HaffmanTree);

		unsigned char next;
		createSequensies(root);
		InFile = fopen(aa.c_str(), "rb");
		OutStream.OpenBitStream();
		OutStream.WriteInt(FileSize);
		OutStream.WriteInt(SymbolsInText);
		WriteHaffmanTree(root);
		//next = getc(InFile);
		fread(&next, sizeof(char), 1, InFile);
		while(!feof(InFile)) {

			c = next;
		//	std::cout << next;
			for (int e = 0; e < CodeSeq[c].length; e++) {
				OutStream.WriteBit(CodeSeq[c].code[e]);
			//	std::cout << CodeSeq[c].code[e];
			}
			//next = getc(InFile);
			fread(&next, sizeof(char), 1, InFile);
		//	std::cout << '\n';
		}
		delete root;
		OutStream.FlushAllToFile();
		fclose(InFile);

	}

};
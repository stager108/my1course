
#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
class CInBitStream {
	unsigned char Buffer[4];
	int BufferSize = 0;
	int PartOfFile = 0;
	int FileSize = 0;
	int i;
	FILE* InFil;
	std::fstream MyFile;
	int sizeOfFile = 0;
	int readBitCount = 0;
	int CrBit = 0;
	unsigned char CrashedByte[8];
	int ByteCount = 0;
public:

	explicit CInBitStream() {}
	~CInBitStream() {}
	void OpenDecodingFile() {
		PartOfFile = 0;
		char a[20];
		char e;
		std::cout << "Enter decoding file's name:" << std::endl;
		std::cin >> a;
		/*if (fopen_s(&InFil, a, "rb")) {
			assert(false);
		}*/
		InFil = fopen(a, "rb");
		//assert(InFil != NULL);
		//fread(&sizeOfFile, sizeof(int), 1, InFil);
		sizeOfFile = ReadInt();
	//	std::cout << sizeOfFile;
		//sizeOfFile = static_cast<size_t>();
		std::cout << "Enter answer file's name:" << std::endl;
		std::cin >> a;
		MyFile.open(a, std::ios_base::out);
	}
	unsigned char ReadChar() {
		unsigned char N;
		char e;
	//	N = getc(InFil);
		fread(&N, sizeof(char), 1, InFil);
		return N;
	}
	void UnReadChar(unsigned char u) {
		unsigned char N;
		char e;
		N = ungetc((int)u,InFil);
	}
	int ReadInt() {
		int N = 0;
		char n;
		fscanf(InFil, "%d",&N );
		//n = getc(InFil);
		fread(&n, sizeof(char), 1, InFil);
		return N;
	}
	void CloseFile() {
		fclose(InFil);
		MyFile.close();
	}
	bool IsInFile() {
		return (PartOfFile != sizeOfFile);
	}
	void Incr() {
		PartOfFile++;
	}
	void ReadBuffer() {
		unsigned char next;
		i = 0;
		for (int i = 0; i < 4; i++)
			Buffer[i] = (unsigned char)0;
		i = 0;
		while ((i < 4)) {
		//	fread(&next, sizeof(char), 1, InFil);
			Buffer[i] = getc(InFil);
			i++;
		}
	//	fread(Buffer, sizeof(char), 4, InFil);
		ByteCount = 0;

	}
	int GetNextBit() {
		int a;
		unsigned char byte;
		unsigned char byte1;
		//if (ByteCount == 4) {
		//	ReadBuffer();
	//	}
		if (CrBit == 0) {
		//	byte = Buffer[ByteCount];
			//byte = getc(InFil);
			fread(&byte, sizeof(char), 1, InFil);
		/*	if (byte == (unsigned char)'\r') {
				byte1 = ReadChar();
				if (byte1 != (unsigned char)'\n') { UnReadChar(byte1); }
				else { byte = (unsigned char)'\n'; }
			}*/
		//	std::cout << byte <<'\n';
		//	std::cout << ByteCount<<'\n';
			for (int ii = 0; ii < 8; ii++) {
				a = byte % 2;
		//		std::cout << a;
				byte = byte / 2;
				CrashedByte[ii] = a;
			}
			ByteCount++;
			CrBit = 8;
		}

		CrBit--;
		//std::cout <<'\n'<<CrBit<<'\n';
		return CrashedByte[CrBit];
	}

	void WriteNextSymbol(char Symbol) {
	//	MyFile.put(Symbol);// << Symbol;
		MyFile.write((const char*)&Symbol, 1);
	}
};

#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <cassert>
#include <ios>
#include "filestorage.h"

void FileStorageTest(std::string &dir){
	FileStorage <int> E;
	int R;
	E.nameFile(1, dir);//get name
	E.openForWrite();
	E.putElement(1)	;
	E.putElement(2);
	E.putElement(3);
	E.closeFile();
	E.openForRead();

	E.getElement(R);
	std::cout<<R<<" ";
	E.getElement(R);
	std::cout<<R<<" ";
	E.getElement(R);
	std::cout<<R<<" ";
	
	E.closeFile();
	
}
void DataSourceTest() {

		IDataSourceRead <int> W();
		IDataSourceWrite <int> Y();
		W.iDataOpen();
		Y.iDataOpen();
		int R;
		W.get(R);
		std::cout << R << " ";
		Y.put(R);
		W.get(R);
		std::cout << R;
		Y.put(R);
		Y.iDataClose();
		W.iDataClose();
		return 0;
	}

}
int main() {


}

/*#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <cassert>
#include <ios>
#include "filestorage.h"

int main(){
	FileStorage <int> E;
	int R;
	E.nameFile(1);//get name
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
	
}*/

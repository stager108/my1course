/*#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <cassert>
#include <ios>
#include "idatasource.h"


int main(){	

    IDataSourceRead <int> W;
	IDataSourceWrite <int> Y;
    W.iDataOpen();
    Y.iDataOpen();
	int R;
	W.get(R);
	std::cout<<R<<" ";
	Y.put(R);
	W.get(R);
	std::cout<<R;
	Y.put(R);
	Y.iDataClose();
	W.iDataClose();
	return 0;
}*/

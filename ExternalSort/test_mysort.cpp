#include "myreverse1.h"

int main(){
	int k = 1000000;
	//MySort <int> W(k);
	MyReverse <int> W(k);
	std::string s("input.txt"), a("out.txt"), dir("C:\\Users\\Софья\\Documents\\Visual Studio 2015\\Projects\\Work — копия\\Work\\");
	//std::cin >> s >> a;
	W.getAnswer(s, a, dir);
    return 0;
}

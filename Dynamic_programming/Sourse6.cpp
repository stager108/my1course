
#include "limits.h"
#include <iostream>
int main() {
	int n;
	int m;
	int s;
    bool ans = false;
	std::cin >> n;
	int *cash1 = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> cash1[i];
	}
	std::cin >> m;
	int *cash2 = new int[m];
	for (int i = 0; i < m; i++) {
		std::cin >> cash2[i];
	}
    std::cin >> s;
	bool *res1 = new bool[10001];
	for (int i = 0; i <10001; i++) {
		res1[i] = false;
	}

    bool *res2 = new bool[10001];
    for (int i = 0; i < 10001; i++) {
		res2[i] = false;
	}


    res1[0]=true;
    res2[0]=true;
	for (int i = 0; i < n; i++) {

		for (int j = 10000; j > cash1[i];  j--) {
			if(res1[j - cash1[i]])res1[j] = true;
		}
		res1[cash1[i]] = true;
	}

	for (int i = 0; i < m; i++) {

		for (int j = 10000; j > cash2[i];  j--) {
			if(res2[j - cash2[i]])res2[j] = true;
		}
        res2[cash2[i]] = true;
	}

    for(int i = s; i < 10001; i++){
        ans = ans || (res1[i])&&(res2[i-s]);
    }

	if (ans) { std::cout << "yes"; }
	else { std::cout << "no"; }
	delete[] cash2;
	delete[] cash1;
	delete[] res1;
	delete[] res2;
	return 0;

}


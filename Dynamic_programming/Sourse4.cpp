// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	long long int** ans = new long long int*[n + 1];
	for (int i = 0; i < n + 1; i++) ans[i] = new long long int [n + 1];
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++)
			ans[i][j] = 0;
    ans[0][0] = 1;
	for (int j = 0; j <= n; j++) {
		ans[0][j] = 1;
	}
	for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            ans[i][k] += ans[i - k][k] + ans[i][k-1];
        }

		for (int j = i + 1; j < n + 1; j++) {
			ans[i][j] = ans[i][i];
		}

	}
	/*
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++)
			std::cout << ans[i][j] << " ";
		std::cout << "\n";
	}*/
	std::cout << ans[n][n];
	for (int i = 0; i < n + 1; i++) delete [] ans[i];
	delete [] ans;
	//std::cin >> n;
	return 0;
}


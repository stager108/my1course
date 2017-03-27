// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "limits.h"
#include <iostream>
#include <cmath>
#include <algorithm>
int *a;
int *b;
int n;
double **C;
int **D;
double length(int i, int j) {
	if ((abs(i - j) != 1) && (i != j)) {
		return sqrt((a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j])*(b[i] - b[j]));
	}
	else return 0;
}

void MinTriangle(int l, int r) {
	if ((l >= r) || (r - l < 3)) return;
	double dl;
	for (int j = l + 1; j < r; j++) {
		if (C[l][j] == INT_MAX) { MinTriangle(l, j); }
		if (C[j][r] == INT_MAX) { MinTriangle(j, r); }
		dl = C[l][j] + C[j][r] + length(l, j) + length(j, r);
		if (C[l][r] > dl) {
			C[l][r] = dl;
			D[l][r] = j;
		}
	}
}
void WriteMinTriangle(int l, int r) {
	if ((l >= r) || (r - l < 3)) return;
	if (D[l][r] == INT_MAX) return;
	if((abs(l - D[l][r]) > 1)) std::cout << l << " " << D[l][r] << "\n";
	if ((abs(r - D[l][r]) > 1)) std::cout << D[l][r] << " " << r << "\n";
	if ((abs(l - D[l][r]) > 2)) WriteMinTriangle(l, D[l][r]);
	if ((abs(r - D[l][r]) > 2)) WriteMinTriangle(D[l][r], r);

}
int main() {
	double dl;
	std::cin >> n;
	if (n > 3) {
		a = new int[n];
		b = new int[n];

		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			std::cin >> b[i];
		}

		C = new double*[n];
		D = new int*[n];

		for (int i = 0; i < n; i++) {
			C[i] = new double[n];
		}

		for (int i = 0; i < n; i++) {
			D[i] = new int[n];
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				C[i][j] = INT_MAX;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				D[i][j] = INT_MAX;
		for (int i = 0; i < n; i++)
			C[i][i] = 0;

		for (int i = 0; i < n - 1; i++)
			C[i][i + 1] = 0;

		for (int i = 0; i < n - 2; i++)
			C[i][i + 2] = 0;

		MinTriangle(0, n - 1);
	/*	for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				std::cout << C[i][j] << " ";
			std::cout << "\n";
		}
*/
        std::cout << C[0][n-1];
	//	WriteMinTriangle(0, n - 1);

	/*	for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				std::cout << C[i][j] << " ";
			std::cout << "\n";
		}*/
		delete[] a;
		delete[] b;
		for (int i = 0; i < n; i++) {
			delete[] C[i];
		}
		delete[] C;
        for (int i = 0; i < n; i++) {
			delete[] D[i];
		}
		delete[] D;
	}
	return 0;
}

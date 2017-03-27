#include "stdio.h"
#include "limits.h"
#include <iostream>
int main() {
	int n;
	std::cin >> n;
    int data;
    int sum = 0;
    int maximum;
    int minimum;
    int minl = -1;
    int lmax = 0;
    int rmax = 0;
    std::cin >> sum;
    maximum = sum;
	for (int i = 1; i < n; i++) {
        std::cin >> data;
        sum+=data;
		if (sum >= maximum) {
			maximum = sum;
			rmax = i;
			lmax = minl+1;
		}
		if (sum < 0) {
            minl = i;
            sum = 0;
		}
	}

	std::cout << lmax << ' ' << rmax;
	return 0;

}

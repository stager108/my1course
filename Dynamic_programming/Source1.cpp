#include "stdio.h"
#include "limits.h"
#include <iostream>


int main() {
	int n;
	std::cin >> n;
	unsigned long long int *ans = new unsigned long long int[n + 5];
	ans[0] = 1;
	ans[1] = 8;
	ans[2] = ans[1] * 8 + 8;
	ans[3] = ans[2] * 8 + ans[1] * 8 + 8;
	ans[4] = ans[3] * 8 + ans[2] * 8 + ans[1] * 8 + 2;
	for (int i = 4; i <= n; i++) {
		ans[i] = ans[i - 1] * 8 + ans[i - 2] * 8 + ans[i - 3] * 8 + ans[i - 4] * 2;
	}
	std::cout << ans[n];
	delete ans;
	return 0;
}

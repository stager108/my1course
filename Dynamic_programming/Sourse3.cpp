#include <iostream>
#include <stdio.h>
#include <vector>
int main() {
	int n;
	int m;
	int answer = 0;
	std::vector <int> st;
	std::vector <int> counts;
	int sum = 0;
	int last_el = 0;
	int last_stack_el = 0;
	int count_last_el = 0;
	std::cin >> m;
	std::cin >> n;
	int** ans = new int*[m];

	for (int i = 0; i < m; i++)
		ans[i] = new int[n];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			std::cin >> ans[i][j];

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < m; j++) {
			if (ans[j][i] == 0) {
				sum++;
			}
			else {
				sum = 0;
			}
			ans[j][i] = sum;
		}

	}


	for (int i = 0; i < m; i++) {
		sum = 0;
		last_el = 0;
		count_last_el = 0;
		last_stack_el = 0;
		st.clear();
		counts.clear();
		for (int j = 0; j < n; j++) {

			if (ans[i][j] >= last_stack_el) {
				st.push_back(ans[i][j]);
				counts.push_back(1);
				count_last_el = 1;
				sum += ans[i][j];
				last_stack_el = ans[i][j];
			}
			else {
				last_el = ans[i][j];
				if (ans[i][j] != 0) {
					count_last_el = 1;
					while ((st.size()> 0) && (st.back() >= last_el)) {
						count_last_el += counts.back();
						sum -= st.back()*counts.back();
						st.pop_back();
						counts.pop_back();
					}
					st.push_back(ans[i][j]);
					counts.push_back(count_last_el);
					last_stack_el = ans[i][j];
					sum += count_last_el * last_stack_el;
				}
				else {
					count_last_el = 0;
					st.clear();
					counts.clear();
					last_stack_el = 0;
					last_el = 0;
					sum = 0;
				}

			}

			answer += sum ;
		}

	}

	std::cout << answer;
	for (int i = 0; i < m; i++) delete[] ans[i];
	delete[] ans;
	//std::cin >> n;
	return 0;
}


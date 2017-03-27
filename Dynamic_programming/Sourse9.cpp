
#include "stdio.h"
#include "limits.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
enum Color { White, Blue};
struct Node {
	int count_child;
	Color colour;
	std::vector <int> child;
};

Node* Tree;
int *ssize;
int** ans;
void dfs1(int v, int s) {
	ssize[v] = 1;1
	Tree[v].colour = Blue;
	ans[v][1] = Tree[v].count_child + s;
	for (int i = 0; i < Tree[v].count_child; i++) {
		if (Tree[Tree[v].child[i]].colour == White) {
			dfs1(Tree[v].child[i], -1);
			for (int k = ssize[v]; k > 0; k--) {
				for (int j = 1; j<= ssize[Tree[v].child[i]];j++) {

					ans[v][k + j] = std::min(ans[v][k + j], ans[Tree[v].child[i]][j] + ans[v][k] - 1);
				}
			}
		    ssize[v] += ssize[Tree[v].child[i]];
		}
	}

	Tree[v].colour = White;
}
int dfs2(int v, int k, int s) {
	int res = ans[v][k] + s;
	Tree[v].colour = Blue;
	for (int i = 0; i < Tree[v].count_child; i++) {
		if (Tree[Tree[v].child[i]].colour == White) {
			res = std::min(res, dfs2(Tree[v].child[i], k, 1));
		}
	}

	Tree[v].colour = White;
	return res;
}
int main() {
	int n;
	int v1, v2;
	std::cin >> n;
	Tree = new Node[n + 2];
	for (int i = 0; i < n; i++) {
		Tree[i].count_child = 0;
		Tree[i].colour = White;
		Tree[i].child.clear();
	}
	for (int i = 0; i < n - 1; i++) {
		std::cin >> v1 >> v2;
		Tree[v1].child.push_back(v2);
		Tree[v2].child.push_back(v1);
		Tree[v1].count_child++;
		Tree[v2].count_child++;
	}
	ans = new int*[n + 1];
	ssize = new int[n + 1];
	for (int i = 0; i <= n; i++)
		ans[i] = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			ans[i][j] = INT_MAX - 1;
		}

	}
	dfs1(0,0);
	int k;
	std::cin >> k;
	int minimum = n;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
		std::cout << ans[i][j]<<" ";
		}
		std::cout << "\n";
	}
	minimum = dfs2(0, k, 0);
	std::cout << minimum;
	for (int i = 0; i < n; i++) {
		Tree[i].child.clear();
	}
	delete[] Tree;
	for (int i = 0;  i <= n; i++) {
		delete[] ans[i];

	}
	delete[] ans;
	delete[] ssize;
	return 0;

}


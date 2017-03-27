#include "stdio.h"
#include "limits.h"
#include <iostream>
#include <vector>
enum Color { White, Blue, Grey };
struct Node {
    long long int sum;
	long long int sqrsum;
	long long int count_child;
	long long int subtree_size;
	int v_size;
	Color colour;
	int* weight;
	int* child;

    Node(){
        sum = 0;
		sqrsum = 0;
		count_child = 0;
		subtree_size = 1;
		colour = White;
		weight = new int [2];
		child = new int [2];
		v_size = 2;
    }
    ~Node(){

        delete [] weight;
		delete [] child;
    }
};

Node* Tree;
int Tsize;

void dfs(Node* root) {
	root->colour = Blue;
	for (int i = 0; i < root->count_child; i++) {
		if (Tree[root->child[i]].colour == White)dfs(&Tree[root->child[i]]);
	}
	for (int i = 0; i < root->count_child; i++) {
		if (Tree[root->child[i]].colour == Grey) {
			root->subtree_size += Tree[root->child[i]].subtree_size;
			root->sum += Tree[root->child[i]].sum + Tree[root->child[i]].subtree_size * root->weight[i];
			root->sqrsum += Tree[root->child[i]].sqrsum + (2 * Tree[root->child[i]].sum + Tree[root->child[i]].subtree_size * root->weight[i])* root->weight[i];
		}
	}
	root->colour = Grey;
}


void DFS(Node* root, int res, int osum) {
	int bigSum = 0;
	int bigSize = 0;
	int bigsSum = 0;
	root->sqrsum += res;
	root->sum += osum;
	root->colour = Blue;
	for (int i = 0; i < root->count_child; i++) {
		if (Tree[root->child[i]].colour == Grey) {
			bigSize = Tsize - Tree[root->child[i]].subtree_size;
			bigSum = root->sum - Tree[root->child[i]].sum - root->weight[i] * Tree[root->child[i]].subtree_size;
			bigsSum = root->sqrsum - Tree[root->child[i]].subtree_size * root->weight[i] * root->weight[i] - 2 * Tree[root->child[i]].sum * root->weight[i] - Tree[root->child[i]].sqrsum;
			bigsSum = bigsSum + bigSize * root->weight[i] * root->weight[i] + 2 * root->weight[i] * bigSum;
			DFS(&Tree[root->child[i]], bigsSum, bigSum + root->weight[i] * bigSize);
		}
	}
	root->colour = White;
}
int main() {
	int n;
	int v1, v2, w;
	std::cin >> n;
	Tree = new Node[n];

	for (int i = 0; i < n - 1; i++) {
		std::cin >> v1 >> v2 >> w;

		Tree[v1].child[Tree[v1].count_child] = v2;
        if(Tree[v1].v_size == Tree[v1].count_child + 1) {
            int* reserved = new int[Tree[v1].v_size * 2];
            for(int i=0; i < Tree[v1].v_size; i++){
                reserved[i] = Tree[v1].child[i];
            }
            std::swap(Tree[v1].child, reserved);
            Tree[v1].v_size *=2;
            delete [] reserved;
            reserved = new int[Tree[v1].v_size];
            for(int i=0; i < Tree[v1].v_size/2; i++){
                reserved[i] = Tree[v1].weight[i];
            }
            std::swap(Tree[v1].weight, reserved);
            delete [] reserved;
        }

        Tree[v2].child[Tree[v2].count_child] = v1;

        if(Tree[v2].v_size == Tree[v2].count_child + 1) {
            int* reserved = new int[Tree[v2].v_size * 2];
            for(int i = 0; i < Tree[v2].v_size; i++){
                reserved[i] = Tree[v2].child[i];
            }
            std::swap(Tree[v2].child, reserved);
            Tree[v2].v_size *= 2;
            delete [] reserved;
            reserved = new int[Tree[v2].v_size];
            for(int i=0; i < Tree[v2].v_size/2; i++){
                reserved[i] = Tree[v2].weight[i];
            }
            std::swap(Tree[v2].weight, reserved);
            delete [] reserved;
        }
        Tree[v1].weight[Tree[v1].count_child] = w;
        Tree[v2].weight[Tree[v2].count_child] = w;
        Tree[v2].count_child++;
        Tree[v1].count_child++;
	}
	dfs(&Tree[0]);
	Tsize = Tree[0].subtree_size;
	DFS(&Tree[0], 0, 0);
	for (int i = 0; i<n; i++)
		std::cout << Tree[i].sqrsum << " ";

	//  std::cin >> n;

	delete[] Tree;
	return 0;

}

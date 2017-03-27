#include "stdio.h"
#include "limits.h"
#include <iostream>
#include <vector>
enum Color { White, Blue, Grey };
struct Node {
	int first;
	int first_dist;
	int first_subtree;

	int second;
	int second_subtree;
	int second_dist;

	int count_child;
	Color colour;
    int v_size;
	int* weight;
	int* child;
};

Node* Tree;

void dfs(int root) {
	Tree[root].colour = Blue;
	for (int i = 0; i < Tree[root].count_child; i++) {
		if (Tree[Tree[root].child[i]].colour == White)
			dfs(Tree[root].child[i]);
	}
	Tree[root].first = root;
	Tree[root].first_dist = 0;
	Tree[root].first_subtree = root;
	Tree[root].second = root;
	Tree[root].second_dist = 0;
	Tree[root].second_subtree = root;

	for (int i = 0; i < Tree[root].count_child; i++) {
		if (Tree[Tree[root].child[i]].colour == Grey) {
			if ((Tree[Tree[root].child[i]].first_dist + Tree[root].weight[i] > Tree[root].first_dist)) {
                Tree[root].second = Tree[root].first;
                Tree[root].second_dist = Tree[root].first_dist;
                Tree[root].second_subtree = Tree[root].first_subtree;
				Tree[root].first = Tree[Tree[root].child[i]].first;
				Tree[root].first_dist = Tree[Tree[root].child[i]].first_dist + Tree[root].weight[i];
				Tree[root].first_subtree = Tree[root].child[i];
			}
			else{
                if ((Tree[Tree[root].child[i]].first_dist + Tree[root].weight[i] == Tree[root].first_dist)&&(Tree[root].first > Tree[Tree[root].child[i]].first)) {
                    Tree[root].second = Tree[root].first;
                    Tree[root].second_dist = Tree[root].first_dist;
                    Tree[root].second_subtree = Tree[root].first_subtree;
				    Tree[root].first = Tree[Tree[root].child[i]].first;
                    Tree[root].first_dist = Tree[Tree[root].child[i]].first_dist + Tree[root].weight[i];
                    Tree[root].first_subtree = Tree[root].child[i];
			    }
			    else{

                    if ((Tree[Tree[root].child[i]].first_dist + Tree[root].weight[i] > Tree[root].second_dist)) {
                        Tree[root].second = Tree[Tree[root].child[i]].first;
                        Tree[root].second_dist = Tree[Tree[root].child[i]].first_dist + Tree[root].weight[i];
                        Tree[root].second_subtree = Tree[root].child[i];
                    }
                    else{
                        if ((Tree[Tree[root].child[i]].first_dist + Tree[root].weight[i] == Tree[root].second_dist)&&(Tree[root].second > Tree[Tree[root].child[i]].first)) {
                        Tree[root].second = Tree[Tree[root].child[i]].first;
                        Tree[root].second_dist = Tree[Tree[root].child[i]].first_dist + Tree[root].weight[i];
                        Tree[root].second_subtree = Tree[root].child[i];
                        }
                    }

			    }
			}
		}
	}
	Tree[root].colour = Grey;

}


void DFS(int root, int res, int maximum,  int subtree) {
	Tree[root].colour = Blue;
	if ((Tree[root].first_dist < res)) {
        Tree[root].second = Tree[root].first;
        Tree[root].second_dist = Tree[root].first_dist;
        Tree[root].second_subtree = Tree[root].first_subtree;
		Tree[root].first = maximum;
		Tree[root].first_dist = res;
		Tree[root].first_subtree = subtree;
	}
	else{
        if((Tree[root].first_dist == res)&&( Tree[root].first > maximum)){
            Tree[root].second = Tree[root].first;
            Tree[root].second_dist = Tree[root].first_dist;
            Tree[root].second_subtree = Tree[root].first_subtree;
            Tree[root].first = maximum;
		    Tree[root].first_dist = res;
		    Tree[root].first_subtree = subtree;
        }
        else{

     	if ((Tree[root].second_dist < res)) {
            Tree[root].second = maximum;
            Tree[root].second_dist = res;
            Tree[root].second_subtree = subtree;
        }
        else{
            if((Tree[root].second_dist == res)&&( Tree[root].second > maximum)){
                Tree[root].second = maximum;
                Tree[root].second_dist = res;
                Tree[root].second_subtree = subtree;
            }

        }
	}
	}
	for (int i = 0; i < Tree[root].count_child; i++) {
		if (Tree[Tree[root].child[i]].colour == Grey) {
			if (Tree[root].child[i] != Tree[root].first_subtree) {
				DFS(Tree[root].child[i], Tree[root].first_dist + Tree[root].weight[i], Tree[root].first, root);
			}
			else {
				DFS(Tree[root].child[i], Tree[root].second_dist + Tree[root].weight[i], Tree[root].second, root);
			}
		}
	}
	Tree[root].colour = White;
}
int main() {
	int n;
	int v1, v2, w;
	std::cin >> n;
	Tree = new Node[n];
	for(int i=0; i<n; i++){

    Tree[i].first = -1;
	Tree[i].first_dist = 0;
	Tree[i].first_subtree = -1;

	Tree[i].second = -1;
	Tree[i].second_subtree = -1;
	Tree[i].second_dist = 0;

	Tree[i].count_child = 0;
	Tree[i].colour = White;
    Tree[i].v_size = 2;
    Tree[i].weight = new int [2];
	Tree[i].child = new int [2];
	}
	int* reserved;
	for (int i = 0; i < n - 1; i++) {
		std::cin >> v1 >> v2 >> w;

		Tree[v1].child[Tree[v1].count_child] = v2;
        if(Tree[v1].v_size == Tree[v1].count_child + 1) {
            reserved = new int[Tree[v1].v_size * 2];
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
            reserved = new int[Tree[v2].v_size * 2];
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
	dfs(0);
	DFS(0, -1, 0, 0);
	for (int i = 0; i<n; i++)
		std::cout << Tree[i].first << " ";

    for (int i = 0; i<n; i++) {
		delete [] Tree[i].weight;
		delete [] Tree[i].child;
	}
	delete[] Tree;
	return 0;

}

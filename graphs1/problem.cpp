#include <iostream>
#include "gmatrix.h"
#include "glist.h"
#include "garc.h"
#include "gset.h"
#include <vector>
#include <limits>
class StrongConnectivityFounder {

	std::vector <int> parts;
	std::vector <int> tout;
	std::vector <int> order;
	std::vector <bool> visited;
	std::vector <bool> isIn;
	std::vector <bool> isOut;
	std::vector <int> ans1;
	std::vector <int> ans2;
	int time;
	int v;
	int w;
	int g = 0;
	bool sinknotfound;
	void dfs1(int vertex, int &time, CListGraph &Graph) {
		time++;
		visited[vertex] = true;
		std::vector <int> NewVertexes = Graph.GetPrevVertexes(vertex);
		for (size_t i = 1; i <= NewVertexes.size(); i++) {
			if (!visited[NewVertexes[i - 1]]) {
				dfs1(NewVertexes[i - 1], time, Graph);
			}
		}
		order.push_back(vertex);
		tout[vertex] = time;
		time++;
	}

	void dfs2(int vertex, int part, CListGraph &Graph) {
		visited[vertex] = true;
		parts[vertex] = part;
		std::vector <int> NewVertexes = Graph.GetNextVertexes(vertex);
		for (size_t i = 1; i <= NewVertexes.size(); i++) {
			if (!visited[NewVertexes[i - 1]]) {
				dfs2(NewVertexes[i - 1], part, Graph);
			}
		}
	}
	void dfs3(int vertex, CMatrixGraph &Graph) {
		if (!visited[vertex]) {
			if ((!isOut[vertex])&&(w==-1)) {
				w = vertex;
				sinknotfound = false;
			}
			visited[vertex] = true;
			std::vector <int> NewVertexes = Graph.GetNextVertexes(vertex);
			for (size_t i = 1; i <= NewVertexes.size(); i++) {
				if (sinknotfound) {
					dfs3(NewVertexes[i - 1], Graph);
				}
			}
		}
	}
	int GetComponents(CListGraph &Graph, int n) {

		int time = 0;
		int component = 0;
		tout.resize(n, 0);
		order.resize(n, 0);
		parts.resize(n, -1);
		visited.resize(n, false);

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs1(i, time, Graph);
			}
		}
		visited.clear();
		visited.resize(n, false);
		std::reverse(order.begin(), order.end());
		for (int i = 0; i < n; i++) {
			if (!visited[order[i]]) {
				dfs2(order[i], component, Graph);
				component++;
			}
		}
		return component;
	}

public:
	StrongConnectivityFounder() {}

	~StrongConnectivityFounder() {
		order.clear();
		visited.clear();
		tout.clear();
		parts.clear();
	}
	void GetAnswer(CListGraph &Graph, int n) {
		int c = GetComponents(Graph, n);
		if (c != 1) {
			CMatrixGraph NewGraph(c);
			isIn.clear();
			isIn.resize(c, false);
			isOut.clear();
			isOut.resize(c, false);
			std::vector <int> ComVert(c, -1);
			std::vector <int> NewVertexes;
			for (int i = 0; i < n; i++) {
				NewVertexes = Graph.GetPrevVertexes(i);
				for (size_t j = 0; j < NewVertexes.size(); j++) {
					if (parts[NewVertexes[j]] != parts[i]) {
						isIn[parts[i]] = true;
						NewGraph.AddEdge(parts[NewVertexes[j]], parts[i]);
					}
				}
				NewVertexes.clear();
				NewVertexes = Graph.GetNextVertexes(i);
				for (size_t j = 0; j < NewVertexes.size(); j++) {
					if (parts[NewVertexes[j]] != parts[i]) {
						isOut[parts[i]] = true;
						NewGraph.AddEdge(parts[NewVertexes[j]], parts[i]);
					}
				}

				NewVertexes.clear();
				ComVert[parts[i]] = i;
			}
			std::vector <int> FirstPart;
			FirstPart.clear();
			for (int i = 0; i < c; i++) {
				if (!isIn[i]) {
					FirstPart.push_back(i);
				}
			}
			std::vector <int> SecondPart;
			SecondPart.clear();
			for (int i = 0; i < c; i++) {
				if (!isOut[i]) {
					SecondPart.push_back(i);
				}
			}
			int e = std::max(FirstPart.size(), SecondPart.size());
			std::cout << e << "\n";

			ans1.clear();
			ans2.clear();
			visited.clear();
			visited.resize(c, false);
			for (size_t j = 1; j <= FirstPart.size(); j++) {
				v = FirstPart[j - 1];
				w = -1;
				sinknotfound = true;
				dfs3(v, NewGraph);
				if (w != -1) {
					ans1.push_back(v);
					ans2.push_back(w);
				}
			}
			for (size_t j = 0; j < ans1.size() - 1; j++) {
				std::cout << ComVert[ans2[j]] << " " << ComVert[ans1[j + 1]] << "\n";
				isOut[ans2[j]] = true;
				isIn[ans1[j + 1]] = true;
			}
			std::cout << ComVert[ans2.back()] << " " << ComVert[ans1[0]] << "\n";
			isOut[ans2.back()] = true;
			isIn[ans1[0]] = true;
			visited.clear();
			visited.resize(c, false);
			FirstPart.clear();
			for (int i = 0; i < c; i++) {
				if (!isIn[i]) {
					FirstPart.push_back(i);
				}
			}
			SecondPart.clear();
			for (int i = 0; i < c; i++) {
				if (!isOut[i]) {
					SecondPart.push_back(i);
				}
			}

			for (size_t j = 1; j <= std::min(FirstPart.size(), SecondPart.size()); j++) {
				std::cout << ComVert[SecondPart[j - 1]] << " " << ComVert[FirstPart[j - 1]] << "\n";
			}
			if (FirstPart.size() > SecondPart.size()) {
				for (size_t j = SecondPart.size(); j < FirstPart.size(); j++) {
					std::cout << ComVert[ans2.back()] << " " << ComVert[FirstPart[j]] << "\n";
				}
			}
			else {
				for (size_t j = FirstPart.size(); j < SecondPart.size(); j++) {
					std::cout << ComVert[SecondPart[j]] << " " << ComVert[ans1.back()] << "\n";
				}
			}
			/*for (int i = 0; i < c; i++) {
				if (!isIn[i]) {
					std::cout << ComVert[ans2.back()] << " " << ComVert[i]<<"\n";
				}
			}
			for (int i = 0; i < c; i++) {
				if (!isOut[i]) {
					std::cout << ComVert[i]<<" "<<ComVert[ans1.back()]<<"\n";
				}
			}*/
		}
	}
};
int main()
{

	int n;
	int m;
	std::cin >> n;
	CListGraph Graph(n);
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		int from;
		int to;
		std::cin >> from >> to;
		Graph.AddEdge(from, to);
	}

	StrongConnectivityFounder Founder;
	Founder.GetAnswer(Graph, n);


	return 0;
}

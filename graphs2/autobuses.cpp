#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
struct Pair {
	int a;
	int b;
};
struct Triade {
	int to;
	int time1;
	int time2;
};
class CListGraph
{
	struct SVertex {
		std::vector <Triade> inf;
		SVertex()
		{
			inf.clear();
		}
		~SVertex()
		{
			inf.clear();
		}
	};
	int CountVertexes;
public:
	std::vector < SVertex > GrList;

	CListGraph(int n)
	{
		CountVertexes = n;
		GrList.clear();
		GrList.resize(n);
	}

	void AddEdge(int from, int to, int time1, int time2)
	{
		Triade next;
		next.to = to;
		next.time1 = time1;
		next.time2 = time2;
		GrList[from].inf.push_back(next);
	}

	int VertexCount() const
	{
		return CountVertexes;
	}

	int GetNextReis(int vertex, int i, Triade &next)
	{
		if (i >= GrList[vertex].inf.size()) {
			return -1;
		}
		else {
			next.time1 = GrList[vertex].inf[i].time1;
			next.time2 = GrList[vertex].inf[i].time2;
			next.to = GrList[vertex].inf[i].to;
			return 1;
		}
	}
	~CListGraph()
	{
		GrList.clear();
	}
};


int main()
{
	int i;
	std::vector <int> times;
	std::vector <int> ways;
	std::set <std::pair<int, int>> MyQueue;
	int n, m, v1, v2, f, t;
	int begv, endv;
	Pair next, nw;
	Triade nowv;
	std::cin >> n;

	std::cin >> m;
	CListGraph MyGraph(n);
	times.clear();
	times.resize(n, INT_MAX);
	ways.clear();
	ways.resize(n, INT_MAX);
	for (i = 0; i < m; i++) {
		std::cin >> v1 >> v2 >> f >> t;
		MyGraph.AddEdge(v1, v2, f, t);
	}
	std::cin >> begv >> endv;

	times[begv] = 0;
	next.a = 0;
	next.b = begv;
	MyQueue.insert(std::make_pair(times[begv], begv));
	while (!MyQueue.empty()) {
		int v = MyQueue.begin()->second;
		int cur = MyQueue.begin()->first;
		if (v == endv) {
			std::cerr << cur << std::endl;
			break;
			// return giveTime(cur);
		}
		MyQueue.erase(MyQueue.begin());
		i = 0;
		while (MyGraph.GetNextReis(v, i, nowv) != -1) {
			int to = nowv.to;
			int endw = nowv.time2;
			if ((nowv.time1 >= cur) && (endw < times[to]) ){
				MyQueue.erase(std::make_pair(times[to], to));
				times[to] = endw;
				ways[to] = v;
				MyQueue.insert(std::make_pair(times[to], to));

			}
			i++;
		}

	}
	//  return ":(";
	std::deque <int> way;
	std::cout << "\n";
	way.clear();
	i = ways[endv];
	if (i != INT_MAX) {
		if(i!= begv)way.push_front(i);
		while (ways[i] != begv) {
			way.push_front(ways[i]);
			i = ways[i];
		}
		for (i = 0; i < way.size(); i++) {
			std::cout << way[i] << " ";
		}
	}
	std::cout << "\n";
	MyQueue.clear();
	times.clear();



	return 0;
}


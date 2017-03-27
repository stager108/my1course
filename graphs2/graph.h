#pragma once
#include <cstdlib>
#include <vector>
class IGraph {
public:
	virtual ~IGraph() {}
	virtual void AddEdge(int from, int to) = 0;
	virtual int VertexCount() const  = 0;
    virtual std::vector<int> GetNextVertexes(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertexes(int vertex) const = 0;
};

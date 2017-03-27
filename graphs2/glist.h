#pragma once
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include "graph.h"

class CListGraph : public IGraph {

    struct SVertex {
        std::vector < int > prev;
        std::vector < int > next;
        SVertex() {
            prev.clear();
            next.clear();
        }
        ~SVertex() {
            prev.clear();
            next.clear();
        }
    };

    int CountVertexes;
    std::vector < SVertex > GrList;

public:

    CListGraph() {
        CountVertexes = 0;
        GrList.clear();
    }

    CListGraph( int n) {
        CountVertexes = n;
        GrList.clear();
        GrList.resize(n);
    }

    CListGraph( IGraph &Another ) {
        std::vector < int > Vertexes;
        int n = Another.VertexCount();
        for(int i = 0; i < n; i++){
            Vertexes = Another.GetNextVertexes(i);
            for(size_t j = 0; j < Vertexes.size(); j++) {
                AddEdge(i, Vertexes[j]);
            }
            Vertexes = Another.GetPrevVertexes(i);
            for(size_t j = 0; j < Vertexes.size(); j++) {
                AddEdge(Vertexes[j], i);
            }
        }

    }
	void AddEdge(int from, int to) {
	    GrList[from].next.push_back(to);
	    GrList[to].prev.push_back(from);
	}

	int VertexCount() const {
	    return CountVertexes;
	}

    std::vector < int > GetNextVertexes(int vertex) const {
         std::vector <int> Vertexes;
         Vertexes.clear();
         for( size_t i = 0; i < GrList[vertex].next.size(); i++) {
             Vertexes.push_back(GrList[vertex].next[i]);
         }
         return Vertexes;
    }

    std::vector < int > GetPrevVertexes(int vertex) const {
         std::vector <int> Vertexes;
         Vertexes.clear();
         for( size_t i = 0; i < GrList[vertex].prev.size(); i++) {
             Vertexes.push_back(GrList[vertex].prev[i]);
         }
         return Vertexes;
    }

    ~CListGraph() {
         GrList.clear();
    }
};


#pragma once
#include <cstdlib>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include "graph.h"

class CSetGraph : public IGraph {

    struct SVertex {

        std:: unordered_set < int > prev;
        std:: unordered_set < int > next;

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
    int SetSize;
    std::vector < SVertex > GrSet;

public:
    CSetGraph() {
        CountVertexes = 0;
        GrSet.clear();
    }

    CSetGraph( int n) {
        CountVertexes = n;
        GrSet.clear();
        GrSet.resize(n);
    }

    CSetGraph( IGraph &Another ) {
        std::vector < int > Vertexes;
        int n = Another.VertexCount();
        for(int i = 0; i < n; i++) {
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
	    GrSet[from].next.insert(to);
	    GrSet[to].prev.insert(from);
	}

	int VertexCount() const {
	    return CountVertexes;
	}

    std::vector < int > GetNextVertexes(int vertex) const {
         std::vector < int > Vertexes;
         Vertexes.clear();
         for(auto i = GrSet[vertex].next.begin(); i != GrSet[vertex].next.end(); i++ ) {
             Vertexes.push_back( *i );
         }
         return Vertexes;
    }

    std::vector < int > GetPrevVertexes(int vertex) const {
         std::vector < int > Vertexes;
         Vertexes.clear();
         for(auto i = GrSet[vertex].prev.begin(); i != GrSet[vertex].prev.end(); i++ ) {
             Vertexes.push_back( *i );
         }
         return Vertexes;
    }

    ~CSetGraph() {
         GrSet.clear();
    }
};


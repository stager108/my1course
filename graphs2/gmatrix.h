#pragma once
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include "graph.h"
class CMatrixGraph : public IGraph {

    int CountVertexes;
    std::vector < std::vector < int > > Matrix;

public:

    CMatrixGraph() {
        CountVertexes = 0;
        Matrix.clear();
    }

    CMatrixGraph( int n ) {
        CountVertexes = n;
        Matrix.clear();
        Matrix.resize(n);
        for(int i = 0; i < CountVertexes; i++) {
             Matrix[i].resize( n , 0 );
         }
    }

    CMatrixGraph( IGraph &Another ) {
        std::vector < int > Vertexes;
        int n = Another.VertexCount();
        for(int i = 0; i < n; i++){
            Vertexes = Another.GetNextVertexes(i);
            for( size_t j = 0; j < Vertexes.size(); j++ ) {
                AddEdge(i, Vertexes[j]);
            }
            Vertexes = Another.GetPrevVertexes(i);
            for( size_t j = 0; j < Vertexes.size(); j++ ) {
                AddEdge(Vertexes[j], i);
            }
        }

    }

	void AddEdge(int from, int to, int w) {
	    Matrix[from][to] = w;
	}

	int VertexCount() const {
	    return CountVertexes;
	}

    std::vector < int > GetNextVertexes(int vertex) const {
         std::vector <int> Vertexes;
         Vertexes.clear();
         for(int i = 0; i < CountVertexes; i++) {
            if(Matrix[vertex][i] == 1) {
                Vertexes.push_back(i);
            }
         }
         return Vertexes;
    }

    std::vector < int > GetPrevVertexes(int vertex) const {
        std::vector <int> Vertexes;
         Vertexes.clear();
         for( int i = 0; i < CountVertexes; i++) {
            if(Matrix[i][vertex] == 1) {
                Vertexes.push_back(i);
            }
         }
         return Vertexes;

    }

    ~CMatrixGraph() {
        /* for( int i = 0; i < CountVertexes; i++ ) {
            Matrix[i].clear();
         }*/
         Matrix.clear();
    }
};

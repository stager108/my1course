
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include "graph.h"
class CArcGraph : public IGraph {
    struct GEdge {
        int from;
        int to;
    };
    int CountVertexes;
    int ArcSize;
    std::vector < GEdge > GArc;

public:
    CArcGraph() {
        CountVertexes = 0;
        GArc.clear();
    }
    CArcGraph( int n) {
        CountVertexes = n;
        GArc.clear();
    }
    CArcGraph( IGraph &Another ) {
        std::vector < int > Vertexes;
        int n = Another.VertexCount();
        for(int i = 0; i < n; i++){
            Vertexes = Another.GetNextVertexes(i);
            for( size_t j = 0; j < Vertexes.size(); j++ ) {
                AddEdge(i, Vertexes[j]);
            }
            Vertexes = Another.GetPrevVertexes(i);
            for( size_t j = 0; j < Vertexes.size(); j++) {
                AddEdge(Vertexes[j], i);
            }
        }

    }
	void AddEdge(int from, int to) {
        GEdge NewEdge;
        NewEdge.from = from;
        NewEdge.to = to;
        GArc.push_back(NewEdge);
	}

	int VertexCount() const {
	    return CountVertexes;
	}

    std::vector < int > GetNextVertexes(int vertex) const {
         std::vector <int> Vertexes;
         Vertexes.clear();
         for (int i = 0; i < CountVertexes; i++){
             if(GArc[i].from == vertex) {
                 Vertexes.push_back(GArc[vertex].to);
             }
         }
         return Vertexes;
    }

    std::vector < int > GetPrevVertexes(int vertex) const {
         std::vector <int> Vertexes;
         Vertexes.clear();
         for (int i = 0; i < CountVertexes; i++){
             if(GArc[i].to == vertex) {
                 Vertexes.push_back(GArc[vertex].from);
             }
         }
         return Vertexes;
    }
    ~CArcGraph() {
         GArc.clear();
    }
};

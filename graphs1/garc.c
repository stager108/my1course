
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <graph.h>
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
        ListSize = 0;
        GArc.clear();
    }
	void AddEdge(int from, int to){
        if(s > CountVertexes) {
            CountVertexes = s + 1;
	    }
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
         Vertexes.clear;
         for (int i = 0; i < CountVertexes; i++){
             if(GArc[i].from = vertex){
                 Vertexes.push_back(GArc[vertex].to);
             }
         }
         return &Vertexes;
    }

    std::vector < int > GetPrevVertexes(int vertex) const {
         std::vector <int> Vertexes;
         Vertexes.clear;
         for (int i = 0; i < CountVertexes; i++){
             if(GArc[i].to = vertex){
                 Vertexes.push_back(GArc[vertex].from);
             }
         }
         return &Vertexes;
    }
    ~CArcGraph() {
         GArc.clear();
    }
}

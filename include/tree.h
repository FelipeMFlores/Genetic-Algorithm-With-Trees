#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include "graph.h"
#include <vector>


struct EDGE{
    int v1;
    int v2;
    int w;
};

class Tree: public Graph
{
private:
    std::map<int,std::list < std::pair <int, int> > > T;
    std::list <int> verticesIn;
    std::vector<int> link;
    std::vector<bool> Rvector;
  

public:
    
    Tree(int id, std::list<int> R,std::map<int, std::list < std::pair <int, int> > > G,int r, int nvertices);
    ~Tree();
    int id;
    void PrintTree();
    void ConstructTree(std::vector<float> keys);
    void PutEdge( EDGE edge );
    bool InT(int v);
   
    int GetNumberOfEdgesT();
    int find(int x);
    bool same(int a, int b) {
        return find(a) == find(b);}
    void unite(int a, int b);
    bool Prune(int v);
    int GetWeight();
};
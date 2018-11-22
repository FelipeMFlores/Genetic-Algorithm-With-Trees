#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include "graph.h"
#include <vector>

struct EDGE{
    int v1;
    int v2;
    float w;
};

class Tree: public Graph
{
private:
    std::map<int,std::list < std::pair <int, int> > > T;
    std::list <int> verticesIn;
    std::list <bool> RIns;

public:
    
    Tree(int id, std::list<int> R,std::map<int, std::list < std::pair <int, int> > > G,int r);
    ~Tree();
    int id;
    void ConstructTree(std::vector<float> keys);
    bool PutEdgeUntilR( EDGE edge );
    bool InT(int v);
    bool AllRIn();
};
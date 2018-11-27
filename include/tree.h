#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include "graph.h"
#include <vector>
#include <random>



struct EDGE{
    int v1;
    int v2;
    int w;
};

class Tree: public Graph
{
private:
    std::map<int,std::list < std::pair <int, int> > > T;
    std::map<int,std::list < std::pair <int, int> > > TCopy;
    std::list <int> verticesIn;
    std::vector<bool> keys;
    void PruneRec(int v);
    int Translate(int v);
    std::vector<bool> Rvector;
     bool PutEdge(  int v1, int v2 , int w );
    std::list< std::pair < int,int> > ShuffleList(std::list< std::pair < int,int> > lst);
  

public:
    
    Tree(int id, std::list<int> R,std::map<int, std::list < std::pair <int, int> > > G,int r, int nvertices,std::map<int,int > SizeReference);
    ~Tree();
    int id;
    void PrintTree();
    void ConstructTree(std::vector<bool> keys);
   
    
    bool InT(int v);
    int GetNumbersOfRsIn();
    int GetNumberOfEdgesT();
    void Prune();
    int GetWeight();
};
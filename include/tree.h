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
    int fitness;
    void PruneRec(int v);
    int Translate(int v);
    std::vector<bool> Rvector;
    bool PutEdge(  int v1, int v2 , int w );
    std::list< std::pair < int,int> > ShuffleList(std::list< std::pair < int,int> > lst);
  

public:
    
    Tree(int id, Graph graph);
    Tree();
    ~Tree();
    int id;
    void PrintTree();
    void ConstructTree(std::vector<bool> keys);
    void ConstructDeep(std::vector<bool> keys);
    void DeepRec(int v);
    
    
    bool InT(int v);
    int GetNumbersOfRsIn();
    int GetNumberOfEdgesT();
    void Prune();
    int GetWeight();
    std::vector<bool> GetKeys(){return keys;}
    void CalculateFitness();
    int GetFitness(){return fitness;}
};
#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include "graph.h"
#include <vector>
#include <random>



class Tree: public Graph
{
private:
    //tree;map with key a vertice and a list of v2(destination) and weight of every edge that leaves the vertice.
    std::map<int,std::list < std::pair <int, int> > > T; 
    std::list <int> verticesIn; //the vertices which are on the tree.
    std::vector<bool> keys;  
    int fitness; //weight + Rs not in * 1000
    int Translate(int v);  //returns the position of the vertice in the key
    std::vector<bool> Rvector;//says wich vertices are in R
    bool PutEdge(  int v1, int v2 , int w );
    std::list< std::pair < int,int> > ShuffleList(std::list< std::pair < int,int> > lst); 
  

public:
    
    Tree(int id, Graph graph);
    Tree();
    ~Tree();
    int id;
    void PrintTree();
    void ConstructTree(std::vector<bool> keys);
    
    
    bool InT(int v);
    int GetNumbersOfRsIn();
    int GetNumberOfEdgesT();
    int GetWeight();
    std::vector<bool> GetKeys(){return keys;}
    void CalculateFitness();
    int GetFitness(){return fitness;}
};
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

    //weight + Rs not in * 1000 
    int fitness; 

    //returns the first position of the edges that leaves the vertice in the key
    int Translate(int v);  

    //says wich vertices are in R
    std::vector<bool> Rvector;

    //Tries to put  a edge in the, if creates a cycle, dont put and return false.
    bool PutEdge(  int v1, int v2 , int w );

    std::list< std::pair < int,int> > ShuffleList(std::list< std::pair < int,int> > lst); 
  

public:
    
    Tree(int id, Graph graph);
    Tree();
    ~Tree();
    int id;
    void PrintTree();

    /******
    Construct the tree based on the keys, 
    start in the root and construct the tree like a Breadth-first search.
    the keys contain a bool, representing if a edge will be tried to put in the tree.
    A edge dont go in the tree if:
    - the key is false
    - points to root
    - points to a vertice already in the tree
    Edges that tried to enter the tree and fail, it key turns false.
    ******/
    void ConstructTree(std::vector<bool> keys);
    
    //searches if a vertice is in the tree.
    bool InT(int v);
    int GetNumbersOfRsIn();
    int GetNumberOfEdgesT();
    int GetWeight();
    std::vector<bool> GetKeys(){return keys;}
    void CalculateFitness();
    int GetFitness(){return fitness;}

};
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include "graph.h"
#include <vector>

class Tree: public Graph
{
private:
    std::map<int,std::list < std::pair <int, int> > > T;
    std::list <int> verticesIn;
    

public:
    Tree(int id, std::list<int> R,std::map<int, std::list < std::pair <int, int> > > G);
    ~Tree();
    int id;
    void ConstructTree(std::vector<float> keys);
    void PutEdge(std::pair <int, int> edge);

};
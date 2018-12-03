#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>


class Graph
{
protected:
    int r;  //root
    std::list<int> R;  //vertices that must be in the tree
     //graph;map with key a vertice and a list of v2(destination) and weight of every edge that leaves the vertice.
    std::map<int,std::list < std::pair <int, int> > > G;  //graph
    std::map<int,int > SizeReference; //used for calculating th positing in the key of a edge
    int nvertices; //number of the highest vertice
    std::string saveFile;
    void createReference();

public:
    Graph();
    Graph(int id);
    ~Graph();

    int id;

    void setSaveFile(std::string newFile){saveFile = newFile;}

    std::string getSaveFile(){return saveFile;}

    void InputGraph();

    void PrintGraph ();

    int GetNumberOfEdges();

    std::list<int> GetR(){return R;}

    std::map<int,std::list < std::pair <int, int> > >  GetG(){return G;}

    int Getr(){return r;}
    
    int GetNVertices(){return nvertices;}

    std::map<int,int > GetSizeReference(){return SizeReference;}

};
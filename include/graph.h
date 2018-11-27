#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>


class Graph
{
protected:
    int r;
    std::list<int> R;
    std::map<int,std::list < std::pair <int, int> > > G;
    std::map<int,int > SizeReference;
    int nvertices;
    void createReference();
public:
    Graph();
    Graph(int id);
    ~Graph();
    int id;
    void InputGraph(std::string inputFile);
    void PrintGraph ();
    void PrintReference();
    int GetNumberOfEdges();
    std::list<int> GetR(){return R;}
    std::map<int,std::list < std::pair <int, int> > >  GetG(){return G;}
    int Getr(){return r;}
    int GetNVertices(){return nvertices;}
    std::map<int,int > GetSizeReference(){return SizeReference;}

};
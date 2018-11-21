#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>


class Graph
{
protected:
    std::list<int> R;
    std::map<int,std::list < std::pair <int, int> > > G;
    

public:
    Graph(int id);
    ~Graph();
    int id;
    void InputGraph();
    void PrintGraph ();
    std::list<int> GetR(){return R;}
    std::map<int,std::list < std::pair <int, int> > >  GetG(){return G;}
};
#include "tree.h"



Tree::Tree(int id, std::list<int> R, std::map<int,std::list < std::pair <int, int> > > G, int r){

    this->id = id;
    this->R = R;
    this->G = G;
    this->r = r;
}

Tree::~Tree()
{
}

void Tree::ConstructTree(std::vector<float> keys)
{
    int i = 0;
    std::list< std::pair < float, EDGE > > edgekey;
    EDGE edge;
    for( auto const& x : G )
    {       
        for( auto const& j : x.second )
            {
                
                edge.v1 = x.first;
                edge.v2 = j.first;
                edge.w = j.second;

                edgekey.push_back(std::make_pair(keys[i],edge));
                i++;
            }
    }
    edgekey.sort();
    for( auto const& x: edgekey)
    {
        if(PutEdgeUntilR(x.second))
            break;
    }


}

//returns true if all R vertice are in the tree
bool Tree::PutEdgeUntilR( EDGE edge )
{
    if(edge.v2 = r) return false; //points to root.

    if(InT(edge.v2)) return false; //points to a vertice in the tree. CICLE

    std::map<int,std::list < std::pair <int, int> > >::iterator it;
    it = T.find(edge.v1);
    if (it != T.end())
        T[edge.v1].push_back(std::make_pair(edge.v2,edge.w));
    else 
    {
        std::list < std::pair <int, int> > novo;
        novo.push_back(std::make_pair(edge.v2,edge.w));
        T[edge.v1] = novo; 
    }

    verticesIn.push_back(edge.v2);
    verticesIn.sort();
    //if()

}

bool Tree::AllRIn(){


}

bool Tree::InT(int v){
    for(auto const& x : verticesIn){
        if(v > x)
            return false;
        else if(v == x)
                return true;
    }

    return false;

}

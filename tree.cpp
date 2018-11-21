#include "tree.h"

Tree::Tree(int id, std::list<int> R, std::map<int,std::list < std::pair <int, int> > > G){

    this->id = id;
    this->R = R;
    this->G = G;
}

Tree::~Tree()
{
}

void Tree::ConstructTree(std::vector<float> keys)
{
    int i = 0;
    std::list< std::pair < float, std::pair < int, int> > > edgekey;
    
    for( auto const& x : G )
    {       
        for( auto const& j : x.second )
            {
                edgekey.push_back(std::make_pair(keys[i],j));
                i++;
            }
    }
    edgekey.sort();
    for( auto const& x: edgekey)
    {
        std::cout << x.first << " : " <<  x.second.first << " -> " << x.second.second << std::endl;
    }


}


void Tree::PutEdge(std::pair <int, int> edge)
{

}

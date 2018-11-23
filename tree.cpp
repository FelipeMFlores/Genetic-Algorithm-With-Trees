#include "tree.h"



Tree::Tree(int id, std::list<int> R, std::map<int,std::list < std::pair <int, int> > > G, int r, int nvertices){

    this->id = id;
    this->R = R;
    this->G = G;
    this->r = r;
    this->nvertices = nvertices;
}

Tree::~Tree()
{
    
}

void Tree::PrintTree(){
    
    std::list < std::pair <int, int> > val;
    for( auto const& x : T )
    {
        std::cout << x.first  << " : ";       
        for( auto const& i : x.second )
            std::cout  << i.first << " , " << i.second  << "; " ;    
        std::cout << std::endl ;
    }

}

bool sortbykey(std::pair<float,EDGE> a, std::pair<float,EDGE> b){ 
    return (a.first < b.first); 
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
    
    edgekey.sort(sortbykey);
    
    link.resize(nvertices);
   
    for (int i = 1; i <= nvertices; i++) link[i] = i;
    


    for( auto const& x: edgekey)
    {
        PutEdge(x.second);

    }


}




void Tree::PutEdge( EDGE edge )
{
    if(edge.v2 == r) return; //points to root.

    if(InT(edge.v2)) return; //points to a vertice in the tree. CICLE

    
    if (same(edge.v1,edge.v2)) return;
    
    unite(edge.v1,edge.v2);

 

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


}

bool Tree::InT(int v){
    for(auto const& x : verticesIn){
        if(v < x)
            return false;
        else if(v == x)
                return true;
    }

    return false;

}




int Tree::GetNumberOfEdgesT(){

        int i = 0;
    for( auto const& x : T )
    {
        i+= x.second.size();
    }

    return i;

}

int Tree::find(int x){
    while (x != link[x]) x = link[x];
    return x;

}

void Tree::unite(int a, int b){
    a = find(a);
    b = find(b);

    link[b] = a;

}
#include "../include/tree.h"


Tree::Tree(){};

Tree::Tree(int id, Graph graph){

    this->id = id;
    this->G = graph.GetG();
    this->r = graph.Getr();
    this->R = graph.GetR();
    this->nvertices = graph.GetNVertices();
    this->SizeReference = graph.GetSizeReference();
    Rvector.resize(nvertices+1, false);
    for(int x: R){
        Rvector[x] = true;
    }
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



void Tree::ConstructTree(std::vector<bool> keys)
{
    this->keys = keys;

    //insert the vertices like a Breadth-first search
    std::list<int> larg;
    int vertice1;

   
    larg.push_back(r);  

    while(!larg.empty()){
        vertice1 = larg.front();
        int i = Translate(vertice1);
        if(i != -1){
            std::list< std::pair < int,int> > edges = ShuffleList(G[vertice1]);
            for(auto const& x : edges){
                if(keys[i++]){
                    if(PutEdge(vertice1,x.first,x.second))
                        larg.push_back(x.first);
                    else
                        this->keys[i-1] = false;
                    
                }

            }
        }
        larg.pop_front();

    }

    
}

std::list< std::pair < int,int> > Tree::ShuffleList(std::list< std::pair < int,int> > lst){
    // create a vector of (wrapped) references to elements in the list
    // http://en.cppreference.com/w/cpp/utility/functional/reference_wrapper

    std::vector< std::pair < int,int>  > vec( lst.begin(), lst.end() ) ;

    // shuffle (the references in) the vector
    std::shuffle( vec.begin(), vec.end(), std::mt19937{ std::random_device{}() } ) ;

    // copy the shuffled sequence into a new list
    std::list<std::pair < int,int>> shuffled_list {  vec.begin(), vec.end() } ;

    return shuffled_list;
}

int Tree::Translate(int v){
    int i = 0;
    for(auto const& x : SizeReference){
        if(x.first == v)
            return i;
        else
            i+= x.second;

    }
    return -1;
}


bool Tree::PutEdge( int v1, int v2 , int w)
{
    if(v2 == r) return false; //points to root.

    if(InT(v2)) return false; //points to a vertice in the tree. CICLE
    
    

    std::map<int,std::list < std::pair <int, int> > >::iterator it;
    it = T.find(v1);
    if (it != T.end())
        {
            T[v1].push_back(std::make_pair(v2,w));
        }
    else 
    {
        T[v1]  = {std::make_pair(v2,w)};;  
        
    }

    verticesIn.push_back(v2);
    verticesIn.sort();
  
    return true;
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


void Tree::Prune(){


    TCopy = T;
    T.clear();
    PruneRec(r);

        
}

void Tree::PruneRec(int v) {


        bool exists = true;
        try
        {
            TCopy.at(v);
        }
        catch(const std::exception& e)
        {
            exists = false;
        }
        if(exists){
        
        for(std::pair<int,int> x: TCopy.at(v))
        {
            T[v].push_back(x);
            PruneRec(x.first);
        
        }
        }


}

int Tree::GetWeight(){
    int w = 0;

    for(auto const& x : T){
        for(auto const& j : x.second){
        w += j.second;
        
        }
    }
    return w;
}


int Tree::GetNumbersOfRsIn(){

    int i = 1;
    for( auto const& x : T )
    {
        for( auto const& j : x.second )
        {
            if(Rvector[j.first])
                i++;
        }
    }

    return i;

}

void Tree::CalculateFitness(){
    int fit = GetWeight();
    fit += (R.size() - GetNumbersOfRsIn())*1000;

    fitness = fit;

}

void Tree::ConstructDeep(std::vector<bool> keys){

    this->keys = keys;
    DeepRec(r);

}


void Tree::DeepRec(int v) {


    int i = Translate(v);
    if(i != -1){
        std::list< std::pair < int,int> > edges = ShuffleList(G[v]);        
        for(auto const& x : edges){
            if(keys[i++]){
                if(PutEdge(v,x.first,x.second))
                    DeepRec(x.first);
                else
                    this->keys[i-1] = false;
                    
            }
        }
    }
}

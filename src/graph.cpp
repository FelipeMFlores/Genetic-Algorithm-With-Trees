#include "../include/graph.h"

Graph::Graph(){}

Graph::Graph (int id)
{ 
    this->id = id;
    nvertices = 0;
}


Graph::~Graph()
{
}


void Graph::PrintGraph ()
{
    
    std::list < std::pair <int, int> > val;
    for( auto const& x : G )
    {
        std::cout << x.first  << " : ";       
        for( auto const& i : x.second )
            std::cout  << i.first << " , " << i.second  << "; " ;    
        std::cout << std::endl ;
    }


}

void Graph::InputGraph(std::string inputFile)
{
   
    std::string strR;
    std::ifstream myfile (inputFile);
    if (myfile.is_open())
    {
        if( getline (myfile,strR) ){
            std::istringstream is( strR );
            int n;
            while( is >> n ) {
                R.push_back(n);
                
            }
            r = R.front();
            R.sort(); 
        }
        int v1,v2,w;
        std::map<int,std::list < std::pair <int, int> > >::iterator it;

        while ( getline (myfile,strR) )
        {
            std::istringstream is( strR );
            is >> v1 >> v2 >> w;

            if(v1 > nvertices)
            nvertices = v1;
            if(v2 > nvertices)
                nvertices = v2;


            it = G.find(v1);
            if (it != G.end())
                G[v1].push_back(std::make_pair(v2,w));
            else 
            {
                std::list < std::pair <int, int> > novo;
                novo.push_back(std::make_pair(v2,w));
                G[v1] = novo; 
            }


        }
    myfile.close();
    }
    createReference();

}

void Graph::createReference(){

    for(auto const& x : G){
        SizeReference[x.first] = x.second.size();
    }

}
void Graph::PrintReference(){
        
    
    for( auto const& x :  SizeReference)
    {
        std::cout << x.first  << " : " << x.second << std::endl;
    }


}

int Graph::GetNumberOfEdges()
{
    int i = 0;
    for( auto const& x : G )
    {
        i+= x.second.size();
    }

    return i;

}





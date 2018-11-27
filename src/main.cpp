#include "../include/main.h"
#include <math.h>

int main (int argc, char** argv)
{


    // -------INPUT GRAPH----------                    
    Graph firstgraph(0);  
    firstgraph.InputGraph(argv[1]);
    //firstgraph.PrintGraph();
    std::cout << std::endl<< std::endl<< std::endl<< std::endl;
    

  
    //   -------KEYS----------                    
    std::vector<bool> keys;
    int nedges = firstgraph.GetNumberOfEdges(); 
    keys.resize(nedges);
    std::generate (keys.begin(), keys.end(), Randomkey);

    //   -------CONSTRUCT TREE----------                    
    Tree firstTree(1 , firstgraph.GetR(), firstgraph.GetG(), firstgraph.Getr(),firstgraph.GetNVertices(),firstgraph.GetSizeReference());
    firstTree.ConstructTree(keys);



   }    

    
    return 0;
}
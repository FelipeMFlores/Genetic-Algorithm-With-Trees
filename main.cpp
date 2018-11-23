#include "main.h"


int main (int argc, char** argv)
{

    Graph firstgraph(0);  
    firstgraph.InputGraph();
    //firstgraph.PrintGraph();
    std::cout << std::endl << std::endl << std::endl << std::endl;
    
    std::vector<float> keys;
    int nedges = firstgraph.GetNumberOfEdges(); 
    keys.resize(nedges);
    

    
        std::cout << i << std::endl;
        std::generate (keys.begin(), keys.end(), Randomkey);

    
        Tree firstTree(i , firstgraph.GetR(), firstgraph.GetG(), firstgraph.Getr(),firstgraph.GetNVertices());
        firstTree.ConstructTree(keys);
    
    //firstTree.PrintTree();
    
    //std::cout << "Graph: " << firstgraph.GetNumberOfEdges() << std::endl;
    //std::cout << "Tree: " << firstTree.GetNumberOfEdgesT() << std::endl;

    return 0;
}
#include "../include/main.h"


int main (int argc, char** argv)
{


    /*    -------INPUT GRAPH----------                    */
    Graph firstgraph(0);  
    firstgraph.InputGraph(argv[1]);
    //firstgraph.PrintGraph();

    /*    -------KEYS----------                    */
    std::vector<float> keys;
    int nedges = firstgraph.GetNumberOfEdges(); 
    keys.resize(nedges);
    std::generate (keys.begin(), keys.end(), Randomkey);
    
    /*    -------CONSTRUCT TREE----------                    */
    Tree firstTree(1 , firstgraph.GetR(), firstgraph.GetG(), firstgraph.Getr(),firstgraph.GetNVertices());
    firstTree.ConstructTree(keys);
    //firstTree.PrintTree();

    /*    -------PRUNE TREE----------                    */
    std::cout << std::endl << std::endl;
    //std::cout << "Antes: " << firstTree.GetWeight() << std::endl;
    // firstTree.Prune(firstgraph.Getr());
    //std::cout << "Depois: " << firstTree.GetWeight() << std::endl;

    
    
    std::cout << "Graph: " << firstgraph.GetNumberOfEdges() << std::endl;
    std::cout << "Tree: " << firstTree.GetNumberOfEdgesT() << std::endl;

    return 0;
}
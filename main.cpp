#include "main.h"


int main (int argc, char** argv)
{

    Graph firstgraph(0);  
    firstgraph.InputGraph();
    //firstgraph.PrintGraph();
    std::cout << std::endl << std::endl << std::endl << std::endl;
    Tree firstTree(1 , firstgraph.GetR(), firstgraph.GetG(), firstgraph.Getr());
    std::vector<float> keys;
    int nedges = firstTree.GetNumberOfEdges(); 
    keys.resize(nedges);
    
    std::generate (keys.begin(), keys.end(), Randomkey);


    
    firstTree.ConstructTree(keys);



    return 0;
}
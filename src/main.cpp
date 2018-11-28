#include "../include/main.h"

int main (int argc, char** argv)
{


    // -------INPUT GRAPH----------                    
    Graph firstgraph(0);  
    firstgraph.InputGraph(argv[1]);
    //firstgraph.PrintGraph();
    std::cout << std::endl<< std::endl<< std::endl<< std::endl;

    GeneticAlgorithm(firstgraph);



    
    return 0;
}
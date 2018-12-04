#include "../include/GeneticAlgorithm.h"

int main (int argc, char** argv)
{
    /*******ARGVS
     * 1 = savefile
     * 2 = POPSIZE
     * 3 = KTOURN
     * 4 = MUTPROB  ex:if 5%,  5
     * 5 = TIMELIMIT
     * *********/


    //take the graph from the stdin  
      
    Graph graph(0);  
    graph.InputGraph();
    std::cout  << std::endl<< std::endl<< std::endl<< std::endl;
    graph.setSaveFile(argv[1]);

    //run the heuristic
    GeneticAlgorithm(graph, atoi(argv[2]),atoi(argv[3]) ,atoi(argv[4]),atoi(argv[5]) );



     
    return 0;
}
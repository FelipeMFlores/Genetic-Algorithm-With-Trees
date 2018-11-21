#include "graph.h"
#include "tree.h"


int main (int argc, char** argv)
{
    Graph firstgraph(0);  
    firstgraph.InputGraph();
    Tree firstTree(1 , firstgraph.GetR(), firstgraph.GetG());
    



    return 0;
}
#include "tree.h"
#include <fstream>
#include <time.h>  



void SaveKeys(std::string file);

void PrintPopulation();
void GeneticAlgorithm(Graph graph, int popsize, int ktourn, float mutprob, int timelimit);
void InitializePopulation(Graph graph);
void Fitness();
bool compareTrees(Tree t1, Tree t2);
std::pair < int, int > SelectForCrossover(std::uniform_int_distribution<int> distribution);
int Tournament(std::uniform_int_distribution<int> distribution);
std::vector<bool> Crossover(std::pair<int,int> parents);
int GetFromPopulationID(int id);
std::vector<bool> Mutation(std::vector< bool > keys);
void EnterPopulation(Tree child);

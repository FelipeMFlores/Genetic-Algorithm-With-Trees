#include "tree.h"
#include <fstream>
#define POPSIZE 50
#define KTOURN 3
#define MUTPROB 0.01


void SaveKeys();

void PrintPopulation();
void GeneticAlgorithm(Graph graph);
void InitializePopulation(Graph graph);
void Fitness();
bool compareTrees(Tree t1, Tree t2);
std::pair < int, int > SelectForCrossover();
int Tournament();
std::vector<bool> Crossover(std::pair<int,int> parents);
int GetFromPopulationID(int id);
std::vector<bool> Mutation(std::vector< bool > keys);
void EnterPopulation(Tree child);

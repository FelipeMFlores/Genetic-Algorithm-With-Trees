#include "tree.h"
#include <fstream>
#include <time.h>  


//Save the best key and your fitness in the file. 
void SaveKey(std::string file);

//Print all the fitness of the population
void PrintPopulation();

//The main method of the heuristic
void GeneticAlgorithm(Graph graph, int popsize, int ktourn, float mutprob, int timelimit);


//initializes the population with all keys 1
//contruct all trees.
void InitializePopulation(Graph graph);

//calculate the fitness of all population
//sort the population by it
void Fitness();

//compare which tree has the lowest fitness
bool compareTrees(Tree t1, Tree t2);

//select two parents by the k tournament method
std::pair < int, int > SelectForCrossover(std::uniform_int_distribution<int> distribution);
int Tournament(std::uniform_int_distribution<int> distribution);


std::vector<bool> Crossover(std::pair<int,int> parents);
int GetFromPopulationID(int id);
std::vector<bool> Mutation(std::vector< bool > keys);

//try to put a child in the population.
void EnterPopulation(Tree child);

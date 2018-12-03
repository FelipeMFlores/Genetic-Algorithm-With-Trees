#include "../include/GeneticAlgorithm.h"

    //RANDOM
    std::mt19937 rng(2018);
    std::uniform_int_distribution<int> distribution(0,1);
    std::uniform_real_distribution<float> distributionMut(0,1); 
    float RandomBool(){ return distribution(rng);}
    float RandomMut(){ return distributionMut(rng);}


//PARAMETERS
int POPSIZE;  //50;
int KTOURN; //3;
float MUTPROB;  //0.01;
int TIMELIMIT; //7200; //seconds

std::vector< Tree > population;
int idcont = 1;


void GeneticAlgorithm(Graph graph, int popsize, int ktourn, float mutprob, int timelimit){

    POPSIZE = popsize;  
    KTOURN = ktourn; 
    MUTPROB = mutprob/100;  
    TIMELIMIT = timelimit; 

    std::uniform_int_distribution<int> distributionTourn(0,POPSIZE-1);
    population.resize(POPSIZE);

 
    time_t timer;
    time_t timer2;
    time(&timer);

    InitializePopulation(graph);
    
    Fitness();

    int best = 99999999;
    int i = 0;
    int j = 0;
    while(true){
        std::pair<int,int> parents = SelectForCrossover(distributionTourn);
        std::vector<bool> childKeys = Crossover(parents);
        childKeys = Mutation(childKeys);
        Tree child(idcont++,graph);
        child.ConstructTree(childKeys);
        child.CalculateFitness();
        EnterPopulation(child);
        if(population[0].GetFitness() < best){std::cout << "NEW BEST: " << population[0].GetFitness() << std::endl; best = population[0].GetFitness(); }
        i++;
        if(i > 30000){std::cout << "                                        BEST 10: " 
                    << population[0].GetFitness() << " - " << population[1].GetFitness() << " - "
                    << population[2].GetFitness() << " - " << population[3].GetFitness() << " - "
                    << population[4].GetFitness() << " - " << population[5].GetFitness() << " - "
                    << population[6].GetFitness() << " - " << population[7].GetFitness() << " - "
                    << population[8].GetFitness() << " - " << population[9].GetFitness() << " - "
                    << population[10].GetFitness() 
                    << std::endl;i =0; 
                    j++;
                    time(&timer2);
                    if(difftime(timer2,timer) > TIMELIMIT){
                    SaveKeys(graph.getSaveFile());
                    break;
                    }
                    
                    }  

    }
    std::cout << "Best Result Found: " << population[0].GetFitness() << std::endl;

}

void SaveKeys(std::string file){
    
    std::ofstream myfile (file);
 
    if (myfile.is_open())
    {
       
        std::vector<bool> k = population[0].GetKeys();
        myfile << "[";
        for(unsigned x = 0; x < k.size();x++) 
                    myfile << k[x] << ", ";
        myfile << "]" << std::endl;
        myfile << "Result: " << population[0].GetFitness();

        myfile.close();
        std::cout << "                                                                  SAVED\n";
    }
    else
        std::cout << "ERRO AO SALVAR KEYS\n";
}


void InitializePopulation(Graph graph){

    
    std::vector<bool> keys;
    int nedges = graph.GetNumberOfEdges(); 
    keys.resize(nedges,true);
    
    for(int i = 0;i < POPSIZE; i++){
        Tree tree(idcont++ , graph);
        tree.ConstructTree(keys);
        population[i] = tree;
        
    }

}



void Fitness(){
    
    for(int i = 0; i<POPSIZE;i++){
        population[i].CalculateFitness();
    }
    std::sort(population.begin(),population.end(), compareTrees);
}

bool compareTrees(Tree t1, Tree t2){
    return t1.GetFitness() < t2.GetFitness();

}

std::pair < int, int > SelectForCrossover(std::uniform_int_distribution<int> distribution){
    int first,second;
    first = Tournament(distribution);
    second = Tournament(distribution);
    while(first == second)
        second = Tournament(distribution);

    return std::make_pair(first,second);
}

int Tournament(std::uniform_int_distribution<int> distribution){
    std::vector<bool> selected(POPSIZE,false);
    int i = 0;
    int r;
    while(i <= KTOURN){
        r = distribution(rng);
        if(!selected[r]){
            selected[r] = true;
            i++;
        }
    }
    
    for(int i = 0 ; i < POPSIZE ; i++){
        if(selected[i])
            return population[i].id;
    }

    return -1;
}

std::vector<bool> Crossover(std::pair<int,int> parents){
    int parent1 = GetFromPopulationID(parents.first);
    int parent2 = GetFromPopulationID(parents.second);

    std::vector<bool> keys1 = population[parent1].GetKeys();
    std::vector<bool> keys2 = population[parent2].GetKeys();
    std::vector<bool> childKeys(keys1.size());
    for(unsigned i = 0; i < keys1.size();i++)
        if(RandomBool())
            childKeys[i] = keys1[i];
        else
            childKeys[i] = keys2[i];

    return childKeys;
}

int GetFromPopulationID(int id){
    for(int i = 0; i < POPSIZE;i++)
        if(population[i].id == id)
            return i;

    return -1;   
}
void PrintPopulation(){
    for(int i = 0; i < POPSIZE; i++)
        std::cout << i << " : " << population[i].id << " - " << population[i].GetFitness() << std::endl;
}

std::vector<bool> Mutation(std::vector< bool > keys){
    for(unsigned i = 0; i < keys.size();i++)
        if(RandomMut() <= MUTPROB)
            keys[i] = !keys[i];
    
    return keys;
    
}

void  EnterPopulation(Tree child){

    if(population[POPSIZE-1].GetFitness() > child.GetFitness()){
        population.pop_back();
        population.push_back(child);
        std::sort(population.begin(),population.end(), compareTrees);
    }
}
#include "../include/GeneticAlgorithm.h"

std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> distribution(0,1);
std::uniform_int_distribution<int> distributionTourn(0,POPSIZE-1);
std::uniform_real_distribution<float> distributionMut(0,1);
float RandomInd(){ return distributionTourn(rng);}
float RandomBool(){ return distribution(rng);}
float RandomMut(){ return distributionMut(rng);}

std::vector< Tree > population(POPSIZE);
int idcont = 1;


void GeneticAlgorithm(Graph graph){

    InitializePopulation(graph);
    
    Fitness();

    int best = 99999999;
    int i = 0;
    int j = 0;
    while(true){
        std::pair<int,int> parents = SelectForCrossover();
        std::vector<bool> childKeys = Crossover(parents);
        childKeys = Mutation(childKeys);
        Tree child(idcont++,graph);
        child.ConstructTree(childKeys);
        child.CalculateFitness();
        EnterPopulation(child);
        if(population[0].GetFitness() < best){std::cout << population[0].GetFitness() << std::endl; best = population[0].GetFitness(); }
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
                    if(j > 30){
                        SaveKeys();
                        j=0;
                    }
                    }  
    }


}

void SaveKeys(){
    
    std::ofstream myfile ("backupKeys.txt");
 
    if (myfile.is_open())
    {
        for(int i = 0;i<POPSIZE;i++){
            std::vector<bool> k = population[i].GetKeys();
            myfile << "[";
            for(unsigned x = 0; x < k.size();x++) 
                        myfile << k[x] << ", ";
            myfile << "]" << std::endl;
        }

        myfile.close();
        std::cout << "                                                                  SAVED\n";
    }
    else
        std::cout << "ERRO AO SALVAR KEYS\n";
}


void InitializePopulation(Graph graph){

    
    std::vector<bool> keys;
    int nedges = graph.GetNumberOfEdges(); 
    //keys.resize(nedges);
    /*
    for(int i = 0;i < POPSIZE; i++){
        Tree tree(idcont++ , graph);
        std::generate (keys.begin(), keys.end(), RandomBool);
        tree.ConstructTree(keys);
        population[i] = tree;
        
    }*/
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
    if((t1.GetFitness()/1000 == t2.GetFitness()/1000)  && t2.GetFitness()/1000 != 0)
       return t1.GetFitness() > t2.GetFitness();
    return t1.GetFitness() < t2.GetFitness();

}

std::pair < int, int > SelectForCrossover(){
    int first,second;
    first = Tournament();
    second = Tournament();
    while(first == second)
        second = Tournament();

    return std::make_pair(first,second);
}

int Tournament(){
    std::vector<bool> selected(POPSIZE,false);
    int i = 0;
    int r;
    while(i <= KTOURN){
        r = RandomInd();
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
        std::cout << "                  " << child.GetFitness() << std::endl;
        std::sort(population.begin(),population.end(), compareTrees);
    }
}
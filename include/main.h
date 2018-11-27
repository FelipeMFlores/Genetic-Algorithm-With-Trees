#include "tree.h"

#include <random>


std::random_device rd;
std::mt19937 rng(rd());


std::uniform_int_distribution<int> distribution(0,1);


float Randomkey(){ return distribution(rng);}
    

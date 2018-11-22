#include "tree.h"

#include <random>


std::random_device rd;
std::mt19937 rng(rd());


std::uniform_real_distribution<float> distribution(0.0,1.0);


float Randomkey(){ return distribution(rng);}
    

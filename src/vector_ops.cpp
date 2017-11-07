#include "vector_ops.h"

#include <random>
#include <iostream>

vector_ops::vector_ops()
{
    //ctor
}

void vector_ops::GenRandomVector(std::vector<int> &v){

    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0,5000); // guaranteed unbiased

    for(int i = 0; i < v.size(); i++){
        v[i] = uni(rng);
    }
}

void vector_ops::ShowVector(std::vector<int> &v){

    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<"\t";
    }

}


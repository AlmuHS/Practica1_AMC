#include "GenVector.h"

GenVector::GenVector(std::vector<int> v)
{
    //ctor
    this->v = v;
}

std::vector<int> GenVector::GenRandomVector(){
    return this->v;
}

void GenVector::showVector(std::vector<int> v){

    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<" ";
    }
}

void GenVector::showVector(){

    for(int i = 0; i < this->v.size(); i++){
        std::cout<<this->v[i]<<" ";
    }
}


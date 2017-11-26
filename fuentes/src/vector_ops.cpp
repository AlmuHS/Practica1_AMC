/*Copyright 2017 Almudena Garcia Jurado-Centurion

This file is part of Practica1_AMC.

Practica1_AMC is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Practica1_AMC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Practica1_AMC.  If not, see <http://www.gnu.org/licenses/>.*/


#include "vector_ops.h"

#include <random>
#include <iostream>


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


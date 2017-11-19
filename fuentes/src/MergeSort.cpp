/*Copyright 2016 2017 Almudena Garcia Jurado-Centurion

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


#include "MergeSort.h"

void MergeSort::OrdenaMergesort(std::vector<int> &v){
    OrdenaMergesort(v, 0, v.size() - 1);
}

void MergeSort::OrdenaMergesort(std::vector<int> &v, int e, int d){
    if(e < d){
        int m = (e+d)/2;
        OrdenaMergesort(v, e, m);
        OrdenaMergesort(v, m+1, d);
        Merge(v, e, m,d);
    }
}

void MergeSort::Merge(std::vector<int> &v, int e, int m, int d){
    std::vector<int> B(d-e+1);
    int i = e;
    int j = m+1;
    int k = 0;

    while(i<=m && j<=d){
        if(v[i] <= v[j])
            B[k++] = v[i++];
        else
            B[k++] = v[j++];
    }

    while(i <= m)
        B[k++] = v[i++];

    while(j<=d)
        B[k++] = v[j++];

    for(k=0; k<=d-e; ++k)
        v[e+k] = B[k];
}

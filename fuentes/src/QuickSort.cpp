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


#include "QuickSort.h"

using namespace std;

void QuickSort::OrdenaQuickSort(vector<int> &v){
    OrdenaQuickSort(v, 0, v.size() - 1);
}

void QuickSort::OrdenaQuickSort(vector<int> &v, int e, int d){
    if (e < d){
        int q = Partition(v, e, d);
        OrdenaQuickSort(v, e, q);
        OrdenaQuickSort(v, q+1, d);
    }
}
int QuickSort::Partition(vector<int> &v, int e, int d){
    int x = v[e];
    int i = e - 1;
    int j = d + 1;

    for(;;){
        while(x < v[--j]);
        while(v[++i] < x);

        if(i >= j) return j;
        swap(v[i], v[j]);
    }
}

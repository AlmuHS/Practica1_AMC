#include "../include/MergeSort.h"

void MergeSort::OrdenaMergesort(std::vector<int> v){
    OrdenaMergesort(v, 0, v.size() - 1);
}

void MergeSort::OrdenaMergesort(std::vector<int> v, int e, int d){
    if(e < d){
        int m = (e+d)/2;
        OrdenaMergesort(v, e, m);
        OrdenaMergesort(v, m+1, d);
        Merge(v, e, m,d);
    }
}

void MergeSort::Merge(std::vector<int> v, int e, int m, int d){
    int B[d-e+1];
    int i = e;
    int j = m+1;
    int k = 0;

    while(i<=m and j<=d){
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

#include "QuickSort.h"

using namespace std;

void QuickSort::OrdenaQuickSort(int v[], int size){
    OrdenaQuickSort(v, 0, size - 1);
}

void QuickSort::OrdenaQuickSort(int v[], int e, int d){
    if (e < d){
        int q = Partition(v, e, d);
        OrdenaQuickSort(v, e, q);
        OrdenaQuickSort(v, q+1, d);
    }
}
int QuickSort::Partition(int v[], int e, int d){
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

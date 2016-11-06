#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>    // std::swap


class QuickSort
{
    public:
        void OrdenaQuickSort(int v[], int size);

        void OrdenaQuickSort(int v[], int e, int d);

        int Partition(int v[], int e, int d);
};

#endif // QUICKSORT_H

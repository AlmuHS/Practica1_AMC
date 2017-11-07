#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>    // std::swap
#include <vector>


class QuickSort
{
    public:
        void OrdenaQuickSort(std::vector<int> &v);

        void OrdenaQuickSort(std::vector<int> &v, int e, int d);

        int Partition(std::vector<int> &v, int e, int d);
};

#endif // QUICKSORT_H

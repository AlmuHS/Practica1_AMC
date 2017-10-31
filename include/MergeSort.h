#include <vector>

#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort
{
    public:

    void OrdenaMergesort(std::vector<int> v);

    void OrdenaMergesort(std::vector<int> v, int e, int d);

    void Merge(std::vector<int> v, int e, int m, int d);
};

#endif // MERGESORT_H

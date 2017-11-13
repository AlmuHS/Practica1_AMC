#ifndef HASHSEARCH_H
#define HASHSEARCH_H

#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>
#include <array>

#include "AlgoritmosBusqueda.h"

using namespace std;


class HashSearch
{
    vector<list<int> > hash_opened;
    vector<int> hash_closed;

    public:
        HashSearch();

        void add_element_opened(vector<int> v);

        void add_element_closed(vector<int> v);

        int closed_hash(int intempts, int key, int size);

        void pop_element(vector<int> v);

        int search_element_opened(int key);

        int search_element_closed(int key);

};

#endif // HASHSEARCH_H

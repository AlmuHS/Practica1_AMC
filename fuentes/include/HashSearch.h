#ifndef HASHSEARCH_H
#define HASHSEARCH_H

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

#include "vector_ops.h"

using namespace std;


class HashSearch
{
    vector<list<int> > hash_opened;
    vector<int> hash_closed;

    public:
        HashSearch();

        void add_element_opened(vector<int> &v);

        void add_element_closed(vector<int> &v);

        int closed_hash(int intempts, int key, int size);

        int search_element_opened(int key);

        int search_element_closed(int key);

        void show_closed_table();

        void show_opened_table();

};

#endif // HASHSEARCH_H

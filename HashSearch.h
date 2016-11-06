#ifndef HASHSEARCH_H
#define HASHSEARCH_H

#include <unordered_map>

using namespace std;


class HashSearch
{
    unordered_map<int, int> hash_closed;
    unordered_multimap<int, int> hash_opened;

    public:
        HashSearch();

        void add_element_opened(int v[], int size);

        void add_element_closed(int v[], int size);


        void pop_element(int v[], int size);

        int search_element_opened(int key);

        int search_element_closed(int key);

};

#endif // HASHSEARCH_H

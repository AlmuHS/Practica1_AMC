#ifndef HASHSEARCH_H
#define HASHSEARCH_H

#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


class HashSearch
{
    unordered_map<int, int> hash_closed;
    //unordered_multimap<int, int> hash_opened;
    vector<list<int> > hash_opened;

    public:
        HashSearch();

        void add_element_opened(vector<int> v);

        void add_element_closed(vector<int> v);


        void pop_element(vector<int> v);

        int search_element_opened(int key);

        int search_element_closed(int key);

};

#endif // HASHSEARCH_H

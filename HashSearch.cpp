#include "HashSearch.h"

using namespace std;

HashSearch::HashSearch()
{

}

void HashSearch::add_element_opened(int v[], int size){
    for(int i=0; i<size; i++){
        hash_opened.emplace(v[i], i);
    }
}

void HashSearch::add_element_closed(int v[], int size){
    for(int i=0; i<size; i++){
        hash_closed.emplace(v[i], i);
    }
}

int HashSearch::search_element_opened(int key){
    unordered_multimap<int, int>::iterator it;
    it = hash_opened.find(key);

    return it->second;
}

int HashSearch::search_element_closed(int key){
    unordered_map<int, int>::iterator it;
    it = hash_closed.find(key);

    return it->second;
}



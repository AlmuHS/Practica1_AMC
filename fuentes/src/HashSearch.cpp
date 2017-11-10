#include "HashSearch.h"

using namespace std;

HashSearch::HashSearch()
{

}

void HashSearch::add_element_opened(vector<int> v)
{
    int pos;

    hash_opened.assign(v.size(), list<int>());

    for(int i = 0; i < v.size(); i++)
    {
        pos = v[i] % v.size(); //Funcion hash
        hash_opened[pos].push_back(v[i]);
    }
}

void HashSearch::add_element_closed(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        hash_closed.emplace(v[i], i);
    }
}

int HashSearch::search_element_opened(int key)
{
    int pos = key % hash_opened.size();

    if(!hash_opened.at(pos).empty()){

        std::list<int>::const_iterator it = hash_opened.at(pos).begin();

        while(*it != key && it != hash_opened[pos].end()) it++;
        //std::list<int>::const_iterator it = std::find(begin(hash_opened[pos]), end(hash_opened[pos]), key);

        if(it != end(hash_opened[pos])) return pos;
    }

    return -1;
}

int HashSearch::search_element_closed(int key)
{
    unordered_map<int, int>::iterator it;
    it = hash_closed.find(key);

    return it->second;
}



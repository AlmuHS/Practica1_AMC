#include "HashSearch.h"
#include <cmath>
#include <iostream>

using namespace std;

const float inv_aurea = 2/(1 + sqrt(5));

HashSearch::HashSearch()
{

}

void HashSearch::add_element_opened(vector<int> v)
{
    hash_opened.assign(v.size(), list<int>());
    int pos = 0;

    for(int i = 0; i < v.size(); i++)
    {
        pos = trunc(v.size() * (v[i]* inv_aurea - trunc(v[i] * inv_aurea) ) );

        hash_opened[pos].push_back(v[i]);
    }
}

void HashSearch::add_element_closed(vector<int> v)
{
    hash_closed.assign(v.size(), -1);
    int pos = 0;

    bool vacia = false;
    int intentos = 1;

    for(int i = 0; i < v.size(); i++)
    {
        vacia = false;
        intentos = 1;

        while(!vacia){

            if(intentos < v.size()/4 + 3)
                pos = trunc(v.size() * (v[i]* inv_aurea * intentos - trunc(v[i] * inv_aurea * intentos) ) );

            else pos = (v[i] + intentos) % v.size();

            if(hash_closed[pos] == -1) vacia = true;
            intentos++;
        }

        if(vacia) hash_closed[pos] = v[i];

    }
}

int HashSearch::search_element_opened(int key)
{
    //int pos = key % hash_opened.size();
    int pos = trunc(hash_opened.size() * (key * inv_aurea - trunc(key * inv_aurea) ) );

    if(!hash_opened.at(pos).empty()){

        std::list<int>::const_iterator it = hash_opened.at(pos).begin();

        while(*it != key && it != hash_opened[pos].end()) it++;

        if(it != hash_opened[pos].end()) return pos;
    }

    return -1;
}

int HashSearch::search_element_closed(int key)
{
    int intentos = 1;

    int pos = trunc(hash_closed.size() * (key * inv_aurea - trunc(key * inv_aurea) ));

    while(hash_closed[pos] != key){

        if(intentos < hash_closed.size()/4 + 3)
            pos = trunc(hash_closed.size() * (key * inv_aurea * intentos - trunc(key * inv_aurea * intentos) ) );

        else pos = (key + intentos) % hash_closed.size();
        intentos++;
    }

    if(hash_closed[pos] == key) return pos;

    return -1;
}



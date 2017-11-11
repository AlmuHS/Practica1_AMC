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

    for(int i = 0; i < v.size(); i++)
    {
        int pos = v[i] % v.size(); //Funcion hash
        hash_opened[pos].push_back(v[i]);
    }
}

void HashSearch::add_element_closed(vector<int> v)
{
    hash_closed.assign(v.size(), -1);
    int pos = 0;
    int max_intentos = 4;

    for(int i = 0; i < v.size(); i++)
    {
        bool vacia = false;
        int intentos = 1;

        //Si la posicion esta ocupada, se recalcula la hash a partir del numero de intentos realizados
        while(intentos < max_intentos && !vacia){
            pos = trunc(v.size() * (float(v[i])* inv_aurea - trunc(v[i] * inv_aurea) - 1/intentos ) );

            if(hash_closed[pos] == -1) vacia = true;
            intentos++;
        }//Fin while

        if(vacia) hash_closed[pos] = v[i];

        else if(intentos == max_intentos){
            pos = v.size() - 1;
            while(hash_closed[pos] != -1) pos--;

            if(pos >= 0) hash_closed[pos] = v[i];
        }
    }
}

int HashSearch::search_element_opened(int key)
{
    int pos = key % hash_opened.size();

    if(!hash_opened.at(pos).empty()){

        std::list<int>::const_iterator it = hash_opened.at(pos).begin();

        while(*it != key && it != hash_opened[pos].end()) it++;
        //std::list<int>::const_iterator it = std::find(begin(hash_opened[pos]), end(hash_opened[pos]), key);

        if(it != hash_opened[pos].end()) return pos;
    }

    return -1;
}

int HashSearch::search_element_closed(int key)
{

    int pos = key % hash_closed.size();
    int intentos = 1;
    int max_intentos = 4;

    while(hash_closed[pos] != key && intentos < max_intentos){
        pos = trunc(hash_closed.size() * (float(key)* inv_aurea - trunc(key * inv_aurea) - 1/intentos ) );

        intentos++;
    }
    if(hash_closed[pos] == key) return pos;

    else if(intentos == max_intentos){
        std::vector<int>::iterator it = std::find(begin(hash_closed), end(hash_closed), key);

        if(it != hash_closed.end()) return pos;
    }

    return -1;
}



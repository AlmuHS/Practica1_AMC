#include "HashSearch.h"

using namespace std;

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

    for(int i = 0; i < v.size(); i++)
    {
        //hash_closed.emplace(v[i], i);
        bool vacia = false;
        int intentos = 1;

        //Si la posicion esta ocupada, se recalcula la hash a partir del numero de intentos realizados
        while(intentos < 3 && !vacia){
            pos = (v[i] % v.size()) / intentos;

            if(hash_closed[pos] == -1) vacia = true;
            intentos++;
        }//Fin while

        if(vacia) hash_closed[pos] = v[i];

        //Si despues de 3 intentos, no se ha logrado alojar, se hace una busqueda lineal del primer elemento vacío
        else if(intentos == 3){
            pos = 0;
            while(hash_closed[pos] != -1) pos++;

            if(pos < v.size()) hash_closed[pos] = v[i];
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
    //unordered_map<int, int>::iterator it;
    //it = hash_closed.find(key);
    int pos = key % hash_closed.size();
    int intentos = 1;

    while(hash_closed[pos] != key && intentos < 3){
        pos = (key % hash_closed.size()) / intentos;
        intentos++;
    }
    if(hash_closed[pos] == key) return pos;

    else if(intentos == 3){
        std::vector<int>::iterator it = std::find(begin(hash_closed), end(hash_closed), key);

        if(it != hash_closed.end()) return pos;
    }

    return -1;
}



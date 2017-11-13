#include "HashSearch.h"
#include <cmath>

using namespace std;

constexpr float inv_aurea = 2/(1 + sqrt(5));

HashSearch::HashSearch()
{

}

void HashSearch::add_element_opened(vector<int> v)
{
    hash_opened.assign(v.size(), list<int>());
    int pos = 0;
    int tam = v.size();

    for(int i = 0; i < tam; i++)
    {
        pos = trunc(tam * (v[i]* inv_aurea - trunc(v[i] * inv_aurea) ) );

        hash_opened[pos].push_back(v[i]);
    }
}

void HashSearch::add_element_closed(vector<int> v)
{
    int pos = 0;
    AlgoritmosBusqueda buscar;

    bool vacia = false;
    int intentos = 1;
    int tam = v.size();
    int max_intentos = tam/2; //Limite para cambiar de funcion hash
    int top_intentos = 2 * tam; //Limite para busqueda secuencial

    hash_closed.assign(tam, -1);

    for(int i = 0; i < tam; i++)
    {
        vacia = false;
        intentos = 1;

        while(!vacia && intentos < top_intentos){

            if(intentos < max_intentos)
                pos = trunc(tam * (v[i]* inv_aurea * intentos - trunc(v[i] * inv_aurea * intentos) ) );

            else pos = (v[i] + intentos) % tam;

            if(hash_closed[pos] == -1) vacia = true;
            else if(pos < tam-1 && hash_closed[pos+1] == -1){
                vacia = true;
                pos++;
            }
            else if(pos > 0 && hash_closed[pos-1] == -1){
                vacia = true;
                pos--;
            }
            else intentos++;
        }

        if(vacia) hash_closed[pos] = v[i];

        else if(intentos == top_intentos){
            pos = buscar.busquedaSecuencial(hash_closed, -1);
            hash_closed[pos] = v[i];
        }

    }
}

int HashSearch::search_element_opened(int key)
{
    int tam = hash_opened.size();
    int pos = trunc(tam * (key * inv_aurea - trunc(key * inv_aurea) ) );

    if(!hash_opened.at(pos).empty()){

        std::list<int>::const_iterator it = hash_opened.at(pos).begin();

        while(*it != key && it != hash_opened[pos].end()) it++;

        if(it != hash_opened[pos].end()) return pos;
    }

    return -1;
}

int HashSearch::search_element_closed(int key)
{
    AlgoritmosBusqueda buscar;
    int intentos = 1;
    int tam = hash_closed.size();
    int max_intentos = tam/2;
    int top_intentos = 2 * tam;

    int pos = trunc(tam * (key * inv_aurea - trunc(key * inv_aurea) ));

    while(hash_closed[pos] != key && intentos < top_intentos){

        if(intentos < max_intentos)
            pos = trunc(tam * (key * inv_aurea * intentos - trunc(key * inv_aurea * intentos) ) );

        else pos = (key + intentos) % hash_closed.size();

        if(hash_closed[pos] == key) return pos;
        else if(pos < tam-1 && hash_closed[pos+1] == key)  return pos+1;
        else if(pos > 0 && hash_closed[pos-1] == key)   return pos-1;

        intentos++;
    }

    if(intentos == top_intentos) return buscar.busquedaSecuencial(hash_closed, key);
}



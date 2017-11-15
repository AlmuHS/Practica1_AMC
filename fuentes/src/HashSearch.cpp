#include "HashSearch.h"
#include <cmath>

using namespace std;

constexpr float inv_aurea = 2/(1 + sqrt(5));

HashSearch::HashSearch()
{

}

/*Funcion de creacion de tabla hash con dispersión abierta
* Genera una tabla hash con dispersion abierta,
* basada en los datos de un vector ya existente
*
* En caso de colision, inserta el valor en una lista enlazada
* asociada a dicha posicion
*/

void HashSearch::add_element_opened(vector<int> &v)
{
    //Crea un nuevo vector de listas, del mismo tamaño que el vector inicial
    hash_opened.assign(v.size(), list<int>());
    int pos = 0;
    int tam = v.size();

    //Rellena la tabla con los datos del vector
    for(int i = 0; i < tam; i++)
    {
        //Ejecuta la funcion hash de gran dispersion para obtener la posicion
        pos = trunc(tam * (v[i]* inv_aurea - trunc(v[i] * inv_aurea) ) );

        //Inserta el elemento en la lista asociada a dicha posicion
        hash_opened[pos].push_back(v[i]);
    }
}

/*Funcion de creacion de tabla hash con dispersión cerrada
* Genera una tabla hash con dispersion cerrada, basada en los datos de un vector ya existente
*
* En caso de colision, se busca una nueva posición mediante rehashing o
* busqueda en las posiciones colindantes
*
* El rehashing se basará en el número de intentos realizados para insertar ese valor
*
* Combina 2 funciones hash: una de gran dispersion y otra de dispersion pequeña
* La segunda función se utilizará cuando los intentos superen el máximo establecido
*
* Si el numero de intentos supera la cota máxima (top_intentos),
* se considerará que la tabla esta llena, y que no es posible insertar el valor
*/

void HashSearch::add_element_closed(vector<int> &v)
{
    int pos = 0;

    bool vacia = false;//Centinela para indicar si se ha encontrado una posicion libre
    int intentos = 1; //Intentos de inserción realizados
    int tam = v.size();//Tamaño del vector
    int max_intentos = tam/2; //Limite para cambiar de funcion hash
    int top_intentos = 1.5 * tam + 1; //Limite para concluir la busqueda

    /*Creamos un nuevo vector, del mismo tamaño que el inicial
     *con posiciones inicializadas a -1*/
    hash_closed.assign(tam, -1);

    //Insertamos los valores en la tabla hash
    for(int i = 0; i < tam; i++)
    {
        vacia = false;
        intentos = 1; //Intentos de inserción del valor actual

        /*Mientras no encuentres una posicion vacia,
         *y no alcances el tope de intentos, continua buscando*/
        while(!vacia && intentos < top_intentos){

            //Mientras el numero de intentos no llegue al maximo, usa una funcion hash de gran dispersion
            if(intentos < max_intentos)
                pos = trunc(tam * (v[i]* inv_aurea * intentos - trunc(v[i] * inv_aurea * intentos) ) );

            /*Si alcanza el maximo de intentos, cambia a una funcion hash de menor dispersion, pero circular
             *Esta funcion hash recorrerá todas las posiciones de la tabla*/
            else pos = (v[i] + intentos) % tam;

            //Si la posicion obtenida esta libre, activa el centinela
            if(hash_closed[pos] == -1) vacia = true;

            //Si la posición obtenida esta ocupada, busca en las posicion anterior y posterior
            else if(pos < tam-1 && hash_closed[pos+1] == -1){
                vacia = true;
                pos++;
            }
            else if(pos > 0 && hash_closed[pos-1] == -1){
                vacia = true;
                pos--;
            }

            //Si no se ha obtenido una posicion libre, incrementa el numero de intentos y vuelve a intentarlo
            else intentos++;
        }

        //Si se ha encontrado una posicion vacia, asigna el valor a dicha posicion
        if(vacia) hash_closed[pos] = v[i];

        //Si la tabla esta llena, interrumpe la ejecucion
        else break;
    }
}

/* Funcion de busqueda en tablas hash con dispersion abierta
*  Busca en la tabla una clave dada
*
*  Ejecuta la función hash para obtener la posición asociada a la clave indicada
*  y realiza una busqueda secuencial para comprobar si la clave existe en dicha posicion
*
*  Si la clave no existe en la tabla, devuelve -1
*/

int HashSearch::search_element_opened(int key)
{
    int tam = hash_opened.size(); //Tamaño del vector

    //Obtenemos la posición asociada a dicha clave,
    // mediante la misma funcion hash usada para insertarla
    int pos = trunc(tam * (key * inv_aurea - trunc(key * inv_aurea) ) );

    //Si la posicion no esta vacia, haz una busqueda secuencial del elemento
    if(!hash_opened.at(pos).empty()){

        std::list<int>::const_iterator it = hash_opened.at(pos).begin();

        while(*it != key && it != hash_opened[pos].end()) it++;

        //Si se ha encontrado el valor, devuelve su posicion
        if(it != hash_opened[pos].end()) return pos;
    }

    //Si no se ha encontrado el valor, devuelve -1 para indicar que el valor no está en la tabla
    return -1;
}

/* Funcion de busqueda en tabla hash con dispersion cerrada
*  Busca en la tabla una clave dada
*
*  Ejecuta la funcion hash para obtener la posición asignada a dicha clave
*  Si la clave no está en dicha posición, se aplica el rehashing,
*  con el mismo algoritmo que se usó para la inserción
*
*  Si, tras llegar a la cota máxima de intentos, no se ha encontrado la clave,
*  asumimos que esta no se encuentra en la tabla, con lo cual devolvemos -1
*/


int HashSearch::search_element_closed(int key)
{
    int intentos = 1; //Contador de intentos
    int tam = hash_closed.size(); //Tamaño de la tabla hash
    int max_intentos = tam/2; //Limite para cambiar de funcion hash
    int top_intentos = 1.5 * tam + 1; //Limite para finalizar busqueda

    //Obtenemos la primera posición asociada a dicho valor
    int pos = trunc(tam * (key * inv_aurea - trunc(key * inv_aurea) ));

    //Si el valor no está en la posición, aplicamos rehashing para seguir buscando
    while(hash_closed[pos] != key && intentos < top_intentos){

        //Si el numero de intentos es menor que el máximo, usamos funcion de gran dispersion
        if(intentos < max_intentos)
            pos = trunc(tam * (key * inv_aurea * intentos - trunc(key * inv_aurea * intentos) ) );

        //Si superamos el maximo de intentos, cambia a funcion hash circular basada en módulo
        else pos = (key + intentos) % hash_closed.size();

        //Si se ha encontrado la clave, devuelve su posicion
        if(hash_closed[pos] == key) return pos;

        //Si no se ha encontrado, busca en las posiciones colindantes
        //y devuelve su posición en caso de exito
        else if(pos < tam-1 && hash_closed[pos+1] == key)  return pos+1;
        else if(pos > 0 && hash_closed[pos-1] == key)   return pos-1;

        //Si la clave aun no se ha encontrado, incrementa el numero de intentos para seguir buscando
        intentos++;
    }

    //Si llegamos a la cota maxima de intentos sin encontrar la clave,
    //asumimos que el valor no esta en la tabla, y devolvemos -1 para indicarlo
    return -1;
}

void HashSearch::show_closed_table(){
    vector_ops vops;

    vops.ShowVector(hash_closed);
}

void HashSearch::show_opened_table(){
    vector_ops vops;

    for(int i = 0; i < hash_opened.size(); i++){

            cout<<"Posicion "<<i<<": ";
            for(std::list<int>::const_iterator it = hash_opened[i].begin(); it != hash_opened[i].end(); it++){
                std::cout<<*it<<"\t";
            }

            cout<<endl;
    }
}



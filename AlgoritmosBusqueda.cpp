#include "AlgoritmosBusqueda.h"
#include "AlgoritmosOrdenacion.h"

AlgoritmosBusqueda::AlgoritmosBusqueda(void)
{
}


AlgoritmosBusqueda::~AlgoritmosBusqueda(void)
{
}

int AlgoritmosBusqueda::busquedaBinaria(int v[], int size, int key){
	int inf=0, sup=size, mitad;

	while(sup>=inf){
		mitad=(inf+sup)/2;
		if(v[mitad]==key) return mitad;
		else{
			if(key<v[mitad]) sup=mitad-1;
			else inf=mitad+1;
		}
	}
	return -1;
}

int AlgoritmosBusqueda::busquedaSecuencial(int v[], int size, int key){
	int i=0;
    int pos=0;

    while (v[i]!=key && i<size) i++;

    if(v[i]==key) pos=i;
    else pos=-1;

    return pos;
}



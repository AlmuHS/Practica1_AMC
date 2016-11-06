#include "AlgoritmosOrdenacion.h"

using namespace std;

AlgoritmosOrdenacion::AlgoritmosOrdenacion(void)
{
}


AlgoritmosOrdenacion::~AlgoritmosOrdenacion(void)
{
}

void AlgoritmosOrdenacion::OrdenaBurbuja(int v[], int size){
    int aux_elem;
    //int movs;
    //movs = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size -1; j > i; j--)
        {
            if (v[j] < v[j-1])
            {
                aux_elem = v[j];
                v[j] = v[j-1];
                v[j-1] = aux_elem;
                //movs++;
            }
        }//fin for j
    }//fin for i
}

void AlgoritmosOrdenacion::OrdenaInsercion(int v[], int size){
	int x, j, aux;

    for (int i=1; i<size; i++)
	{
		x=v[i];
		j=i-1;

		while (j>=0 && v[j]>x)
		{
			aux=v[j+1];
			v[j+1]=v[j];
			v[j]=aux;
			j=j-1;
		}
	}
}

void AlgoritmosOrdenacion::OrdenaSeleccion(int v[], int size){
	int posminimo=0, aux;
	for(int i=0; i<size; i++){
		posminimo=i;
		for(int j=i+1; j<size; j++){
			if(v[j]<v[posminimo]) posminimo=j;
		}
		aux=v[posminimo];
		v[posminimo]=v[i];
		v[i]=aux;
	}
}


void AlgoritmosOrdenacion::OrdenaShell(int v[], int size){
    for(int h = size/2; h > 0; h/=2){

        for(int i = h; i < size; i++){
            int j = i;
            int elem = v[i];

            while(j >= h && elem < v[j-h]){
                v[j] = v[j-h];
                j -= h;
            }

            v[j] = elem;
        }
    }
}



void AlgoritmosOrdenacion::OrdenaHeapSort(int v[], int size){
    priority_queue <int> pq;

    for(int i=0; i<size; i++)
        pq.push(v[i]);

    for(int i=size-1; i>= 0; i--){
        v[i]=pq.top();
        pq.pop();
    }

}



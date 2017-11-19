/*Copyright 2013 2014 2016 2017 Almudena Garcia Jurado-Centurion

This file is part of Practica1_AMC.

Practica1_AMC is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Practica1_AMC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Practica1_AMC.  If not, see <http://www.gnu.org/licenses/>.*/


#include "AlgoritmosOrdenacion.h"

using namespace std;

AlgoritmosOrdenacion::AlgoritmosOrdenacion(void)
{
}


AlgoritmosOrdenacion::~AlgoritmosOrdenacion(void)
{
}

void AlgoritmosOrdenacion::OrdenaBurbuja(vector<int> &v)
{
    int aux_elem;

    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = v.size() -1; j > i; j--)
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

void AlgoritmosOrdenacion::OrdenaInsercion(vector<int> &v)
{
    int x, j, aux;

    for (int i = 1; i < v.size(); i++)
    {
        x = v[i];
        j = i-1;

        while (j >= 0 && v[j] > x)
        {
            aux = v[j+1];
            v[j+1] = v[j];
            v[j] = aux;
            j = j - 1;
        }
    }
}

void AlgoritmosOrdenacion::OrdenaSeleccion(vector<int> &v)
{
    int posminimo = 0, aux;

    for(int i = 0; i < v.size(); i++)
    {
        posminimo = i;

        for(int j = i+1; j < v.size(); j++)
        {
            if(v[j] < v[posminimo]) posminimo = j;
        }

        aux = v[posminimo];
        v[posminimo] = v[i];
        v[i] = aux;
    }
}


void AlgoritmosOrdenacion::OrdenaShell(vector<int> &v)
{
    for(int h = v.size() / 2; h > 0; h /= 2)
    {

        for(int i = h; i < v.size(); i++)
        {
            int j = i;
            int elem = v[i];

            while(j >= h && elem < v[j-h])
            {
                v[j] = v[j-h];
                j -= h;
            }

            v[j] = elem;
        }
    }
}



void AlgoritmosOrdenacion::OrdenaHeapSort(vector<int> &v)
{
    priority_queue <int> pq;

    for(int i = 0; i < v.size(); i++)
        pq.push(v[i]);

    for(int i = v.size() - 1; i >= 0; i--)
    {
        v[i] = pq.top();
        pq.pop();
    }

}



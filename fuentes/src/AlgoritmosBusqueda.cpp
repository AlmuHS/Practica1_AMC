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


#include "AlgoritmosBusqueda.h"
#include "AlgoritmosOrdenacion.h"

AlgoritmosBusqueda::AlgoritmosBusqueda(void)
{
}


AlgoritmosBusqueda::~AlgoritmosBusqueda(void)
{
}

int AlgoritmosBusqueda::busquedaBinaria(std::vector<int> &v, int key){
	int inf = 0, sup = v.size(), mitad;

	while(sup >= inf){
		mitad = (inf+sup)/2;

		if(v[mitad] == key) return mitad;

		else{
			if(key < v[mitad]) sup = mitad-1;
			else inf = mitad+1;
		}
	}
	return -1;
}

int AlgoritmosBusqueda::busquedaSecuencial(std::vector<int> &v, int key){
	int i = 0;
    int pos = 0;

    while (v[i] != key && i < v.size()) i++;

    if(v[i] == key) pos = i;
    else pos = -1;

    return pos;
}

int AlgoritmosBusqueda::busquedaInterpolacion(std::vector<int> &v, int key){
	int p, primero, ultimo;

	primero = 0;
	ultimo = v.size() -1;

	while (v[ultimo] >= key && v[primero] < key){
		p = primero + ((ultimo - primero) * (key - v[primero]) / (v[ultimo] - v[primero]));

		if (key > v[p]) primero = p + 1;
		else{
			if (key < v[p]) ultimo = p - 1;
			else primero = p;
		}
	}

	if (v[primero] == key) return primero;
	else return -1;
}


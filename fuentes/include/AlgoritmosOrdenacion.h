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


#include <algorithm>    // std::swap
#include <queue>
#include <vector>

#ifndef ALGORITMOSORDENACION_
#define ALGORITMOSORDENACION_

class AlgoritmosOrdenacion
{
public:
	AlgoritmosOrdenacion(void);
	~AlgoritmosOrdenacion(void);
	/*
	* Función ordenaBurbuja, implementa el método de ordenación Burbuja
	* param v: el array de enteros a ordenar
	* param size: tamaño del array de enteros a ordenar
	*/
	void OrdenaBurbuja(std::vector<int> &v);
	/*
	* Función ordenaInsercion, implementa el método de ordenación por Inserción
	* param v: el array de enteros a ordenar
	* param size: tamaño del array de enteros a ordenar
	*/
	void OrdenaInsercion(std::vector<int> &v);
	/*
	* Función ordenaSeleccion, implementa el método de ordenación por Selección
	* param v: el array de enteros a ordenar
	* param size: tamaño del array de enteros a ordenar
	*/
	void OrdenaSeleccion(std::vector<int> &v);

    void OrdenaShell(std::vector<int> &v);

    void OrdenaHeapSort(std::vector<int> &v);
};

#endif

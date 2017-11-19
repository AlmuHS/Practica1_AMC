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



#include <vector>

#ifndef ALGORITMOSBUSQUEDA_
#define ALGORITMOSBUSQUEDA_

class AlgoritmosBusqueda
{
public:
	AlgoritmosBusqueda(void);
	~AlgoritmosBusqueda(void);
	/*
	* Función busquedabinaria, implementa el método de búsqueda binaria
	* param v: el array de enteros donde buscar
	* param size: tamaño del array
	* param key: clave o elemento a buscar
	* return posición de la clave en el array
	*/
	int busquedaBinaria(std::vector<int> &v, int key);
	/*
	* Función busquedaSecuencial, implementa el método de búsqueda secuencial
	* param v: el array de enteros donde buscar
	* param size: tamaño del array
	* param key: clave o elemento a buscar
	* return posición de la clave en el array
	*/
	int busquedaSecuencial(std::vector<int> &v, int key);


};

#endif

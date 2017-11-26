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



/*
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los métodos de ordenacion de la clase Ordenacion funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de ordenación,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente
 * 3. Comparar el coste temporal de dos de los métodos de ordenación
 *    burbuja, inserción, y selección, permitiendo guardar los datos e imprimir la
 *    gráfica correspondiente.
 */
#ifndef _TEST_ORDENACION
#define _TEST_ORDENACION

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

#include "AlgoritmosOrdenacion.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "vector_ops.h"

/* Constantes para indicar el metodo de ordenacion*/
static const int BURBUJA = 0;
static const int INSERCION = 1;
static const int SELECCION = 2;
static const int SHELL = 3;
static const int HEAPSORT = 4;
static const int QUICKSORT = 5;
static const int MERGESORT = 6;

/* Constantes para indicar el Numero de repeticiones para el caso medio de cada método de búsqueda */
static const int NUMREPETICIONES=10;

class TestOrdenacion {
	std::vector<std::string> nombreAlgoritmo;
public:

	TestOrdenacion();
/*
 * Ordena un array de enteros según el método indicado
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 * param metodo: Metodo de ordenacion a utilizar
 * return Tiempo empleado en la ordenación (en milisegundos)
 */
	static double ordenarArrayDeInt(std::vector<int> &v,int metodo);

/*
 * Comprueba que los metodos de ordenación funcionan correctamente
 */
	void comprobarMetodosOrdenacion();

/*
 * Compara dos metodos de ordenacion.
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo1: Primer metodo de ordenacion a comparar
 * param metodo2: Segundo metodo de ordenacion a comparar
 */
	void comparar(int metodo1, int metodo2);

/*
 * Calcula el caso medio de un metodo de ordenacion,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo: metodo de ordenacion a estudiar.
 */
	void casoMedio(int metodo);

	void generar_grafica(std::string metodo);
	void generar_grafica(std::string fichero1, std::string fichero2);

};
#endif

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

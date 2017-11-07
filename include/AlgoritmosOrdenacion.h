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
	* Funci�n ordenaBurbuja, implementa el m�todo de ordenaci�n Burbuja
	* param v: el array de enteros a ordenar
	* param size: tama�o del array de enteros a ordenar
	*/
	void OrdenaBurbuja(std::vector<int> &v);
	/*
	* Funci�n ordenaInsercion, implementa el m�todo de ordenaci�n por Inserci�n
	* param v: el array de enteros a ordenar
	* param size: tama�o del array de enteros a ordenar
	*/
	void OrdenaInsercion(std::vector<int> &v);
	/*
	* Funci�n ordenaSeleccion, implementa el m�todo de ordenaci�n por Selecci�n
	* param v: el array de enteros a ordenar
	* param size: tama�o del array de enteros a ordenar
	*/
	void OrdenaSeleccion(std::vector<int> &v);

    void OrdenaShell(std::vector<int> &v);

    void OrdenaHeapSort(std::vector<int> &v);
};

#endif

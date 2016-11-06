#include <algorithm>    // std::swap
#include <queue>

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
	void OrdenaBurbuja(int v[], int size);
	/*
	* Función ordenaInsercion, implementa el método de ordenación por Inserción
	* param v: el array de enteros a ordenar
	* param size: tamaño del array de enteros a ordenar
	*/
	void OrdenaInsercion(int v[], int size);
	/*
	* Función ordenaSeleccion, implementa el método de ordenación por Selección
	* param v: el array de enteros a ordenar
	* param size: tamaño del array de enteros a ordenar
	*/
	void OrdenaSeleccion(int v[], int size);

    void OrdenaShell(int v[], int size);

    void OrdenaHeapSort(int v[], int size);
};


#include <algorithm>    // std::swap
#include <queue>

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
	void OrdenaBurbuja(int v[], int size);
	/*
	* Funci�n ordenaInsercion, implementa el m�todo de ordenaci�n por Inserci�n
	* param v: el array de enteros a ordenar
	* param size: tama�o del array de enteros a ordenar
	*/
	void OrdenaInsercion(int v[], int size);
	/*
	* Funci�n ordenaSeleccion, implementa el m�todo de ordenaci�n por Selecci�n
	* param v: el array de enteros a ordenar
	* param size: tama�o del array de enteros a ordenar
	*/
	void OrdenaSeleccion(int v[], int size);

    void OrdenaShell(int v[], int size);

    void OrdenaHeapSort(int v[], int size);
};


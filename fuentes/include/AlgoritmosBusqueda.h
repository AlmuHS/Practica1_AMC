#include <vector>

#ifndef ALGORITMOSBUSQUEDA_
#define ALGORITMOSBUSQUEDA_

class AlgoritmosBusqueda
{
public:
	AlgoritmosBusqueda(void);
	~AlgoritmosBusqueda(void);
	/*
	* Funci�n busquedabinaria, implementa el m�todo de b�squeda binaria
	* param v: el array de enteros donde buscar
	* param size: tama�o del array
	* param key: clave o elemento a buscar
	* return posici�n de la clave en el array
	*/
	int busquedaBinaria(std::vector<int> &v, int key);
	/*
	* Funci�n busquedaSecuencial, implementa el m�todo de b�squeda secuencial
	* param v: el array de enteros donde buscar
	* param size: tama�o del array
	* param key: clave o elemento a buscar
	* return posici�n de la clave en el array
	*/
	int busquedaSecuencial(std::vector<int> &v, int key);


};

#endif

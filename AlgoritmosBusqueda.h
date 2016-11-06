
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
	int busquedaBinaria(int v[], int size, int key);
	/*
	* Función busquedaSecuencial, implementa el método de búsqueda secuencial
	* param v: el array de enteros donde buscar
	* param size: tamaño del array
	* param key: clave o elemento a buscar
	* return posición de la clave en el array
	*/
	int busquedaSecuencial(int v[], int size, int key);


};


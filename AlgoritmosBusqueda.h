
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
	int busquedaBinaria(int v[], int size, int key);
	/*
	* Funci�n busquedaSecuencial, implementa el m�todo de b�squeda secuencial
	* param v: el array de enteros donde buscar
	* param size: tama�o del array
	* param key: clave o elemento a buscar
	* return posici�n de la clave en el array
	*/
	int busquedaSecuencial(int v[], int size, int key);


};


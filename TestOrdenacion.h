/*
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los m�todos de ordenacion de la clase Ordenacion funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un m�todo de ordenaci�n,
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente
 * 3. Comparar el coste temporal de dos de los m�todos de ordenaci�n
 *    burbuja, inserci�n, y selecci�n, permitiendo guardar los datos e imprimir la
 *    gr�fica correspondiente.
 */
#ifndef _TEST_ORDENACION
#define _TEST_ORDENACION

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

/* Constantes para indicar el metodo de ordenacion*/
static const int BURBUJA = 0;
static const int INSERCION = 1;
static const int SELECCION = 2;
static const int SHELL = 3;
static const int HEAPSORT = 4;
static const int QUICKSORT = 5;
static const int MERGESORT = 6;

/* Constantes para indicar el Numero de repeticiones para el caso medio de cada m�todo de b�squeda */
static const int NUMREPETICIONES=10;

class TestOrdenacion {
	vector<string> nombreAlgoritmo;
public:

	TestOrdenacion();
	~TestOrdenacion();
/*
 * Ordena un array de enteros seg�n el m�todo indicado
 * param v: el array de enteros a ordenar
 * param size: tama�o del array de enteros a ordenar
 * param metodo: Metodo de ordenacion a utilizar
 * return Tiempo empleado en la ordenaci�n (en milisegundos)
 */
	static double ordenarArrayDeInt(vector<int> v,int metodo);

/*
 * Comprueba que los metodos de ordenaci�n funcionan correctamente
 */
	void comprobarMetodosOrdenacion();

/*
 * Compara dos metodos de ordenacion.
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param metodo1: Primer metodo de ordenacion a comparar
 * param metodo2: Segundo metodo de ordenacion a comparar
 */
	void comparar(int metodo1, int metodo2);

/*
 * Calcula el caso medio de un metodo de ordenacion,
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param metodo: metodo de ordenacion a estudiar.
 */
	void casoMedio(int metodo);
	void casoMejor(int metodo);
	void casoPeor(int metodo);

	void generar_grafica(string metodo);
	void generar_grafica(string fichero1, string fichero2);

};
#endif

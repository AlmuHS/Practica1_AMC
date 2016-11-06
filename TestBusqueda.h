#include <vector>
#include "AlgoritmosBusqueda.h"
#include "ConjuntoInt.h"
#include "Mtime.h"
#include "AlgoritmosOrdenacion.h"
#include "HashSearch.h"
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

static const int BINARIA = 0;
static const int SECUENCIAL = 1;
static const int HASHCLOSED = 2;
static const int HASHOPENED = 3;

class TestBusqueda
{
	vector<string> nombreAlgoritmo;
public:
	TestBusqueda(void);
	~TestBusqueda(void);
	void comprobarMetodosBusqueda();
	void comparar(int metodo1, int metodo2);
	void casoMedio(int metodo);
	void casoMejor(int metodo);
	void casoPeor(int metodo);
	double Buscar(int v[], int metodo, int size, int key);
	void generar_grafica(string metodo);
	void generar_grafica(string fichero1, string fichero2);
};


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


#include <vector>
#include "AlgoritmosBusqueda.h"
#include "Mtime.h"
#include "AlgoritmosOrdenacion.h"
#include "HashSearch.h"
#include "vector_ops.h"


#include <vector>
#include <fstream>
#include <chrono>
#include <string>

static const int BINARIA = 0;
static const int SECUENCIAL = 1;
static const int HASHCLOSED = 2;
static const int HASHOPENED = 3;


class TestBusqueda
{
	std::vector<string> nombreAlgoritmo;
public:
	TestBusqueda(void);
	~TestBusqueda(void);
	void comprobarMetodosBusqueda();
	void comparar(int metodo1, int metodo2);
	void casoMedio(int metodo);
	double Buscar(std::vector<int> &v, int metodo, int key);
	void generar_grafica(std::string metodo);
	void generar_grafica(std::string fichero1, std::string fichero2);
};


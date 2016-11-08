/*
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los métodos de ordenacion de la clase Ordenacion funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de ordenación,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente
 * 3. Comparar el coste temporal de dos de los métodos de ordenación
 *    burbuja, inserción, y selección, permitiendo guardar los datos e imprimir la
 *    gráfica correspondiente.
 */
#include "AlgoritmosOrdenacion.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "TestOrdenacion.h"
#include "ConjuntoInt.h"
#include "Mtime.h"
#include <string>
#include <iomanip>
#include <iostream>

#define NUMREPETICIONES 20
using namespace std;
using namespace std::chrono;

TestOrdenacion::TestOrdenacion()
{
	nombreAlgoritmo.push_back("Burbuja");
	nombreAlgoritmo.push_back("Insercion");
	nombreAlgoritmo.push_back("Seleccion");
	nombreAlgoritmo.push_back("Shell");
	nombreAlgoritmo.push_back("Heapsort");
	nombreAlgoritmo.push_back("QuickSort");
	nombreAlgoritmo.push_back("MergeSort");
}
TestOrdenacion::~TestOrdenacion(){}
/*
 * Ordena un array de enteros según el método indicado
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 * param metodo: Metodo de ordenacion a utilizar
 * return Tiempo empleado en la ordenación (en milisegundos)
 */
double TestOrdenacion::ordenarArrayDeInt(int v[],int size,int metodo)
{
	AlgoritmosOrdenacion estrategia;
	QuickSort QS;
	MergeSort MS;
    double tiempo;
    #if defined _WIN32 || defined _WIN64
        Mtime t;
        LARGE_INTEGER t_inicial, t_final;
        QueryPerformanceCounter(&t_inicial);
        /* Invoca al método de ordenación elegido */
        switch (metodo){
            case BURBUJA: estrategia.OrdenaBurbuja(v, size);
                break;
            case INSERCION: estrategia.OrdenaInsercion(v, size);
                break;
            case SELECCION: estrategia.OrdenaSeleccion(v, size);
                break;
            case SHELL:
                estrategia.OrdenaShell(v, size);
                break;
            case HEAPSORT:
                estrategia.OrdenaHeapSort(v, size);
                break;
            case QUICKSORT:
                QS.OrdenaQuickSort(v, size);
                break;
            case MERGESORT:
                MS.OrdenaMergesort(v,size);
                break;



        }
        QueryPerformanceCounter(&t_final);
        tiempo=t.performancecounter_diff(&t_final, &t_inicial) * 1000;
    #elif defined __linux__ || defined __unix__
        duration<double> interval;
        high_resolution_clock::time_point t_ini, t_fin;

        switch (metodo){
            case BURBUJA:
                t_ini = high_resolution_clock::now();
                estrategia.OrdenaBurbuja(v, size);
                t_fin = high_resolution_clock::now();
            break;

            case INSERCION:
                t_ini = high_resolution_clock::now();
                estrategia.OrdenaInsercion(v, size);
                t_fin = high_resolution_clock::now();
            break;

            case SELECCION:
                t_ini = high_resolution_clock::now();
                estrategia.OrdenaSeleccion(v, size);
                t_fin = high_resolution_clock::now();
            break;

            case SHELL:
                t_ini = high_resolution_clock::now();
                estrategia.OrdenaShell(v, size);
                t_fin = high_resolution_clock::now();
            break;

            case HEAPSORT:
                t_ini = high_resolution_clock::now();
                estrategia.OrdenaHeapSort(v, size);
                t_fin = high_resolution_clock::now();
            break;

            case QUICKSORT:
                t_ini = high_resolution_clock::now();
                QS.OrdenaQuickSort(v, size);
                t_fin = high_resolution_clock::now();
            break;

            case MERGESORT:
                t_ini = high_resolution_clock::now();
                MS.OrdenaMergesort(v,size);
                t_fin = high_resolution_clock::now();
            break;

        }
        interval = duration_cast<duration<double>>(t_fin - t_ini);
        tiempo=interval.count()*100000;
    #endif
    return tiempo;
}

/*
 * Comprueba los metodos de ordenacion
 */
void TestOrdenacion::comprobarMetodosOrdenacion()
{
	int talla;
	cout<<endl<<endl<<"Introduce la talla: ";
	cin>>talla;
	#if defined _WIN32 || defined _WIN64
        system("cls");
        system("pause");
    #elif defined __linux__ || defined __unix__
        system("clear");
    #endif // defined
	for (unsigned int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++){
		ConjuntoInt *v= new ConjuntoInt(talla);
		v->GeneraVector();
		cout <<endl<<endl<< "vector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
		ordenarArrayDeInt(v->get_datos(), talla, metodo);
        cout<<endl<<endl<<"Array ordenado con metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
		cout<<endl;
		v->vaciar();
    }
}

/*
 * Calcula el caso medio de un metodo de ordenacion,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo: metodo de ordenacion a estudiar.
 */
void TestOrdenacion::casoMedio(int metodo)
{
    int tallaIni = 500,
        tallaFin = 20000,
        incTalla = 500;
    vector<double> tiempos;
    string nombre_fichero=nombreAlgoritmo[metodo]+".dat";
    ofstream fichero(nombre_fichero.c_str());
    char opcion;
	double segundos=0, tiempo;
	AlgoritmosOrdenacion ordena;

    cout<<"Ordenacion por "<<nombreAlgoritmo[metodo]<<". Tiempos de ejecucion promedio\n";
	cout<<"\nTalla\t\t"<<"Tiempo\n\n";

	for(int i=tallaIni; i<tallaFin; i+=incTalla){
		ConjuntoInt v(i);
		int contador=0;
		segundos=0;
		while(contador < NUMREPETICIONES){
            v.GeneraVector();
			segundos+=ordenarArrayDeInt(v.get_datos(), i, metodo);
			contador++;
		}
		tiempo=segundos/NUMREPETICIONES;
		cout<<i<<"\t\t"<<tiempo<<endl;

		tiempos.push_back(tiempo);
	}//fin for

	cout<<"\n\nGrabar los datos en el fichero "<<nombre_fichero<<" ? (s/n): ";
	cin>>opcion;
	if(opcion=='s'){
        for(unsigned int j=0; j<tiempos.size(); j++){
            fichero<<500*j+500<<"\t\t"<<tiempos[j]<<endl;
        }
        cout<<"\n\nDatos grabados en el fichero "<<nombre_fichero
            <<"\n\nGenerar grafica de resultados? (s/n): ";
        cin>>opcion;
        if(opcion=='s') generar_grafica(nombre_fichero);
        fichero.close();
	}
}

/*
 * Compara dos metodos de ordenacion.
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo1: Primer metodo de ordenacion a comparar
 * param metodo2: Segundo metodo de ordenacion a comparar
 */
void TestOrdenacion::comparar(int metodo1, int metodo2) {
	int tallaIni = 500,
      tallaFin = 20000,
      incTalla = 500;

	double segundos1=0, segundos2=0, tiempo1, tiempo2;
	AlgoritmosOrdenacion ordena;
	string met1, met2;
	met1=nombreAlgoritmo[metodo1];
	met2=nombreAlgoritmo[metodo2];
    vector<double> tiempos1, tiempos2;
    char opcion;

	cout<<"Talla\t\t"<<met1<<"\t\t"<<met2<<endl<<endl;
	met1+=".dat";
	met2+=".dat";
	ofstream fichero1(met1.c_str()), fichero2(met2.c_str());
	for(int i=tallaIni; i<tallaFin; i+=incTalla){
		ConjuntoInt v(i);
		int *vector=v.get_datos();
		segundos1=0;
		int contador=0;
		while(contador < NUMREPETICIONES){
            v.GeneraVector();
			segundos1+=ordenarArrayDeInt(vector, i, metodo1);
			segundos2+=ordenarArrayDeInt(vector, i, metodo2);
			contador++;
		}
		tiempo1=segundos1/NUMREPETICIONES;
		tiempo2=segundos2/NUMREPETICIONES;
		cout<<i<<"\t\t"<<tiempo1<<"\t\t"<<tiempo2<<endl;

		tiempos1.push_back(tiempo1);
		tiempos2.push_back(tiempo2);
	}//fin for

	cout<<"\n\nGrabar datos en ficheros ? (s/n): ";
	cin>>opcion;
	if(opcion=='s'){
        for(unsigned int j=0; j<tiempos1.size(); j++){
            fichero1<<j*500+500<<"\t\t"<<tiempos1[j]<<endl;
            fichero2<<j*500+500<<"\t\t"<<tiempos2[j]<<endl;
        }
        cout<<"\nDatos guardados en los ficheros "<<met1<<" y "<<met2<<endl
            <<"\nGenerar grafica de resultados? (s/n): ";
        cin>>opcion;

        if(opcion == 's') generar_grafica(met1, met2);
	}

}

void TestOrdenacion::casoMejor(int metodo)
{
    int tallaIni = 500,
        tallaFin = 10000,
        incTalla = 1000;

	double segundos=0, tiempo;
	AlgoritmosOrdenacion ordena;

	cout<<"Talla\t\t"<<"Tiempo\n\n";
	for(int i=tallaIni; i<tallaFin; i+=incTalla){
		ConjuntoInt v(i);
		int *vector=v.get_datos();
		int contador=0;
		segundos=0;
		while(contador < NUMREPETICIONES){
            v.GeneraVector();
			segundos+=ordenarArrayDeInt(vector, i, metodo);
			contador++;
		}
		tiempo=segundos/NUMREPETICIONES;
		cout<<i<<"\t\t"<<tiempo<<endl;
	}//fin for
}

void TestOrdenacion::casoPeor(int metodo)
{
    int tallaIni = 100,
        tallaFin = 1000,
        incTalla = 100;

	double segundos=0, tiempo;
	AlgoritmosOrdenacion ordena;

	cout<<"Talla\t\t"<<"Tiempo\n\n";
	for(int i=tallaIni; i<tallaFin; i+=incTalla){
		ConjuntoInt v(i);
		v.GeneraVector();
		int contador=0;
		segundos=0;
		v.ordena_inverso();
		int *vector=v.get_datos();
		while(contador < NUMREPETICIONES){
			segundos+=ordenarArrayDeInt(vector, i, metodo);
			contador++;
		}
		tiempo=segundos/NUMREPETICIONES;
		cout<<i<<"\t\t"<<tiempo<<endl;
	}//fin for
}

void TestOrdenacion::generar_grafica(string metodo){
    string nom = "CmdMedio.plt";

    ofstream fout((char*)nom.c_str());

    #if defined __linux__ || defined __unix__
        fout<<"#!/usr/bin/gnuplot"<<endl;
    #endif

    fout << "set title \" Ordenacion " << metodo << "\"" << endl;
    fout << "set key top left vertical inside" << endl;
    fout << "set grid" << endl;
    fout << "set xlabel \"Talla (n)\"" << endl;
    fout << "set ylabel \"Tiempo (ms)\"" << endl;
    fout << "plot \"" << metodo << "\" using 1:2 with lines" << endl;
    if(metodo=="Shell.dat"){
        fout << "InsDir(x) = a + b*x*log(x)*log(x)" << endl;
        fout << "fit InsDir(x) \"" + metodo + "\" using 1:2 via a,b" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, InsDir(x)" << endl;
    }
    else if (metodo == "MergeSort.dat" || metodo == "Heapsort.dat" || metodo == "QuickSort.dat"){
        fout << "quick(x) = a*x*log(x)" << endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << endl;
    }
    else if (metodo == "Burbuja.dat" || metodo == "Insercion.dat" || metodo == "Seleccion.dat"){
        fout << "quick(x) = a*x*x + b" << endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a, b" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << endl;
    }
    fout << "set terminal png" << endl;
    fout << "set output \"" << metodo << ".png\"" << endl;
    fout << "replot" << endl;
    fout << "pause 10 \"Pulse Enter para continuar...\"" << endl;

    fout.close();
    #if defined __linux__ || defined __unix__
        system("chmod +x CmdMedio.plt");
        system("./CmdMedio.plt");
    #elif defined _WIN32 || defined _WIN64
        system("CmdMedio.plt");
    #endif
}

void TestOrdenacion::generar_grafica(string fichero1, string fichero2){
    ofstream graf("CmdCMP.plt");
    #if defined __linux__ || defined __unix__
        graf<<"#!/usr/bin/gnuplot"<<endl;
    #endif

	graf << "set title \""<<"Comparacion tiempos entre " << fichero1 <<" y "<< fichero2 << "\"" << "\n";
	graf << "set key top left vertical inside\n";
	graf << "set grid\n";
	graf << "set xlabel \"Talla (n)\"\n";
	graf << "set ylabel \"Tiempo (ms)\"\n";
	graf << "plot \"" << fichero1 << "\" using 1:2 with lines, \"" << fichero2 << "\" using 1:2 with lines" << endl;


	graf << "set terminal png" << endl;
    graf << "set output \"" << fichero1 << "-" <<fichero2 << ".png\"" << endl;
    graf << "replot" << endl;
    graf << "pause 10 \"Pulse Enter para continuar...\"" << endl;
	graf.close();
	#if defined __linux__ || defined __unix__
        system("chmod +x CmdCMP.plt");
        system("./CmdCMP.plt");
    #elif defined _WIN32 || defined _WIN64
        system("CmdCMP.plt");
    #endif
}


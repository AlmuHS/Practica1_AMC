/*
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los métodos de ordenacion de la clase Ordenacion funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de ordenación,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente
 * 3. Comparar el coste temporal de dos de los métodos de ordenación
 *    burbuja, inserción, y selección, permitiendo guardar los datos e imprimir la
 *    gráfica correspondiente.
 */
<<<<<<< HEAD:src/TestOrdenacion.cpp

#include "TestOrdenacion.h"

#include "Mtime.h"
=======
#include "../include/AlgoritmosOrdenacion.h"
#include "../include/QuickSort.h"
#include "../include/MergeSort.h"
#include "../include/TestOrdenacion.h"
#include "../include/Mtime.h"

>>>>>>> 98ef0e55704a2666b20fc497475a2f10a7098cf2:src/TestOrdenacion.cpp
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
TestOrdenacion::~TestOrdenacion() {}
/*
 * Ordena un array de enteros según el método indicado
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 * param metodo: Metodo de ordenacion a utilizar
 * return Tiempo empleado en la ordenación (en milisegundos)
 */

#if defined _WIN32 || defined _WIN64
<<<<<<< HEAD:src/TestOrdenacion.cpp
    double TestOrdenacion::ordenarArrayDeInt(vector<int> &v,int size,int metodo)
=======

    double TestOrdenacion::ordenarArrayDeInt(vector<int> v,int size,int metodo)
>>>>>>> 98ef0e55704a2666b20fc497475a2f10a7098cf2:src/TestOrdenacion.cpp
    {
        AlgoritmosOrdenacion estrategia;
        QuickSort QS;
        MergeSort MS;
        double tiempo;

        Mtime t;
        LARGE_INTEGER t_inicial, t_final;
        QueryPerformanceCounter(&t_inicial);
        /* Invoca al método de ordenación elegido */
        switch (metodo)
        {
        case BURBUJA:
            estrategia.OrdenaBurbuja(v, size);
            break;
        case INSERCION:
            estrategia.OrdenaInsercion(v, size);
            break;
        case SELECCION:
            estrategia.OrdenaSeleccion(v, size);
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
        tiempo = t.performancecounter_diff(&t_final, &t_inicial) * 1000;

        return tiempo;
    }

#elif defined __linux__ || defined __unix__

    double TestOrdenacion::ordenarArrayDeInt(vector<int> &v,int metodo)
    {
        AlgoritmosOrdenacion estrategia;
        QuickSort QS;
        MergeSort MS;
        double tiempo;

        duration<double> interval;
        high_resolution_clock::time_point t_ini, t_fin;

        switch (metodo)
        {
        case BURBUJA:
            t_ini = high_resolution_clock::now();
            estrategia.OrdenaBurbuja(v);
            t_fin = high_resolution_clock::now();
            break;

        case INSERCION:
            t_ini = high_resolution_clock::now();
            estrategia.OrdenaInsercion(v);
            t_fin = high_resolution_clock::now();
            break;

        case SELECCION:
            t_ini = high_resolution_clock::now();
            estrategia.OrdenaSeleccion(v);
            t_fin = high_resolution_clock::now();
            break;

        case SHELL:
            t_ini = high_resolution_clock::now();
            estrategia.OrdenaShell(v);
            t_fin = high_resolution_clock::now();
            break;

        case HEAPSORT:
            t_ini = high_resolution_clock::now();
            estrategia.OrdenaHeapSort(v);
            t_fin = high_resolution_clock::now();
            break;

        case QUICKSORT:
            t_ini = high_resolution_clock::now();
            QS.OrdenaQuickSort(v);
            t_fin = high_resolution_clock::now();
            break;

        case MERGESORT:
            t_ini = high_resolution_clock::now();
            MS.OrdenaMergesort(v);
            t_fin = high_resolution_clock::now();
            break;

        }
        interval = duration_cast<duration<double>>(t_fin - t_ini);
        tiempo=interval.count()*100000;

        return tiempo;
    }

#endif

/*
 * Comprueba los metodos de ordenacion
 */
void TestOrdenacion::comprobarMetodosOrdenacion()
{
    int talla;
    vector_ops vops;

    cout<<endl<<endl<<"Introduce la talla: ";
    cin>>talla;

    vector<int> v(talla);
    vops.GenRandomVector(v); //Generar vector aleatorio

    vector<int> copia = v;


    #if defined _WIN32 || defined _WIN64
        system("cls");
        system("pause");
    #elif defined __linux__ || defined __unix__
        system("clear");
    #endif // defined

    for (unsigned int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
    {
        cout <<endl<<endl<< "vector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;

        vops.ShowVector(v); //Mostrar vector por pantalla

        ordenarArrayDeInt(v, metodo);
        cout<<endl<<endl<<"Array ordenado con metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;

        vops.ShowVector(v);  //Mostrar vector por pantalla

        cout<<endl;

        v = copia;
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
        tallaFin = 10000,
        incTalla = 500;

    vector_ops vops;
    string nombre_fichero = nombreAlgoritmo[metodo] + ".dat";
    ofstream fichero(nombre_fichero.c_str());

    double segundos = 0, tiempo;
    AlgoritmosOrdenacion ordena;

    cout<<"Ordenacion por " << nombreAlgoritmo[metodo] << ". Tiempos de ejecucion promedio\n";
    cout<<"\nTalla\t\t"<<"Tiempo\n\n";

    for(int i = tallaIni; i < tallaFin; i += incTalla)
    {
        std::vector<int> v(i);

        int contador = 0;
        segundos = 0;

        while(contador < NUMREPETICIONES)
        {
            vops.GenRandomVector(v);
            segundos += ordenarArrayDeInt(v, metodo);
            contador++;
        }
        tiempo = segundos / NUMREPETICIONES;
        cout << i << "\t\t" << tiempo << endl;
        fichero << i << "\t\t" << tiempo << endl;
    }

    char opcion;
    cout<<"\n\nGrabar datos en ficheros ? (s/n): ";
    cin>>opcion;

    if(opcion == 's')
    {
        cout<<"\nDatos guardados en el fichero "<<metodo<<endl
            <<"\nGenerar grafica de resultados? (s/n): ";
        cin>>opcion;

        if(opcion == 's') generar_grafica(nombreAlgoritmo[metodo]);
    }
}

/*
 * Compara dos metodos de ordenacion.
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo1: Primer metodo de ordenacion a comparar
 * param metodo2: Segundo metodo de ordenacion a comparar
 */
void TestOrdenacion::comparar(int metodo1, int metodo2)
{
    int tallaIni = 500,
        tallaFin = 10000,
        incTalla = 500;

    double segundos1 = 0, segundos2 = 0, tiempo1, tiempo2;
    AlgoritmosOrdenacion ordena;
    string met1, met2;
    met1 = nombreAlgoritmo[metodo1];
    met2 = nombreAlgoritmo[metodo2];
<<<<<<< HEAD:src/TestOrdenacion.cpp

=======
>>>>>>> 98ef0e55704a2666b20fc497475a2f10a7098cf2:src/TestOrdenacion.cpp
    char opcion;

    cout<< "Talla\t\t" << met1 << "\t\t" << met2 << endl << endl;
    met1 += ".dat";
    met2 += ".dat";
    ofstream fichero1(met1.c_str()), fichero2(met2.c_str());

    for(int i = tallaIni; i < tallaFin; i += incTalla)
    {
        vector<int> v(i);
        vector<int> copia = v;
        vector_ops vops;

        segundos1 = 0;
        int contador = 0;

        while(contador < NUMREPETICIONES)
        {
            vops.GenRandomVector(v);
            segundos1 += ordenarArrayDeInt(v, metodo1);
            segundos2 += ordenarArrayDeInt(copia, metodo2);
            contador++;
        }

        tiempo1 = segundos1 / NUMREPETICIONES;
        tiempo2 = segundos2 / NUMREPETICIONES;

        cout << i << "\t\t" << tiempo1 << "\t\t" << tiempo2 << endl;

        fichero1 << i << "\t\t" << tiempo1 << endl;
        fichero2 << i << "\t\t" << tiempo2 << endl;
<<<<<<< HEAD:src/TestOrdenacion.cpp
=======

>>>>>>> 98ef0e55704a2666b20fc497475a2f10a7098cf2:src/TestOrdenacion.cpp
    }//fin for

    cout<<"\n\nGrabar datos en ficheros ? (s/n): ";
    cin>>opcion;

    if(opcion == 's')
    {
        cout<<"\nDatos guardados en los ficheros "<<met1<<" y "<<met2<<endl
            <<"\nGenerar grafica de resultados? (s/n): ";
        cin>>opcion;

        if(opcion == 's') generar_grafica(met1, met2);
    }

}

void TestOrdenacion::generar_grafica(string metodo)
{
    string nom = "CmdMedio.plt";

    metodo += ".dat";

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

    if(metodo=="Shell.dat")
    {
        fout << "InsDir(x) = a + b*x*log(x)*log(x)" << endl;
        fout << "fit InsDir(x) \"" + metodo + "\" using 1:2 via a,b" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, InsDir(x)" << endl;
    }

    else if (metodo == "MergeSort.dat" || metodo == "Heapsort.dat" || metodo == "QuickSort.dat")
    {
        fout << "quick(x) = a*x*log(x)" << endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << endl;
    }

    else if (metodo == "Burbuja.dat" || metodo == "Insercion.dat" || metodo == "Seleccion.dat")
    {
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

void TestOrdenacion::generar_grafica(string fichero1, string fichero2)
{
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


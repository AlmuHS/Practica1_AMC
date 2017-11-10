#include "TestBusqueda.h"
#define NUMREPETICIONES 100
#include "Mtime.h"
#include <iostream>

using namespace std;
using namespace std::chrono;

TestBusqueda::TestBusqueda(void)
{
    nombreAlgoritmo.push_back("Binaria");
    nombreAlgoritmo.push_back("Secuencial");
    nombreAlgoritmo.push_back("Hash Cerrada");
    nombreAlgoritmo.push_back("Hash Abierta");
}


TestBusqueda::~TestBusqueda(void)
{
}

#if defined _WIN32 || defined _WIN64

double TestBusqueda::Buscar(vector<int> v, int metodo, int key)
{
    AlgoritmosBusqueda test;
    double segundos = 0;
    AlgoritmosOrdenacion ordenar;
    HashSearch testhash;

    Mtime counter;
    LARGE_INTEGER t_ini, t_fin;

    switch(metodo)
    {
    case BINARIA:
        ordenar.OrdenaHeapSort(v);
        QueryPerformanceCounter(&t_ini);
        test.busquedaBinaria(v, key);
        QueryPerformanceCounter(&t_fin);
        break;

    case SECUENCIAL:
        QueryPerformanceCounter(&t_ini);
        test.busquedaSecuencial(v, key);
        QueryPerformanceCounter(&t_fin);
        break;

    case HASHCLOSED:
        testhash.add_element_closed(v);
        QueryPerformanceCounter(&t_ini);
        testhash.search_element_closed(key);
        QueryPerformanceCounter(&t_fin);
        break;

    case HASHOPENED:
        testhash.add_element_opened(v);
        QueryPerformanceCounter(&t_ini);
        testhash.search_element_opened(key);
        QueryPerformanceCounter(&t_fin);
        break;

    }
    segundos=counter.performancecounter_diff(&t_fin, &t_ini)*1000000;

    return segundos;
}

#elif defined __linux__ || defined __unix__


double TestBusqueda::Buscar(vector<int> v, int metodo, int key)
{
    AlgoritmosBusqueda test;
    double segundos = 0;
    AlgoritmosOrdenacion ordenar;
    HashSearch testhash;

    duration<double> interval;
    high_resolution_clock::time_point t_ini, t_fin;

    switch(metodo)
    {
    case BINARIA:
        ordenar.OrdenaHeapSort(v);
        t_ini = high_resolution_clock::now();
        test.busquedaBinaria(v, key);
        t_fin = high_resolution_clock::now();
        break;

    case SECUENCIAL:
        t_ini = high_resolution_clock::now();
        test.busquedaSecuencial(v, key);
        t_fin = high_resolution_clock::now();
        break;

    case HASHCLOSED:
        testhash.add_element_closed(v);
        t_ini = high_resolution_clock::now();
        testhash.search_element_closed(key);
        t_fin = high_resolution_clock::now();
        break;

    case HASHOPENED:
        testhash.add_element_opened(v);
        t_ini = high_resolution_clock::now();
        testhash.search_element_opened(key);
        t_fin = high_resolution_clock::now();
        break;
    }

    interval = duration_cast<duration<double>>(t_fin - t_ini) * 1000;
    segundos = interval.count()*1000000;



    return segundos;
}

#endif

void TestBusqueda::comprobarMetodosBusqueda()
{
    int talla, pos;
    AlgoritmosBusqueda test;
    AlgoritmosOrdenacion ordena;
    HashSearch testhash;
    vector_ops vops;

    std::cout<<endl<<endl<<"Introduce la talla: ";
    std::cin>>talla;

    vector<int> v(talla);
    vops.GenRandomVector(v);

    for (unsigned int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
    {
        int elem = v[talla-1];

        cout <<endl<<endl<< "vector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
        vops.ShowVector(v); //Mostrar por pantalla

        vector<int> copia = v;
        switch(metodo)
        {

        case BINARIA:
            ordena.OrdenaHeapSort(copia);

            cout<<"\nvector ordenado: "<<endl<<endl;
            vops.ShowVector(copia);

            pos = test.busquedaBinaria(copia, elem);
            break;

        case SECUENCIAL:
            pos = test.busquedaSecuencial(v, elem);
            break;

        case HASHCLOSED:
            testhash.add_element_closed(v);
            testhash.search_element_closed(elem);
            break;

        case HASHOPENED:
            testhash.add_element_opened(v);
            testhash.search_element_opened(elem);
            break;
        }
        cout<<endl<<endl<<"Busqueda con metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
        cout<<"\nElemento a buscar: "<<elem<<endl;
        cout<<"\nElemento encontrado en posicion "<<pos;
        cout<<endl;
    }
}


void TestBusqueda::comparar(int metodo1 = 0, int metodo2 = 1)
{
    int tallaIni = 500,
        tallaFin = 50000,
        incTalla = 500;
    char opcion;
    double segundos1 = 0, segundos2 = 0, tiempo1, tiempo2;
    string met1, met2;

    met1 = nombreAlgoritmo[metodo1];
    met2 = nombreAlgoritmo[metodo2];

    cout<<"Talla\t\t"<<met1<<"\t\t"<<met2<<endl<<endl;
    met1+=".dat";
    met2+=".dat";
    ofstream fichero1(met1.c_str()), fichero2(met2.c_str());
    vector_ops vops;

    for(int i = tallaIni; i <= tallaFin; i += incTalla)
    {
        vector<int> v(i);
        segundos1 = 0;
        segundos2 = 0;
        int contador = 0;

        while(contador < NUMREPETICIONES)
        {
            vops.GenRandomVector(v);
            segundos1 += Buscar(v, metodo1, v[i/2]);
            segundos2 += Buscar(v, metodo2, v[i/2]);
            contador++;
        }

        tiempo1 = segundos1 / NUMREPETICIONES;
        tiempo2 = segundos2 / NUMREPETICIONES;

        cout<<i<<"\t\t"<<tiempo1<<"\t\t"<<tiempo2<<endl;

        fichero1<<i<<"\t\t"<<tiempo1<<endl;
        fichero2<<i<<"\t\t"<<tiempo2<<endl;
    }//fin for

    cout<<"\n\nGrabar los datos en ficheros? (s/n): ";
    cin>>opcion;
    if(opcion == 's')
    {
        cout<<"\n\nDatos grabados en los ficheros "<<met1<<" y  "<<met2
            <<"\n\nGenerar grafica de resultados? (s/n): ";
        cin>>opcion;
        if(opcion == 's') generar_grafica(met1, met2);
    }
}

void TestBusqueda::casoMedio(int metodo){
    int tallaIni = 500,
        tallaFin = 50000,
        incTalla = 500;
    char opcion;
    double segundos = 0, tiempo;
    string nombre_fichero = nombreAlgoritmo[metodo] + ".dat";
    ofstream fichero(nombre_fichero.c_str());
    vector_ops vops;

	cout<<"Talla\t\t"<<"Tiempo\n\n";
	for(int i = tallaIni; i < tallaFin; i += incTalla){
		vector<int> v(i);
		int contador = 0;
		segundos = 0;

		while(contador < NUMREPETICIONES){
            vops.GenRandomVector(v);

			segundos += Buscar(v, metodo, v[i/4]);
			contador++;
		}
		tiempo = segundos / NUMREPETICIONES;

		cout<<i<<"\t\t"<<tiempo<<endl;
		fichero<<i<<"\t\t"<<tiempo<<endl;
	}//fin for

	cout<<"\n\nGrabar los datos en el fichero "<<nombre_fichero<<" ? (s/n): ";
	cin>>opcion;

	if(opcion == 's'){
        cout<<"\n\nDatos grabados en el fichero "<<nombre_fichero
            <<"\n\nGenerar grafica de resultados? (s/n): ";
        cin>>opcion;
        if(opcion == 's') generar_grafica(nombre_fichero);
	}
}


void TestBusqueda::generar_grafica(string metodo)
{
    string nom = "CmdMedio.plt";

    ofstream fout((char*)nom.c_str());

    fout << "set title \" Busqueda " << metodo << "\"" << endl;
    fout << "set key top left vertical inside" << endl;
    fout << "set grid" << endl;
    fout << "set xlabel \"Talla (n)\"" << endl;
    fout << "set ylabel \"Tiempo (ms)\"" << endl;
    fout << "plot \"" << metodo << "\" using 1:2 with lines" << endl;

    if(metodo=="Secuencial.dat")
    {
        fout << "InsDir(x) = a + b*x" << endl;
        fout << "fit InsDir(x) \"" + metodo + "\" using 1:2 via a,b" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, InsDir(x)" << endl;
    }
    else if (metodo == "Binaria.dat")
    {
        fout << "quick(x) = a*x*log(x)+b*x+c" << endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a, b, c" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << endl;
    }
    else if(metodo == "Hash Cerrada.dat" || metodo == "Hash Abierta.dat")
    {
        fout << "quick(x) = a + b + c" << endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a,b,c" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << endl;
    }


    fout << "set terminal png" << endl;
    fout << "set output \"" << metodo << ".png\"" << endl;
    fout << "replot" << endl;
    fout << "pause 10 \"Pulse Enter para continuar...\"" << endl;

    fout.close();

    system("gnuplot CmdMedio.plt");
}

void TestBusqueda::generar_grafica(string fichero1, string fichero2)
{
    ofstream graf("CmdCMP.plt");

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

    system("gnuplot CmdCMP.plt");
}

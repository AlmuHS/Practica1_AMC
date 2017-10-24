#include "TestBusqueda.h"
#define NUMREPETICIONES 100
#include "Mtime.h"

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

double TestBusqueda::Buscar(int v[], int size, int metodo, int key){
	AlgoritmosBusqueda test;
	double segundos = 0;
    AlgoritmosOrdenacion ordenar;
    HashSearch testhash;

    Mtime counter;
    LARGE_INTEGER t_ini, t_fin;

    switch(metodo){
        case BINARIA:
            ordenar.OrdenaHeapSort(v, size);
            QueryPerformanceCounter(&t_ini);
            test.busquedaBinaria(v, size, key);
            QueryPerformanceCounter(&t_fin);
        break;

        case SECUENCIAL:
            QueryPerformanceCounter(&t_ini);
            test.busquedaSecuencial(v, size, key);
            QueryPerformanceCounter(&t_fin);
        break;

        case HASHCLOSED:
            testhash.add_element_closed(v, size);
            QueryPerformanceCounter(&t_ini);
            testhash.search_element_closed(key);
            QueryPerformanceCounter(&t_fin);
        break;

        case HASHOPENED:
            testhash.add_element_opened(v, size);
            QueryPerformanceCounter(&t_ini);
            testhash.search_element_opened(key);
            QueryPerformanceCounter(&t_fin);
        break;

    }
    segundos=counter.performancecounter_diff(&t_fin, &t_ini)*1000000;

	return segundos;
}

#elif defined __linux__ || defined __unix__


double TestBusqueda::Buscar(int v[], int size, int metodo, int key){
	AlgoritmosBusqueda test;
	double segundos = 0;
    AlgoritmosOrdenacion ordenar;
    HashSearch testhash;

    duration<double> interval;
    high_resolution_clock::time_point t_ini, t_fin;

    switch(metodo){
        case BINARIA:
            ordenar.OrdenaHeapSort(v, size);
            t_ini = high_resolution_clock::now();
            test.busquedaBinaria(v, size, key);
            t_fin = high_resolution_clock::now();
        break;

        case SECUENCIAL:
            t_ini = high_resolution_clock::now();
            test.busquedaSecuencial(v, size, key);
            t_fin = high_resolution_clock::now();
        break;

        case HASHCLOSED:
            testhash.add_element_closed(v, size);
            t_ini = high_resolution_clock::now();
            testhash.search_element_closed(key);
            t_fin = high_resolution_clock::now();
        break;

        case HASHOPENED:
            testhash.add_element_opened(v, size);
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

void TestBusqueda::comprobarMetodosBusqueda(){
    int talla, pos;
    AlgoritmosBusqueda test;
    AlgoritmosOrdenacion ordena;
    HashSearch testhash;
	cout<<endl<<endl<<"Introduce la talla: ";
	cin>>talla;
	ConjuntoInt *v = new ConjuntoInt(talla);
    v->GeneraVector();

	for (unsigned int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++){
        int elem = v -> get_posicion(talla-1);
        const int tam = talla;
        int copia[tam];

        for(int i=0; i<tam; i++)
            copia[i] = v->get_datos()[i];

		cout <<endl<<endl<< "vector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();

		switch(metodo){
            case BINARIA:
                ordena.OrdenaHeapSort(copia, talla);
                cout<<"\nvector ordenado: "<<endl<<endl;

                for(int j = 0; j < talla; j++)
                    cout<<copia[j]<<" ";

                cout<<endl;
                pos = test.busquedaBinaria(copia, talla, elem);
            break;

            case SECUENCIAL:
                pos = test.busquedaSecuencial(v->get_datos(), talla, elem);
            break;

            case HASHCLOSED:
                testhash.add_element_closed(v->get_datos(), talla);
                testhash.search_element_closed(elem);
            break;

            case HASHOPENED:
                testhash.add_element_opened(v->get_datos(), talla);
                testhash.search_element_opened(elem);
            break;
        }
        cout<<endl<<endl<<"Busqueda con metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
        cout<<"\nElemento a buscar: "<<elem<<endl;
        cout<<"\nElemento encontrado en posicion "<<pos;
		cout<<endl;
		v->vaciar();
    }
}


void TestBusqueda::comparar(int metodo1 = 0, int metodo2 = 1){
    int tallaIni = 500,
        tallaFin = 100000,
        incTalla = 500;
    char opcion;
	double segundos1 = 0, segundos2 = 0, tiempo1, tiempo2;
	string met1, met2;
	met1=nombreAlgoritmo[metodo1];
	met2=nombreAlgoritmo[metodo2];
    vector<double> tiempos1, tiempos2;

	cout<<"Talla\t\t"<<met1<<"\t\t"<<met2<<endl<<endl;
	met1+=".dat";
	met2+=".dat";
	ofstream fichero1(met1.c_str()), fichero2(met2.c_str());

    for(int i = tallaIni; i <= tallaFin; i += incTalla){
		ConjuntoInt v(i);
		int *vector=v.get_datos();
		segundos1 = 0;
		segundos2 = 0;
		int contador = 0;

		while(contador < NUMREPETICIONES){
            v.GeneraVector();
			segundos1 += Buscar(vector, i, metodo1, v.get_posicion(i/2));
			segundos2 += Buscar(vector, i, metodo2, v.get_posicion(i/2));
			contador++;
		}

		tiempo1 = segundos1 / NUMREPETICIONES;
		tiempo2 = segundos2 / NUMREPETICIONES;

		cout<<i<<"\t\t"<<tiempo1<<"\t\t"<<tiempo2<<endl;

		tiempos1.push_back(tiempo1);
		tiempos2.push_back(tiempo2);
	}//fin for

	cout<<"\n\nGrabar los datos en ficheros? (s/n): ";
	cin>>opcion;
	if(opcion == 's'){
        for(unsigned int j = 0; j < tiempos1.size(); j++){
            fichero1<<500*j+500<<"\t\t"<<tiempos1[j]<<endl;
            fichero2<<500*j+500<<"\t\t"<<tiempos2[j]<<endl;
        }
        cout<<"\n\nDatos grabados en los ficheros "<<met1<<" y  "<<met2
            <<"\n\nGenerar grafica de resultados? (s/n): ";
        cin>>opcion;
        if(opcion == 's') generar_grafica(met1, met2);
	}
}

void TestBusqueda::evaluar(string caso, int metodo){
    int tallaIni, tallaFin, incTalla;
    char opcion;
    double segundos = 0, tiempo;

    vector<double> tiempos;
    string nombre_fichero = nombreAlgoritmo[metodo] + caso +".dat";
    ofstream fichero(nombre_fichero.c_str());

    if(caso == "Mejor"){
        tallaIni = 500;
        tallaFin = 100000;
        incTalla = 500;
    }
    else if(caso == "Medio" || caso == "Peor"){
        tallaIni = 100;
        tallaFin = 1000;
        incTalla = 100;
    }


	cout<<"Talla\t\t"<<"Tiempo\n\n";
	for(int i = tallaIni; i < tallaFin; i += incTalla){
        int pos;
        ConjuntoInt v(i);
		int contador = 0;
		segundos = 0;

        if(caso == "Medio") pos = i / 4;
        else if(caso == "Mejor"){

            if(metodo == BINARIA) pos = i / 2;
            else if(metodo == SECUENCIAL) pos = 0;
        }
        else if(caso == "Peor") pos = i - 1;

		while(contador < NUMREPETICIONES){
            v.GeneraVector();
			segundos += Buscar(v.get_datos(), i, metodo, v.get_posicion(pos));
			contador++;
		}

		tiempo = segundos / NUMREPETICIONES;
		cout<<i<<"\t\t"<<tiempo<<endl;
		tiempos.push_back(tiempo);
    }

    cout<<"\n\nGrabar los datos en el fichero "<<nombre_fichero<<" ? (s/n): ";
	cin>>opcion;

	if(opcion=='s'){
        for(unsigned int j = 0; j < tiempos.size(); j++){
            fichero<<incTalla * j + incTalla<<"\t\t"<< tiempos[j]<<endl;
        }
        cout<<"\n\nDatos grabados en el fichero "<<nombre_fichero
            <<"\n\nGenerar grafica de resultados? (s/n): ";
        cin>>opcion;
        if(opcion=='s') generar_grafica(nombre_fichero);

        #ifdef __linux__
            system("clear");
        #elif defined _WIN32 || defined _WIN64
            system("cls");
        #endif
	}

}

void TestBusqueda::generar_grafica(string metodo){
    string nom = "CmdMedio.plt";

    ofstream fout((char*)nom.c_str());

    #ifdef __linux__
        fout<<"#!/usr/bin/gnuplot"<<endl;
    #endif

    fout << "set title \" Busqueda " << metodo << "\"" << endl;
    fout << "set key top left vertical inside" << endl;
    fout << "set grid" << endl;
    fout << "set xlabel \"Talla (n)\"" << endl;
    fout << "set ylabel \"Tiempo (ms)\"" << endl;
    fout << "plot \"" << metodo << "\" using 1:2 with lines" << endl;
    if(metodo=="Secuencial.dat"){
        fout << "InsDir(x) = a + b*x" << endl;
        fout << "fit InsDir(x) \"" + metodo + "\" using 1:2 via a,b" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, InsDir(x)" << endl;
    }
    else if (metodo == "Binaria.dat"){
        fout << "quick(x) = a*x*log(x)+b*x+c" << endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a, b, c" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << endl;
    }
    else if(metodo == "Hash Cerrada.dat" || metodo == "Hash Abierta.dat"){
        fout << "quick(x) = a + b + c" << endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a,b,c" << endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << endl;
    }


    fout << "set terminal png" << endl;
    fout << "set output \"" << metodo << ".png\"" << endl;
    fout << "replot" << endl;
    fout << "pause 10 \"Pulse Enter para continuar...\"" << endl;

    fout.close();
    #ifdef __linux__
        system("chmod +x CmdMedio.plt");
        system("./CmdMedio.plt");
    #elif defined _WIN32 || defined _WIN64
        system("CmdMedio.plt");
    #endif
}

void TestBusqueda::generar_grafica(string fichero1, string fichero2){
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

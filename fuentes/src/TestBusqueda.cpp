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


#include "TestBusqueda.h"
#define NUMREPETICIONES 300
#include "Mtime.h"
#include <iostream>


TestBusqueda::TestBusqueda(void)
{
    nombreAlgoritmo.push_back("Binaria");
    nombreAlgoritmo.push_back("Secuencial");
    nombreAlgoritmo.push_back("Hash Cerrada");
    nombreAlgoritmo.push_back("Hash Abierta");
    nombreAlgoritmo.push_back("Interpolacion");
}


#if defined _WIN32 || defined _WIN64

double TestBusqueda::Buscar(std::vector<int> &v, int metodo, int key)
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
        ordenar.OrdenaShell(v);
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

    case INTERPOLACION:
		ordenar.OrdenaShell(v);
		QueryPerformanceCounter(&t_ini);
		test.busquedaInterpolacion(v, key);
		QueryPerformanceCounter(&t_fin);
		break;

    }
    segundos = counter.performancecounter_diff(&t_fin, &t_ini)*1000000;

    return segundos;
}

#elif defined __linux__ || defined __unix__


double TestBusqueda::Buscar(std::vector<int> &v, int metodo, int key)
{
    AlgoritmosBusqueda test;
    double segundos = 0;
    AlgoritmosOrdenacion ordenar;
    HashSearch testhash;

    std::chrono::duration<double> interval;
    std::chrono::high_resolution_clock::time_point t_ini, t_fin;

    switch(metodo)
    {
    case BINARIA:
        ordenar.OrdenaShell(v);
        t_ini = std::chrono::high_resolution_clock::now();
        test.busquedaBinaria(v, key);
        t_fin = std::chrono::high_resolution_clock::now();
        break;

    case SECUENCIAL:
        t_ini = std::chrono::high_resolution_clock::now();
        test.busquedaSecuencial(v, key);
        t_fin = std::chrono::high_resolution_clock::now();
        break;

    case HASHCLOSED:
        testhash.add_element_closed(v);
        t_ini = std::chrono::high_resolution_clock::now();
        testhash.search_element_closed(key);
        t_fin = std::chrono::high_resolution_clock::now();
        break;

    case HASHOPENED:
        testhash.add_element_opened(v);
        t_ini = std::chrono::high_resolution_clock::now();
        testhash.search_element_opened(key);
        t_fin = std::chrono::high_resolution_clock::now();
        break;

    case INTERPOLACION:
		ordenar.OrdenaShell(v);
		t_ini = std::chrono::high_resolution_clock::now();
		test.busquedaInterpolacion(v, key);
		t_fin = std::chrono::high_resolution_clock::now();
		break;
    }

    interval = std::chrono::duration_cast<std::chrono::duration<double>>(t_fin - t_ini) * 1000;
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

    std::cout<<"\n\nIntroduce la talla: ";
    std::cin>>talla;

    std::vector<int> v(talla);
    vops.GenRandomVector(v);

    for (unsigned int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
    {
        int elem = v[talla-1];

        std::cout <<"\n\nvector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":\n\n";
        vops.ShowVector(v); //Mostrar por pantalla

        std::vector<int> copia = v;
        switch(metodo)
        {

        case BINARIA:
            ordena.OrdenaShell(copia);

        std::cout<<"\nvector ordenado: \n\n";
            vops.ShowVector(copia);

            pos = test.busquedaBinaria(copia, elem);
            break;

        case SECUENCIAL:
            pos = test.busquedaSecuencial(v, elem);
            break;

        case HASHCLOSED:
            testhash.add_element_closed(v);

           std::cout<<std::endl<<std::endl<<"Tabla Hash Cerrada generada: \n\n";
            testhash.show_closed_table();
            pos = testhash.search_element_closed(elem);
            break;

        case HASHOPENED:
            testhash.add_element_opened(v);

           std::cout<<std::endl<<std::endl<<"Tabla Hash Abierta generada: \n\n";
            testhash.show_opened_table();
            pos = testhash.search_element_opened(elem);
            break;

        case INTERPOLACION:
			ordena.OrdenaHeapSort(copia);
			std::cout << "\nvector ordenado: " << std::endl << std::endl;
			vops.ShowVector(copia);

			pos = test.busquedaInterpolacion(copia, elem);
        }
       std::cout<<std::endl<<std::endl<<"Busqueda con metodo "<<nombreAlgoritmo[metodo]<< ":"<<std::endl<<std::endl;
       std::cout<<"\nElemento a buscar: "<<elem<<std::endl;
       std::cout<<"\nElemento encontrado en posicion "<<pos;
       std::cout<<std::endl;
    }
}


void TestBusqueda::comparar(int metodo1 = 0, int metodo2 = 1)
{
    int tallaIni = 500,
        tallaFin = 15000,
        incTalla = 500;
    char opcion;
    double segundos1 = 0, segundos2 = 0, tiempo1, tiempo2;
    std::string met1, met2;

    met1 = nombreAlgoritmo[metodo1];
    met2 = nombreAlgoritmo[metodo2];

   std::cout<<"Talla\t\t"<<met1<<"\t\t"<<met2<<std::endl<<std::endl;
    met1+=".dat";
    met2+=".dat";
    std::ofstream fichero1(met1.c_str()), fichero2(met2.c_str());
    vector_ops vops;

    for(int i = tallaIni; i <= tallaFin; i += incTalla)
    {
        std::vector<int> v(i);
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

       std::cout<<i<<"\t\t"<<tiempo1<<"\t\t"<<tiempo2<<std::endl;

        fichero1<<i<<"\t\t"<<tiempo1<<std::endl;
        fichero2<<i<<"\t\t"<<tiempo2<<std::endl;
    }//fin for

    std::cout<<"\n\nGrabar los datos en ficheros? (s/n): ";
    std::cin>>opcion;
    if(opcion == 's')
    {
       std::cout<<"\n\nDatos grabados en los ficheros "<<met1<<" y  "<<met2
            <<"\n\nGenerar grafica de resultados? (s/n): ";
       std::cin>>opcion;
        if(opcion == 's') generar_grafica(met1, met2);
    }
}

void TestBusqueda::casoMedio(int metodo){
    int tallaIni = 500,
        tallaFin = 50000,
        incTalla = 500;
    char opcion;
    double segundos = 0, tiempo;
    std::string nombre_fichero = nombreAlgoritmo[metodo] + ".dat";
    std::ofstream fichero(nombre_fichero.c_str());
    vector_ops vops;

	std::cout<<"Talla\t\t"<<"Tiempo\n\n";
	for(int i = tallaIni; i < tallaFin; i += incTalla){
		std::vector<int> v(i);
		int contador = 0;
		segundos = 0;

		while(contador < NUMREPETICIONES){
            vops.GenRandomVector(v);

			segundos += Buscar(v, metodo, v[i/4]);
			contador++;
		}
		tiempo = segundos / NUMREPETICIONES;

		std::cout<<i<<"\t\t"<<tiempo<<std::endl;
		fichero<<i<<"\t\t"<<tiempo<<std::endl;
	}//fin for

	std::cout<<"\n\nGrabar los datos en el fichero "<<nombre_fichero<<" ? (s/n): ";
	std::cin>>opcion;

	if(opcion == 's'){
       std::cout<<"\n\nDatos grabados en el fichero "<<nombre_fichero
            <<"\n\nGenerar grafica de resultados? (s/n): ";
        std::cin>>opcion;
        if(opcion == 's') generar_grafica(nombre_fichero);
	}
}


void TestBusqueda::generar_grafica(std::string metodo)
{
    std::string nom = "CmdMedio.plt";

    std::ofstream fout((char*)nom.c_str());

    fout << "set title \" Busqueda " << metodo << "\"" << std::endl;
    fout << "set key top left vertical inside" << std::endl;
    fout << "set grid" << std::endl;
    fout << "set xlabel \"Talla (n)\"" << std::endl;
    fout << "set ylabel \"Tiempo (ms)\"" << std::endl;
    fout << "plot \"" << metodo << "\" using 1:2 with lines" << std::endl;

    if(metodo=="Secuencial.dat")
    {
        fout << "InsDir(x) = a + b*x" << std::endl;
        fout << "fit InsDir(x) \"" + metodo + "\" using 1:2 via a,b" << std::endl;
        fout << "plot \"" + metodo + "\" using 1:2, InsDir(x)" << std::endl;
    }
    else if (metodo == "Binaria.dat" || metodo == "Interpolacion.dat")
    {
        fout << "quick(x) = a*x*log(x)+b*x+c" << std::endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a, b, c" << std::endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << std::endl;
    }
    else if(metodo == "Hash Cerrada.dat" || metodo == "Hash Abierta.dat")
    {
        fout << "quick(x) = a + b + c" << std::endl;
        fout << "fit quick(x) \"" + metodo + "\" using 1:2 via a,b,c" << std::endl;
        fout << "plot \"" + metodo + "\" using 1:2, quick(x)" << std::endl;
    }


    fout << "set terminal png" << std::endl;
    fout << "set output \"" << metodo << ".png\"" << std::endl;
    fout << "replot" << std::endl;
    fout << "pause 10 \"Pulse Enter para continuar...\"" << std::endl;

    fout.close();

    #if defined __linux__ || defined __unix__
        system("gnuplot CmdMedio.plt");
    #elif defined _WIN32 || defined _WIN64
        system("CmdMedio.plt");
    #endif
}

void TestBusqueda::generar_grafica(std::string fichero1, std::string fichero2)
{
    std::ofstream graf("CmdCMP.plt");

    graf << "set title \""<<"Comparacion tiempos entre " << fichero1 <<" y "<< fichero2 << "\"" << "\n";
    graf << "set key top left vertical inside\n";
    graf << "set grid\n";
    graf << "set xlabel \"Talla (n)\"\n";
    graf << "set ylabel \"Tiempo (ms)\"\n";
    graf << "plot \"" << fichero1 << "\" using 1:2 with lines, \"" << fichero2 << "\" using 1:2 with lines" << std::endl;


    graf << "set terminal png" << std::endl;
    graf << "set output \"" << fichero1 << "-" <<fichero2 << ".png\"" << std::endl;
    graf << "replot" << std::endl;
    graf << "pause 10 \"Pulse Enter para continuar...\"" << std::endl;
    graf.close();

    #if defined __linux__ || defined __unix__
        system("gnuplot CmdCMP.plt");
    #elif defined _WIN32 || defined _WIN64
        system("CmdCMP.plt");
    #endif // defined

}

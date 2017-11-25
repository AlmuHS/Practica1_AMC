/*Copyright 2013 2016 2017 Almudena Garcia Jurado-Centurion

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


#include "Menu.h"

#if defined __unix__ || defined __linux__

void Menu::clear(){
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

#elif defined _WIN32 || defined _WIN64
#include <windows.h>

void Menu::clear(){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, &csbi);

    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

    SetConsoleCursorPosition(hStdOut, coord);
}

#endif


void Menu::menu_principal(){
    do{
        cout<<"**** MENU PRINCIPAL ****\n\n"
            <<"1.- MENU ORDENACION\n\n"
            <<"2.- MENU BUSQUEDA\n\n"
            <<"0.- Salir\n\n"
            <<"----------\n\n"
            <<"Elige opcion: ";
        cin>>opcion;

        clear();

        switch(opcion){
            case 0:
                exit(0);
            break;

            case 1:
                menu_ordenacion();
            break;

            case 2:
                menu_busquedas();
            break;
        }
    }while(opcion!=0);
}

void Menu::menu_ordenacion(){
    TestOrdenacion ordena;
    cout<<"*** MENU ORDENACION ***\n\n"
        <<"1.- Probar los metodos de ordenacion\n\n"
        <<"2.- Obtener el caso medio de un metodo de ordenacion\n\n"
        <<"3.- Comparar dos metodos\n\n"
        <<"0.- Volver al menu principal\n\n"
        <<"---------\n\n"
        <<"Elige opcion: ";
    cin>>opcion;

    clear();

    switch(opcion){

        case 1:
            ordena.comprobarMetodosOrdenacion();
        break;

        case 2:
            cout<<"*** Metodo a estudiar para el caso medio ***\n\n"
                <<"0: Burbuja\n\n"
                <<"1: Insercion\n\n"
                <<"2: Seleccion\n\n"
                <<"3: Shell\n\n"
                <<"4: HeapSort\n\n"
                <<"5: QuickSort\n\n"
                <<"6: MergeSort\n\n"
                <<"---------\n\n"
                <<"Elige opcion: ";
            cin>>opcion;
            ordena.casoMedio(opcion);
        break;

        case 3:
            cout<<"*** COMPARACION DE DOS METODOS DE ORDENACION ***\n\n"
                <<"Selecciona los dos metodos a comparar\n\n"
                <<"0. Burbuja\n\n"
                <<"1. Insercion\n\n"
                <<"2. Seleccion\n\n"
                <<"3: Shell\n\n"
                <<"4: HeapSort\n\n"
                <<"5: QuickSort\n\n"
                <<"6: MergeSort\n\n"
                <<"Elige metodo 1: ";
            cin>>opcion;
            cout<<"\nElige metodo 2: ";
            cin>>opcion2;

            clear();
            ordena.comparar(opcion, opcion2);
        break;

        case 0:
            menu_principal();
        break;
    }
}


void Menu::menu_busquedas(){
    TestBusqueda buscar;
    cout<<"**** MENU BUSQUEDA ****\n\n"
        <<"1.- Probar los metodos de busqueda\n\n"
        <<"2.- Obtener el caso medio de un metodo de busqueda\n\n"
        <<"3.- Comparar los metodos\n\n"
        <<"0.- Volver al menu principal\n\n"
        <<"---------\n\n"
        <<"Elige opcion: ";
    cin>>opcion;

    clear();


    switch(opcion){

        case 1:
            buscar.comprobarMetodosBusqueda();
        break;

        case 2:
            cout<<"*** Metodo a estudiar para el caso medio ***\n\n"
                <<"0: Busqueda Binaria\n\n"
                <<"1: Busqueda Secuencial\n\n"
                <<"2: Busqueda Hash Cerrada\n\n"
                <<"3: Busqueda Hash Abierta\n\n"
                <<"4. Busqueda por Interpolacion\n\n"
                <<"---------\n\n"
                <<"Elige opcion: ";
            cin>>opcion;

            clear();
            buscar.casoMedio(opcion);
        break;

        case 3:
            cout<<"*** COMPARACION DE DOS METODOS DE BUSQUEDA ***\n\n"
                <<"Selecciona los dos metodos a comparar\n\n"
                <<"0. Binaria\n\n"
                <<"1. Secuencial\n\n"
                <<"2: Busqueda Hash Cerrada\n\n"
                <<"3: Busqueda Hash Abierta\n\n"
                <<"4. Busqueda por Interpolacion\n\n"
                <<"Elige metodo 1: ";
            cin>>opcion;
            cout<<"\nElige metodo 2: ";
            cin>>opcion2;

            clear();
            buscar.comparar(opcion, opcion2);
        break;

        case 0:
            menu_principal();
        break;
    }
}

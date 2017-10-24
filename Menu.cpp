#include "Menu.h"

void Menu::menu_principal(){
    do{
        cout<<"**** MENU PRINCIPAL ****\n\n"
            <<"1.- MENU ORDENACION\n\n"
            <<"2.- MENU BUSQUEDA\n\n"
            <<"0.- Salir\n\n"
            <<"----------\n\n"
            <<"Elige opcion: ";
        cin>>opcion;
        #if defined _WIN32 || defined _WIN64
            system("cls");
        #elif defined __linux__
            system("clear");
        #endif // defined


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
    #if defined _WIN32 || defined _WIN64
        system("cls");
    #elif defined __linux__
        system("clear");
    #endif // defined
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

            #if defined _WIN32 || defined _WIN64
                system("cls");
            #elif defined __linux__
                 system("clear");
            #endif // defined
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
    #if defined _WIN32 || defined _WIN64
        system("cls");
    #elif defined __linux__
        system("clear");
    #endif // defined


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
                <<"---------\n\n"
                <<"Elige opcion: ";
            cin>>opcion;
            #if defined _WIN32 || defined _WIN64
                system("cls");
            #elif defined __linux__
                 system("clear");
            #endif // defined
            buscar.evaluar("Medio", opcion);
        break;

        case 3:
            cout<<"*** COMPARACION DE DOS METODOS DE BUSQUEDA ***\n\n"
                <<"Selecciona los dos metodos a comparar\n\n"
                <<"0. Binaria\n\n"
                <<"1. Secuencial\n\n"
                <<"2: Busqueda Hash Cerrada\n\n"
                <<"3: Busqueda Hash Abierta\n\n"
                <<"Elige metodo 1: ";
            cin>>opcion;
            cout<<"\nElige metodo 2: ";
            cin>>opcion2;

            #if defined _WIN32 || defined _WIN64
                system("cls");
            #elif defined __linux__
                 system("clear");
            #endif // defined
            buscar.comparar(opcion, opcion2);
        break;

        case 0:
            menu_principal();
        break;
    }
}

#ifndef MENU_H
#define MENU_H
#include "TestBusqueda.h"
#include "TestOrdenacion.h"

class Menu
{
    int opcion, opcion2;
    public:
        void clear();
        void menu_principal();
        void menu_busquedas();
        void menu_ordenacion();
};

#endif // MENU_H

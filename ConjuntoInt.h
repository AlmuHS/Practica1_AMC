#include <iostream>
#include <cstdlib>
#include <ctime>

 class ConjuntoInt{
    private:
        int tamano;
        int MAXIMO;
        int *datos;
    public:
        ConjuntoInt(int max=4);
        ~ConjuntoInt();
        void vaciar();
        void GeneraVector();
        void insertar(int n);
        int get_primero();
        void escribe();
		int get_posicion(int pos);
		int* get_datos();
		void ordena_inverso();
 };

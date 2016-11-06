#include "ConjuntoInt.h"

using namespace std;

ConjuntoInt::ConjuntoInt(int max){

    tamano=0;
    MAXIMO=max;
    datos=new int[MAXIMO];
}

ConjuntoInt::~ConjuntoInt(){
    delete[] datos;
}

void ConjuntoInt::vaciar(){
    tamano=0;
}

void ConjuntoInt::GeneraVector(){
    srand((unsigned)time(NULL));
    for(tamano=0; tamano<MAXIMO; tamano++)
        datos[tamano]=rand()%1000;
}

void ConjuntoInt::insertar(int n){
    if (tamano<MAXIMO) datos[tamano++]=n;
    else cerr<<"ERROR: el conjunto esta lleno"<<endl;
}

int ConjuntoInt::get_primero(){
    int primero=datos[0];
    return primero;
}


void ConjuntoInt::escribe(){
    for(int i=0; i<MAXIMO; i++)
        cout<<datos[i]<<(i<MAXIMO-1? ",": "\n");
}


int ConjuntoInt::get_posicion(int pos){
	return datos[pos];
}

int* ConjuntoInt::get_datos(){
	return datos;
}

void ConjuntoInt::ordena_inverso(){
    for (int i=0; i<MAXIMO-1; i++)
        for(int j=i+1; j<MAXIMO; j++)
            if(datos[j]>datos[i]){
                int tmp=datos[i];
                datos[i]=datos[j];
                datos[j]=tmp;
            }
}

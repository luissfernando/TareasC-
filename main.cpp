#include <iostream>
#include "matriz.h"
int main(){
    int nodos;
    std::cout<<"ingrese el tamaño de nodos del grafo : ";
    std::cin>>nodos;
    Matriz r1(nodos);
    r1.reservarEspac();
    r1.agregarAristas();
    r1.mostrarMatriz();
    r1.guardarArchivo();
    r1.mostrarGrafo();
    //r1.liberarEspac();
}

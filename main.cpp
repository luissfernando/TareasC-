#include <iostream>
#include "matriz.h"
int main(){
    Matriz r1(3);
    r1.reservarEspac();
    r1.agregarAristas();
    r1.mostrarMatriz();
    r1.guardarArchivo();
    r1.mostrarGrafo();
    //r1.liberarEspac();
}
//prueba para otra rama
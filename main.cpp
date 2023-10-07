#include <iostream>
#include "matriz.h"
using namespace std;
int main(){
    Matriz *r1 = nullptr;
    int nodos,opc;
    do{
        cout<<" \n\n\t ########## MENU: ##########\n";
        cout<<"1) ingresar grafo\n";
        cout<<"2) mostrar matriz\n";
        cout<<"3) mostrar grafo\n";
        cout<<"4) salir\n";
        cout<<"opcion:  ";
        cin>>opc;
        switch (opc){
            case 1:
                cout<<"ingrese el tamaño de nodos del grafo : ";
                cin>>nodos;
                r1 = new Matriz(nodos);
                r1->agregarAristas();
                break;
            case 2:
                if(r1){
                    r1->mostrarMatriz();
                }
                else{
                    cout<<"Nada que mostrar grafo vacio\n";
                }
                break;
            case 3:
                if(r1){
                    r1->guardarArchivo();
                    r1->mostrarGrafo();
                }
                else{
                    cout<<"Nada que mostrar grafo vacio\n";
                }
                break;
            case 4:
                break;
            default:
                cout<<" opcion no valida\n ";
                break;
        }
    }while(opc != 4);
    
    //r1.reservarEspac();
    //r1.liberarEspac();
}

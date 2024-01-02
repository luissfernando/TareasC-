#include <iostream>
#include <fstream>
#include "nodo.h"
using namespace std;
class Nodo{
    char *letras;
    int *cantidades;
    Inicio arbol = NULL;
public:
    Nodo(){
        this->cantidades = new int[6];
        this->letras = new char [6];
        for(int i=0;i<6;i++){
            cantidades[i] = 0;
        }
        letras[0] = 'a';
        letras[1] = 'b';
        letras[2] = 'c';
        letras[3] = 'd';
        letras[4] = 'e';
        letras[5] = 'f';
    }
    void crearFich(char *letras,int *cantidades){
        ofstream fich ("nodo.txt");
        if(!fich){
            cout<<"Error al crear fichero";
            exit(EXIT_FAILURE);
        }
        for (int i=0 ; *(letras+i) != '\0';i++){
            fich<< *(letras+i) << "->" << *(cantidades+i)<<endl;
        }
    }
    void abrirFich(){
	char c;
	ifstream f;
	f.open("nodo.txt");
	f >> c;
	while(!f.eof()){
		if (c=='a')	cantidades[0]=cantidades[0]+1;
		else if (c=='b') cantidades[1]=cantidades[1]+1;
		else if (c=='c') cantidades[2]=cantidades[2]+1;
		else if (c=='d') cantidades[3]=cantidades[3]+1;
		else if (c=='e') cantidades[4]=cantidades[4]+1;
		else if (c=='f') cantidades[5]=cantidades[5]+1;
		f >> c;
	}
	f.close();
}
    void crearArbol(){
        for(int i=0;i<6;i++)
            insertar(arbol,letras[i],cantidades[i]);
    }
    //metodo de burbuja
    void ordenar(){
        for (int i=0 ; *(letras+i) != '\0';i++){
            for(int j=0; j<6;j++){
                if(*(cantidades+i)<*(cantidades+j)){
                    int temp = *(cantidades+i);
					char tempLetra = *(letras+i);
                    *(cantidades+i) = *(cantidades+j);
                    *(cantidades+j) = temp;
					*(letras+i) = *(letras+j);
					*(letras+j) = tempLetra;
				}
            }
        }
    }
	void mostrarDatos(){
        for(int i=0;i<6;i++)
            cout<<*(letras+i) <<" -> "<<*(cantidades+i)<<endl;
    }
    void mostrarFich(){
        ifstream fich;
        string linea;
        fich.open("nodo.txt");
        while (!fich.eof()){
            getline(fich,linea);
            if (! fich.eof()) 
            cout << linea << endl;
        }
        fich.close();}
void ordenarArbol(){
    if (arbol == nullptr || arbol->sig == nullptr) {
        cout << "Arbol vacio\n";
        return;
    } else {
        bool intercambio;
        Inicio temp;
        Inicio cabezaAnterior = nullptr;
        do {
            intercambio = false;
            Inicio anterior = nullptr;
            Inicio actual = arbol;
            while (actual->sig != nullptr) {
                if (actual->cantidad > actual->sig->cantidad) {
                    // Intercambio nodos
                    temp = actual->sig;
                    actual->sig = temp->sig;
                    temp->sig = actual;

                    if (anterior != nullptr) {
                        anterior->sig = temp;
                    } else {
                        arbol = temp;
                    }
                    anterior = temp;
                    intercambio = true;
                } else {
                    anterior = actual;
                    actual = actual->sig;
                }
            }
            // Actualizar cabeza de la lista si es necesario
            if (cabezaAnterior == nullptr) {
                cabezaAnterior = arbol;
            }
        } while (intercambio);
        // Actualizar la cabeza de la lista si fue modificada durante el ordenamiento
        arbol = cabezaAnterior;
    }
}
void creaNodoAlgoritHuffman(){
   // while(arbol != nullptr){
        int sum = arbol->cantidad + arbol->sig->cantidad;
        Inicio head = arbol->sig->sig;
        Inicio temp = crearNodo(' ',sum);
        temp->izq = arbol;
        temp->der = arbol->sig;
        temp->sig = head;
        arbol->sig->sig = nullptr;
        arbol->sig = nullptr;
        arbol = temp;
     //   ordenarArbol();
       // mostrarArbol();
    //}
}
void algoritHuffman(){
    while(arbol->sig != nullptr){
        creaNodoAlgoritHuffman();
        ordenarArbol();
        mostrarArbol();
    }
}
void mostrarArbol(){
    cout<<"    #### ARBOL: #####\n";
    mostrar(arbol);
    cout<<endl;
}
};
int main(){
    Nodo f1;
    f1.abrirFich();
    f1.ordenar();
    f1.mostrarDatos();
    f1.crearArbol();
    
    f1.algoritHuffman();
    
}

#include <iostream>
#include <fstream>
using namespace std;
struct nodo{
	char letra;
	int cantidad;
	nodo* sig;
	nodo* izq;
	nodo* der;
};
typedef nodo* Inicio;
Inicio crearNodo(char c,int value){
	Inicio nuevoNodo = new(nodo);
	nuevoNodo->letra = c;
	nuevoNodo->cantidad = value;
	nuevoNodo->izq = 0;
	nuevoNodo->der = 0;
	nuevoNodo->sig = 0;
	return nuevoNodo;
}
void insertar(Inicio &arbol, char c,int value){
	if(arbol==NULL)
		arbol = crearNodo(c,value);
	else {   
		Inicio temp = crearNodo(c,value);
		Inicio temp2 = arbol;
		while(temp2->sig!=NULL){ 
			temp2=temp2->sig;
		}
		temp2->sig=temp;
	}
}
void mostrar(Inicio arbol){
	if(arbol == NULL)
		cout<<"Arbol vacio\n";
	else{
		while(arbol->sig != NULL){
			cout<<"nodo : "<<arbol->letra<<" --> "<<arbol->cantidad<<endl;
			arbol = arbol->sig;
		}
		cout<<"nodo : "<<arbol->letra<<" --> "<<arbol->cantidad<<endl;
	}
}
// int main(){
// 	Inicio arbol = NULL;
// 	insertar(arbol, 'f',5);
// 	insertar(arbol, 'e',9);
// 	insertar(arbol, 'c',12);
// 	mostrar(arbol);
// }



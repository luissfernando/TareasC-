#include <iostream>
#include <fstream>
using namespace std;

struct nodo {
    char letra;
    nodo* izq;
    nodo* der;
};

typedef nodo* Inicio;

void agregarNodo(Inicio& raiz, char nuevaLetra) {
    if (raiz == nullptr) {
        // Árbol vacío, crea un nuevo nodo como raíz
        raiz = new nodo;
        raiz->letra = nuevaLetra;
        raiz->izq = nullptr;
        raiz->der = nullptr;
        cout << "Nodo '" << nuevaLetra << "' agregado como raiz." << endl;
    } else {
        // Árbol no vacío, agregar a la izquierda o derecha
        char decision;
        cout << "Agregar '" << nuevaLetra << "' a la izquierda (i) o derecha (d) de '" << raiz->letra << "': ";
        cin >> decision;

        if (decision == 'i') {
            agregarNodo(raiz->izq, nuevaLetra);
        } else if (decision == 'd') {
            agregarNodo(raiz->der, nuevaLetra);
        } else {
            cout << "Entrada no válida. Por favor, ingresa 'i' o 'd'." << endl;
        }
    }
}

void generarDot(Inicio& raiz, ofstream& archivoDot) {
    if (raiz != nullptr) {
        //archivoDot << raiz->letra << " [label=\"" << raiz->letra << "\",color=white];" << endl;
        if (raiz->izq != nullptr) {
            archivoDot << raiz->letra << " -> " << raiz->izq->letra << ";" << endl;
            generarDot(raiz->izq, archivoDot);
        }
        if (raiz->der != nullptr) {
            archivoDot << raiz->letra << " -> " << raiz->der->letra << ";" << endl;
            generarDot(raiz->der, archivoDot);
        }
    }
}

bool sonIsomorfos(Inicio raiz1, Inicio raiz2) {
    if (raiz1 == nullptr && raiz2 == nullptr) {
        return true; // Ambos árboles son vacíos, son isomorfos
    } else if (raiz1 == nullptr || raiz2 == nullptr) {
        return false; // Uno de los árboles es vacío y el otro no, no son isomorfos
    } else {
        // Compara recursivamente las subárboles, considerando la posibilidad de intercambiar izquierda y derecha
        return (sonIsomorfos(raiz1->izq, raiz2->izq) && sonIsomorfos(raiz1->der, raiz2->der)) ||
            	(sonIsomorfos(raiz1->izq, raiz2->der) && sonIsomorfos(raiz1->der, raiz2->izq));
    }
}
int main() {
    Inicio raiz1 = nullptr;
    Inicio raiz2 = nullptr;

    // Agregar nodos al primer árbol
    agregarNodo(raiz1, 'A');
    agregarNodo(raiz1, 'B');
    agregarNodo(raiz1, 'C');

    // Agregar nodos al segundo árbol (isomorfo al primero)
    agregarNodo(raiz2, 'X');
    agregarNodo(raiz2, 'Y');
    agregarNodo(raiz2, 'Z');

    // Determinar si los árboles son isomorfos
    if (sonIsomorfos(raiz1, raiz2)) {
        cout << "Los arboles son isomorfos." << endl;
    } else {
        cout << "Los arboles no son isomorfos." << endl;
    }
	ofstream arbol1;
	arbol1.open("arbol1.dot");
	arbol1<<"digraph Binario {"<<endl;
	generarDot(raiz1,arbol1);
	arbol1<<"}"<<endl;
	system("dot -Tpng arbol1.dot -o arbol1.png");
	system("nohup display arbol1.png &" );

	ofstream arbol2;
	arbol2.open("arbol2.dot");
	arbol2<<"digraph Binario {"<<endl;
	generarDot(raiz2,arbol2);
	arbol2<<"}"<<endl;
	system("dot -Tpng arbol2.dot -o arbol2.png");
	system("nohup display arbol2.png &" );

    return 0;
}
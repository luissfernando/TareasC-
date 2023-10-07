#include <iostream>
#include "matriz.h"
#include <fstream>
using namespace std;
Matriz::Matriz(){
    this->n = 0;
    this->nAristas = 0;
}
Matriz::Matriz(int n){
    this->n = n;
    this->nAristas = 0;
    reservarEspac();
}
void Matriz::reservarEspac(){
    M = new int* [n];
    for(int i=0;i<n;i++){
        *(M+i) = new int [n];   
    }
}
void Matriz::liberarEspac(){
    for(int i=0;i<n;i++){
        delete [] M;
    }
}
void Matriz::llenarCeros(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            M[i][j] = 0;
    }
}
void Matriz::mostrarMatriz(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << M[i][j]<<" ";
        cout<<endl;
    }
}
void Matriz::agregarAristas(){
    int aristas,ori,des;
	cout << "Ingresar numero de aristas:";
	cin >> aristas;
    if( aristas <= n*(n+1)/2){
        for(int i=0;i<aristas;i++){
            cout << "arista = " << (i+1) <<" Origen: ";
            cin >> ori;
            cout << "arista = " << (i+1) <<" Destino: ";
            cin >> des;
            M[ori-1][des-1]=1;
            M[des-1][ori-1]=1;
        }
    }
    else{
        cout<<"cantidad de aristas no valida\n";
    }
    nAristas = aristas;
}
void Matriz::eliminarAristas(){
    int aristas,ori,des;
	cout << "Ingresar numero de aristas:";
	cin >> aristas;
    if( aristas <= n*(n+1)/2){
        for(int i=0;i<aristas;i++){
            cout << "arista = " << (i+1) <<" Origen: ";
            cin >> ori;
            cout << "arista = " << (i+1) <<" Destino: ";
            cin >> des;
            M[ori-1][des-1]=0;
            M[des-1][ori-1]=0;
        }
    }
    else{
        cout<<"cantidad de aristas no valida\n";
    }
}
template <typename T>
bool Matriz::abrirFich(T& f){
    f.open("grafo.dot");
    if(f.is_open())
        return true;
    cout<<"Error al abrir el fichero\n";
    return false;
}
void Matriz::guardarArchivo(){
    ofstream f;
    if(abrirFich <ofstream>(f)){                                 
        f << " graph A{" << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>=j){
                    if(M[i][j] == 1){
                        f << i+1 << "--"<<j+1<<endl;
                    }
                }
            }
        }
        f<<"}"<<endl;
    }
    f.close();
}
void Matriz::mostrarGrafo(){
    system("dot -Tpng grafo.dot -o grafo.png");
    system("nohup display grafo.png &"); 
}

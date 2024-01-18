#include <iostream>
#include <vector>
using namespace std;

struct pos {
	int i;
	int j;
	int peso; // para agregar un peso en el algoritmo de kruskall
};
void ceros(int **Ma, int n){ 
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++)
			Ma[i][j]=0;
}

void mostrar(int **Ma, int n){ 
	for(int i=0; i<n;i++){	
		for(int j=0; j<n;j++)
			cout<<Ma[i][j]<<" ";
		cout<<endl;
	}
	cout << endl;
}
void aleatorio(int **Ma, int n){
	pos elem;
	vector<pos> v;
	for(int i=0;i<(n-1);i++){   
		for(int k=2+i;k<n;k++){
			elem.i=i;
			elem.j=k;
			v.push_back(elem);
		}
	}
	for(int i=0;i<v.size();i++){
		cout << "(" << v[i].i<<","<< v[i].j <<")" << endl;
	}
	
	int pos_i,pos_j,aristas,r,cant;
	cant = ((n*n)-n)/2 - (n-1);
	cout << "Numeros de aristas a ingresar (Max="<<cant << "): "; 
	cin >> aristas;
	
	for(int i=0;i<aristas;i++)
	{
		r=rand()%v.size();
		pos_i=v[r].i;
		pos_j=v[r].j;
		Ma[pos_i][pos_j]=1;
		Ma[pos_j][pos_i]=1;
		v.erase(v.begin()+r);
	}
	
}
void caminoBasico(int **Ma, int n){
	for(int i=0;i<(n-1);i++){
		Ma[i][i+1]=1;
		Ma[i+1][i]=1;
	}
}
void prim(int **Ma, int n) {
	int min=999; // para el min
    int verticPadre[n]; //almacena el vértice padre de cada vértice 
    int pesoAristPeque[n];    //almacena el peso de la arista más pequeña

    for (int i = 0; i < n; i++) {
        pesoAristPeque[i] = min;
        verticPadre[i] = -1;  
    }
    pesoAristPeque[0] = 0; // Comienza con el primer vértice.

    for (int cont = 0; cont < n - 1; cont++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (pesoAristPeque[i] != -1 && (u == -1 || pesoAristPeque[i] < pesoAristPeque[u]))
                u = i;
        }
        pesoAristPeque[u] = -1; // Marcar como ya vicitado

        for (int v = 0; v < n; v++) {
            if (Ma[u][v] && pesoAristPeque[v] != -1 && Ma[u][v] < pesoAristPeque[v]) {
                verticPadre[v] = u;
                pesoAristPeque[v] = Ma[u][v];
            }
        }
    }
	// mostrar aristas
    cout << "Aristas por Prim:" << endl;
    for (int i = 1; i < n; i++) {
        cout << verticPadre[i] << " - " << i << endl;
    }
}

void kruskal(int **Ma, int n) {
    // Construir un vector de aristas a partir de la matriz de adyacencia
    pos aristas[(n * (n - 1)) / 2];
    int index = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (Ma[i][j] != 0) {
                aristas[index].i = i;
                aristas[index].j = j;
                aristas[index].peso = Ma[i][j];
                ++index;
            }
        }
    }
    // Ordenar las aristas en form asendente segun el peso 
    for (int i = 0; i < index - 1; ++i) {
        for (int j = 0; j < index - i - 1; ++j) {
            if (aristas[j].peso > aristas[j + 1].peso) {
                // Intercambia aristas : swich
                pos temp = aristas[j];
                aristas[j] = aristas[j + 1];
                aristas[j + 1] = temp;
            }
        }
    }
    // Vector para almacenar los conjuntos de klos vértices
    int conjunto[n];
    // llena los vertices en cada conjunto
    for (int i = 0; i < n; ++i) {
        conjunto[i] = i;
    }
    // structura para almacenar las aristas del Árbol 
    pos arbolAristas[n - 1];
    int mstIndex = 0;

    // Algoritmo de  Kruskall
    for (int i = 0; i < index; ++i) {
        int conjuntoU = conjunto[aristas[i].i];
        int conjuntoV = conjunto[aristas[i].j];

        // Si los vértices no están en el mismo conjunto, agrega al arbolArista
        if (conjuntoU != conjuntoV) {
            arbolAristas[mstIndex] = aristas[i];
            ++mstIndex;

            // Unir los conjuntos de los vértices i y j
            for (int j = 0; j < n; ++j) {
                if (conjunto[j] == conjuntoU) {
                    conjunto[j] = conjuntoV;
                }
            }
        }
    }

    // Imprimir aristas dek arbol
    std::cout << "Aristas  por Kruskal:" << std::endl;
    for (int i = 0; i < n - 1; ++i) {
        std::cout << arbolAristas[i].i << " - " << arbolAristas[i].j << " : " << arbolAristas[i].peso << std::endl;
    }
}
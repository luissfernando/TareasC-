#include "matriz.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cout << "numero de vertices: ";	cin >> n;
	int **m=new int *[n]; 
	for(int i=0; i<n;i++)
		m[i]=new int[n]; 

	ceros(m,n);
	mostrar(m,n);
	cout<<"camino basico\n";
	caminoBasico(m,n);
	mostrar(m,n);
	aleatorio(m,n);
    mostrar(m,n);
	prim(m,n);
	kruskal(m,n);
	for(int i=0;i<n;i++)
		delete [] m[i];
	delete [] m;
	return 0;
}
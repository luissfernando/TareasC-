#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct pos {
	int i;
	int j;
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
void caminoBasico(int **Ma, int n){
	for(int i=0;i<(n-1);i++){
		Ma[i][i+1]=1;
		Ma[i+1][i]=1;
	}
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
//busqueda en profundidad
int formaCiclo(int s,int vp[],int t){
	for(int i=0;i<t;i++){
		if (s==vp[i])
			return 1;
	}
	return 0;
}
void llenarArregloMenosUno(int *A,int n){
	for(int i=0;i<n;i++)
		*(A+i) = -1;
}
void busquedaProfundidad(int **M, int n,int inicialNodo){
	int *vp = new int[n];
	llenarArregloMenosUno(vp,n);
	//int w=2; //nodo inicial
	vp[0]=inicialNodo;
	int k=0;
	while(true){
		for(int i=0;i<n;i++){
			if (M[inicialNodo][i]==1){
				if(!formaCiclo(i,vp,n)){	
					k++;	
					vp[k]=i;
					cout << inicialNodo+1 << "-" << vp[k]+1<< endl;
					inicialNodo=i;
					break;
				}	
			}
			/*Revisar*/
			if ( i==(n-1) && k<(n-1) )
				inicialNodo=vp[k-1];
			/*fin revisar*/
		}
		if (vp[n-1]!= -1)
			break;
	}
}
void busquedaAnchura(int **M,int n, int inicialNodo){
    int* vp = new int[n];
    llenarArregloMenosUno(vp, n);
    vp[0] = inicialNodo;

    queue<int> cola;
    cola.push(inicialNodo);

    while (!cola.empty()) {
        int nodoActual = cola.front();
        cola.pop();

        for (int i = 0; i < n; ++i) {
            if (M[nodoActual][i] == 1 && !formaCiclo(i, vp, n)) {
                vp[i] = nodoActual;
                cola.push(i);
                cout << nodoActual << "-" << i << endl;

                if (vp[n - 1] != -1) {
                    // Se encontró un ciclo hamiltoniano
                    delete[] vp;
                }
            }
        }
    } 	

    delete[] vp;
}
int main(int argc, char *argv[]) 
{
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
	cout<<"se agrego aleatoriamente\n";
	mostrar(m,n);
	
	int nodoInicial = 4;
	cout<<"busqueda en profundidad\n";
	busquedaProfundidad(m,n,nodoInicial-1);
	cout<<"\nbusqueda en anchura\n";
	busquedaAnchura(m,n,nodoInicial-1);
	for(int i=0;i<n;i++)
		delete [] m[i];
	delete [] m;
	return 0;
}

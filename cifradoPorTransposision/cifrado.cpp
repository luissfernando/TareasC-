#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
string cifrar(string texto){
	string textoPar,textoImpar;
	for(int i=0;i< texto.length();i++){   
		if (i%2==0)
			textoPar=textoPar+texto[i];
		else
			textoImpar=textoImpar+texto[i];
	}
	return textoPar+textoImpar;
}
string desifrar(string texto){
	int m;
	string textoPar="";
	string textoImpar="";
	string textoDescifrado;
	if (texto.length()%2 == 0)
		m=texto.length()/2;
	else
		m=texto.length()/2 + 1;
	
	for(int i=0;i< texto.length();i++)
	{   
		if (i<m)
			textoPar=textoPar+texto[i];
		else
			textoImpar=textoImpar+texto[i];
	}
	for(int i=0;i< texto.length()/2;i++){   
		textoDescifrado=textoDescifrado+textoPar[i]+textoImpar[i];
	}
	if (textoPar.length()>textoImpar.length())
		textoDescifrado=textoDescifrado+textoPar[textoPar.length()-1];
	else if (textoPar.length()<textoImpar.length())
		textoDescifrado=textoDescifrado+textoImpar[textoImpar.length()-1];
	return textoDescifrado;

}
void cifrarDesdeArchivo(){
	ofstream fich("cifrado.txt");
	if (!fich){
		cout << "Error al abrir ejemplo.dat\n";
		exit(EXIT_FAILURE);
	}
	string texto;
	cout<<"ingrese texto a cifrar a un archivo\n";
	cin>>texto;
	fich << cifrar(texto) << endl;
}
void decifrarDesdeArchivo(){
	ifstream fich("cifrado.txt");
	if (!fich){
		cout << "Error al abrir ejemplo.dat\n";
		exit(EXIT_FAILURE);
	}
	string linea;
// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(fich, linea)) {
    // Lo vamos imprimiendo	
		cout <<linea<<" => "<< desifrar(linea) << endl;
	}
}
void ReservarEs(char **&M,int fi,int co){
    M = new char*[fi];
    for(int i=0;i<fi;i++)
        M[i] = new char[co];
}
void LiberarEs(char **&M,int fi){ 
    for(int i=0;i<fi;i++){
        delete [] M[i];
}
}
void llenar(char **Ma, int fi,int co){ 
    for(int i=0; i<fi;i++)
        for(int j=0; j<co; j++)
            Ma[i][j] = '0';
}
void llenarFila(char **M,string texto,int f,int c){
	int k=0;
	for(int i=0; i<c;i++)
        for(int j=0; j<f; j++){
            if(i*j < texto.size()){
				M[j][i] = texto[k];
				k++;}
		}
}
void llenarColumna(char **M,string texto,int f,int c){
	int k=0;
	for(int i=0; i<f;i++)
        for(int j=0; j<c; j++){
            if(i*j < texto.size()){
				M[i][j] = texto[k];
				k++;}
		}
}
void mostrar(char **Ma, int fi,int co){
    for(int i=0; i<fi;i++){ 
        for(int j=0; j<co;j++)
            cout<<Ma[i][j]<<" ";
    std::cout<<endl;
    }
}
string leerArchivo(){
	ifstream fich("cifrado.txt");
	if (!fich){
		cout << "Error al abrir ejemplo.dat\n";
		exit(EXIT_FAILURE);
	}
	string linea,acumulador;
// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(fich, linea)) {
    // Lo vamos imprimiendo	
		cout <<linea << endl;
		acumulador = acumulador+linea;
	}
	return acumulador;

}
string cifrarRailFence(string mensaje, int alturaRiel) {
    vector<string> rieles(alturaRiel, ""); // Inicializa un vector de cadenas vacías para cada riel
    int fila = 0;
    int direccion = 1; // 1 para moverse hacia abajo, -1 para moverse hacia arriba
    for (char letra : mensaje) {
        rieles[fila] += letra;
        fila += direccion;
        // Cambia la dirección cuando alcanza los extremos (cima o fondo)
        if (fila == 0 || fila == alturaRiel - 1) {
            direccion = -direccion;
        }
    }
    string mensajeCifrado;
    for (string riel : rieles) {
        mensajeCifrado += riel;
    }
    return mensajeCifrado;
}
void mostrartrnasposisionColumnasConClave(char** M,int f,int c,int* key){
	for (int i = 0; i < c; ++i) {
        int columnaOriginal = key[i];
        for (int j = 0; j < f; ++j) {
            cout << M[j][columnaOriginal] << " ";
        }
        cout << endl;
    }
}
void mostrarTransposisionfilasConClave(char**M,int f,int c,int* key){
	for (int i = 0; i < f; ++i) {
        int filaOriginal = key[i];
        for (int j = 0; j < c; ++j) {
            cout << M[filaOriginal][j] << " ";
        }
        cout << endl;
    }
}
void invertir(char*M,int f){
    int inicio = 0;
    int fin = f - 1;

    while (inicio < fin) {
        // Intercambiar caracteres en las posiciones inicio y fin
        char temp = M[inicio];
        M[inicio] = M[fin];
        M[fin] = temp;

        // Mover los índices hacia el centro del arreglo
        inicio++;
        fin--;
    }
}
void avansarEspac(char **M,int c,int fila1,int fila2){
    for (int j = 0; j < c; ++j) {
        // Intercambiar elementos de las filas fila1 y fila2
        char temp = M[fila1-1][j];
        M[fila1-1][j] = M[fila2-1][j];
        M[fila2-1][j] = temp;
    }
}
void mostrarEnMatriz(char** M,int f,int c);
void transposisionImplem(char ** M,int f,int c){
	for(int i=0;i<f;i++){
		invertir(*(M+i),f);
		cout<<"\nintercambiar los valores de cada fila\n";
		mostrarEnMatriz(M,f,c);
		cout<<endl;
	}
	int a=1,b=2;
	for(int i=0;i<c-1;i++){
		avansarEspac(M,c,a,b);
		cout<<"intercambiar cada fila de la matriz uno adyasente del otro\n";
		mostrarEnMatriz(M,f,c);
		a=b;
		b++;
	}
}
void mostrarEnMatriz(char** M,int f,int c){
	for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << M[i][j] << " ";
        }
		cout<<endl;
	}
}
void mostrarTextoCifrado(char** M,int f,int c){
	for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << M[i][j];
        }
	}
}
void mostrarTextoDescifrado(char** M,int f,int c){
	int a=3,b=4;
	for(int i=0;i<c-1;i++){
		avansarEspac(M,c,a,b);
		a--;
		b--;
		// mostrarEnMatriz(M,f,c);
		// cout<<endl;
	}
	for(int i=0;i<f;i++){
		invertir(*(M+i),f);
		// mostrarEnMatriz(M,f,c);
		// cout<<endl;
	}
	//mostrar
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			cout<<M[j][i];
		}
	}
}
int main() {
	string archivo = leerArchivo();
	char **matriz;
	int fi=4; 
	int col=archivo.length()/fi+1;
	ReservarEs(matriz,fi,col);
	llenar(matriz, fi,col);
	//llenarColumna(matriz,archivo,fi,col);
	llenarFila(matriz,archivo,fi,col);
	// cout<<"\nComo se ve el cifrado en matriz"<<endl;
	// mostrar(matriz, fi, col);
	// cout<<"cifrado Con clave\n";
	int clave[] = {1, 0, 2};
	// mostrartrnasposisionColumnasConClave(matriz,fi,col,clave);

	// LiberarEs(matriz,fi);

	// col = 3;
	// fi = archivo.length()/col+1;
	// ReservarEs(matriz,fi,col);
	// llenar(matriz,fi,col);
	// llenarColumna(matriz,archivo,fi,col);
	// cout<<"\nComo se ve el cifrado internamente"<<endl;
	// mostrar(matriz, fi, col);

	// cout<<endl;
	// cout<<	cifrarRailFence(archivo,2);

	/*string textoClaro;
	cout << "Ingreso un texto para cifrar: ";
	getline(cin,textoClaro);
	//Cifrado
	cout <<"Texto Sifrado: " <<cifrar(textoClaro) << endl;
	//Descifrado
	cout <<"Texto DesCifrado: " << desifrar(cifrar(textoClaro)) << endl;*/
	//cifrarDesdeArchivo();
	//decifrarDesdeArchivo();
	
	//implementacion transpossion
	//transposisionImplem(matriz,fi,col,clave);
	cout<<"matriz\n";
	mostrarEnMatriz(matriz,fi,col);
	transposisionImplem(matriz,fi,col);

	cout<<" \nCifrado\n";
	mostrarTextoCifrado(matriz,fi,col);
	
	cout<<" \nDescifrado\n";
	mostrarTextoDescifrado(matriz,fi,col);
	// cout<<endl;
	// mostrarEnMatriz(matriz,fi,col);
	return 0;
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void escribirArchivo(string texto,string nameArchivo);
string leerArchivo(string nameArchivo);
int buscarNumero(char c,string pat){
	for(int i=0;i<pat.length();i++){
		if (c==pat[i])
			return i;
	}
	return -1;
}
char buscarLetra(int i,string pat){
	return  pat[i];
}
void cifradoCesar(string patron){
	string m;
	int k;
	cout << "Mensaje a cifrar: ";
	cin>>m;
	cout << "Factor K (entre 1 y " << patron.length()-1 <<"): ";
	cin >> k;
	int pos;
	int c;
	char txt;
    string cif = "";
	for(int i=0;i<m.length();i++){
		pos=buscarNumero(m[i],patron);
		c = (pos+k) % patron.length();
		txt=buscarLetra(c,patron);
		cif.append(1, txt);
	}
	escribirArchivo(cif,"cifrado");
	cout<<leerArchivo("cifrado");
}
void descifradoCesar(string patron){
	int k=1;
	cout<<"ingrese la clave de desencriptacion : ";
	cin>>k;
	string m = leerArchivo("cifrado");
	int pos,c;
	string txt;
    string descif="";
	for(int i=0;i<m.length();i++){
		pos=buscarNumero(m[i],patron);
		c = ((pos-k)+ (patron.length()) ) % patron.length();
		txt=buscarLetra(c,patron);
		//cout << txt;
        descif = descif+ txt;
	}
    cout<<descif<<endl;
    escribirArchivo(descif,"descifrado");
	// cout<<leerArchivo();
}

//decifrado de cesar para fuerza bruta
string descifradoCesarParaFB(string patron,int k){
	string m = leerArchivo("cifrado");
	int pos,c;
	string txt;
    string descif="";
	for(int i=0;i<m.length();i++){
		pos=buscarNumero(m[i],patron);
		c = ((pos-k)+ (patron.length()) ) % patron.length();
		txt=buscarLetra(c,patron);
		//cout << txt;
        descif = descif+ txt;
	}
    return descif;
}
string leerArchivo(string nameArchivo){
	ifstream fich(nameArchivo+".txt");
	if (!fich){
		cout << "Error al abrir ejemplo.dat\n";
		exit(EXIT_FAILURE);
	}
	string linea,acumulador;
// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(fich, linea)) {
    // Lo vamos imprimiendo	
		//cout <<linea << endl;
		acumulador = acumulador+linea;
	}
	return acumulador;
}

void escribirArchivo(string texto,string nameArchivo){
    ofstream archivo(nameArchivo+".txt");
    // Verificar si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Escribir en el archivo
        archivo << texto << endl;
        archivo.close();
    }
}
bool buscarCoincidencia(string palabraClave,string comparar){
    string sustraer;
    for(int i=0;i<comparar.size();i++){
        sustraer = comparar.substr(i,palabraClave.size());
        if(i+palabraClave.size() > comparar.size())
            break;
        if(sustraer == palabraClave)
            return true;
    }
    return false;
}
// Función que busca una palabra en un texto
bool buscarPalabra(const std::string& texto, const std::string& palabra) {
    // Usamos find para buscar la palabra en el texto
    size_t posicion = texto.find(palabra);

    // Si find devuelve npos, la palabra no se encontró
    if (posicion != std::string::npos) {
       // std::cout << "La palabra '" << palabra << "' se encuentra en la posición " << posicion << std::endl;
        return true;
    } else {
        //std::cout << "La palabra '" << palabra << "' no se encontró en el texto." << std::endl;
        return false;
    }
}
string descifradoFuerzaBruta(string patron){//,archivo leer
    string palabrasClave;
	cout<<"ingrese alguna coincidencia \n";
	cin>>palabrasClave;
	string archivo = leerArchivo("cifrado");
    ifstream leerDisccionario ("diccionario.txt");
    char respuesta;
    int cont = 1;
    string comparar;
    string palabra;
    while(getline(leerDisccionario,palabra)){
		for(int i=1;i<patron.length()-1;i++){
			comparar = descifradoCesarParaFB(patron,i);
			if(buscarCoincidencia(palabrasClave,comparar)){
				if(buscarPalabra(comparar,palabra)){
					cout<<"\n"<<i<<" Coincidencia:"<<comparar<<endl;
					cout<<"key : "<<i<<endl;
					return comparar;
				}
					//break;
			}
		}
    }
	leerDisccionario.close();
	return comparar;
}
void menu(){
	string patron="0123456789(),:.�����ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	cout<<"\tCIFRADO DE CESAR\n";
	cout<<"1) cifrar\n";
	cout<<"2) descifrar con clave\n";
	cout<<"3) decifrado a fuerza bruta sin key\n";
	cout<<"4) salir\n";
	int opc;
	cin>>opc;
	string decifradoBruto;
	while(opc!=4){
		switch (opc){
			case  1:
				cout<<"\nCIFRAR\n";
				cifradoCesar(patron);
				cout<<"\ningrese una opcion\n";
				cin>>opc;
				cout<<endl;
				break;
			case 2:
				cout<<"\nDESCIFRAR\n";
				descifradoCesar(patron);
				cout<<"\ningrese una opcion\n";
				cin>>opc;
				cout<<endl;
				break;
			case 3:
				cout<<"\nDESCIFRAR POR FUERZA BRUTA\n";
				decifradoBruto = descifradoFuerzaBruta(patron);
				cout<<"Decifrado: "<<decifradoBruto<<endl;
				cout<<"\ningrese una opcion\n";
				cin>>opc;
				cout<<endl;
				break;
			default:
				break;
		}

	}
}
int main(int argc, char *argv[]) {
	menu();
    // string palabraClave="ho";
    // string decifradoBruto;
	//descifradoCesar(cif,patron,k);
    return 0;
}
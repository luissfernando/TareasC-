#include <iostream>
#include <fstream>
using namespace std;
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
string cifradoCesar(string m,string patron,int k){
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
	return cif;
}
string descifradoCesar(string m,string patron, int k){
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
    //cout<<descif<<endl;
    return descif;
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
		//cout <<linea << endl;
		acumulador = acumulador+linea;
	}
	return acumulador;
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
void descifradoFuerzaBruta(string palabrasClave ,string patron){//,archivo leer
    string archivo = leerArchivo();
    ifstream leerDisccionario ("diccionario.txt");
    char respuesta;
    int cont = 1;
    string comparar;
    do{
        comparar = descifradoCesar(archivo,patron,cont);
        if(buscarCoincidencia(palabrasClave,comparar)){
            string linea;
// Obtener línea de archivo, y almacenar contenido en "linea"
           // while (getline(leerDisccionario, linea)) {
    // Lo vamos imprimiendo
                //if(linea == )
}
            cout<<"DESCIFRADO: "<<comparar<<endl;
            cout<<"Es este tu posible cifrado?  S/N\n";
            cin>>respuesta;
            if(respuesta == 'S'){
                cout<<"Cifrado exitoso:"<<comparar<<endl;
                break;
            }

        // }
        cont++;
    }while (respuesta == 'N');
    

}
int main(int argc, char *argv[]) {
	string patron="0123456789(),:.�����ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	// string m; //Mensaje a cifrar
	// string cif="";
	// int k; // patron 
	// cout << "Mensaje a cifrar: ";
	// getline(cin, m);
	// cout << "Factor K (entre 1 y " << patron.length()-1 <<"): ";
	// cin >> k;
    // cif = cifradoCesar(m,patron,k);
	// cout<<"Cifrado: "<<cif<<endl;
    string palabraClave="a";
    descifradoFuerzaBruta(palabraClave,patron);
    //descifradoCesar(cif,patron,k);
    return 0;
}
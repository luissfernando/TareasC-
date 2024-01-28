#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main() {
	string filename("cuento.txt");
	string filename2("cuentoCifrado.txt");
		
	FILE* input_file = fopen(filename.c_str(), "r");
	FILE* output_file = fopen(filename2.c_str(), "w");
	
	int cont=1;
	string textoClaro;
	char c;
	while ((c = fgetc(input_file)) != EOF) 
	{
		if (cont<=100)
		{
			textoClaro=textoClaro+c;
			cont++;
		}
		//Cifrar textoClaro en grupos de 100
		
	}
	for(int i=0;i<textoClaro.length();i++)
		fputc(textoClaro[i], output_file);
	
	fclose(input_file);
	fclose(output_file);
	
	return 0;
}
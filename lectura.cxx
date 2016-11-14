#include<iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	const string nfichero = "estudiantes-materias.ins";
	char cadena[90];
	ifstream fichero;
	fichero.open(nfichero.c_str());
	if(!fichero.fail()){
	    fichero.getline(cadena, 80, ' ');
	while (!fichero.eof()){
	    cout<< cadena << endl;
	    fichero.getline(cadena, 80, ' ');
	}
	fichero.close();
	}
}	
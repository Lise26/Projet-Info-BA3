#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;

//#include "projet.cpp"
#include "sequenceSearch.cpp"
#include "index_reader.cpp"
#include "headerSearch.cpp"

int main(int argc, char **argv) {

	//verif_parametres(argc, argv);
	
	cout << "début" << endl;
	
	vector<int> *tableau_offset(0);
	cout << "après vector tableau" << endl;
	
	vector<int> *header_offset(0);
	
	index_reader(tableau_offset,header_offset);  //sequence address in a table built from index File
	cout << "après index_reader" << endl;
	
	ifstream proteinFile("./P00533.fasta");
	
	int indice = searchSequence(proteinFile, tableau_offset);  //renvoie adresse de la sequence correcte (ou 0 si aucune sesuence ne correspond à la protéine
	cout << "après searchSequence" << endl;
	
	//string title = searchHeader(indice, header_offset);
	//cout << "nom de la protéine: " << title << endl;
	
	proteinFile.close();
	
	return(0);
}

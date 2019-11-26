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
#include "header_search.cpp"

int main(int argc, char **argv) {
	//verif_parametres(argc, argv);
	vector<int> tableau_offset(0);
	
	vector<int> header_offset(0);
	int indice =80000;
	header_offset = index_reader(0);  //sequence address in a table built from index File
	tableau_offset = index_reader(1);

	ifstream proteinFile("P00533.fasta");
	
	//int indice = searchSequence(proteinFile, tableau_offset);  //renvoie adresse de la sequence correcte (ou 0 si aucune sesuence ne correspond à la protéine
	cout << "après searchSequence" << endl;
	header_name(indice, header_offset);//Il faut encore couper le nom et le mettre dans un nouveau fichier
	
	//string title = searchHeader(indice, header_offset);
	//cout << "nom de la protéine: " << title << endl;
	
	proteinFile.close();
	
	return(0);
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
using namespace std;

#include "projet.cpp"
#include "sequenceSearch.cpp"

int main(int argc, char **argv) {

	//verif_parametres(argc, argv);
	
	cout << "Le programme commence" << endl;
	ifstream proteinFile("./P00533.fasta");
	
	cout << "Appel à la fonction searchSequence" << endl;
	searchSequence(proteinFile);
	
	cout << "Fermeture du fichier" << endl;

	proteinFile.close();
	
	
	return(0);
}

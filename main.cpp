#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
using namespace std;

#include "projet.cpp"
#include "sequenceSearch.cpp"

int main(int argc, char **argv) {
	
	verif_parametres(argc, argv);
	
	ifstream proteinFile("./P00533.fasta");
	searchSequence(proteinFile);
	proteinFile.close();
	
	
	return(0);
}

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

int main(int argc, char **argv) {

	//verif_parametres(argc, argv);
	
	cout << "début" << endl;
	
	vector<int> *tableau_offset(0);
	cout << "après vector tableau" << endl;
	
	index_reader(tableau_offset);
	cout << "après index_reader" << endl;
	
	ifstream proteinFile("./P00533.fasta");
	
	searchSequence(proteinFile, tableau_offset);
	cout << "après searchSequence" << endl;
	
	proteinFile.close();
	
	return(0);
}

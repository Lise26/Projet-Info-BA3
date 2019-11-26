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
#include "test_header.cpp"

int main(int argc, char **argv) {

	//verif_parametres(argc, argv);
	
	vector<int> tableau_offset(0);
	vector<int> header_offset(0);
	index_reader(&tableau_offset, &header_offset);
	
	ifstream proteinFile("./P00533.fasta");
	//ifstream proteinFile("./Q6GZX4.fasta");
	header_name(searchSequence(proteinFile, &tableau_offset), header_offset);
	
	proteinFile.close();
	
	return(0);
}

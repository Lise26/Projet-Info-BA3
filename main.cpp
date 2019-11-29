#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

#include "parameters.h"
#include "indexSearch.h"
#include "sequenceSearch.h"
#include "headerSearch.h"

int main(int argc, char **argv) {
	
	parameters verif;
	indexSearch ind;
	sequenceSearch s;
	headerSearch head;
	
	verif.verifParameters(argc, argv);			//vérification of the number of parameters given in input
	
	string nameSequence = argv[2];
	nameSequence.append(".psq");				//construction of the name of the sequence file in the database
	
	string nameIndex = argv[2];
	nameIndex.append(".pin");				//construction of the name of the index file in the database
	
	string nameHeader = argv[2];
	nameHeader.append(".phr");				//construction of the name of the header file in the database
	
	ifstream proteinFile(argv[1]);									
	ifstream sequenceFile(nameSequence);								
	ifstream indexFile(nameIndex);                                   	
	ifstream headerFile(nameHeader);
	
	vector<int> tableauOffset(0);				//varaiables to keep information from the indexFile
	vector<int> headerOffset(0);
	vector<char> titre;
	vector<char> date;
	vector<char> name;
	int version, nbSeq, lmax, size, sizet, sized =0;
	int64_t residu = 0;
	
	ind.indexReader(indexFile, &tableauOffset, &headerOffset, &version, &nbSeq, &lmax, &residu, &titre, &date, &sizet, &sized);		
	
	if(sequenceFile.is_open()) {
		//search for a match between the query protein and the sequence file of the database and return the result of the research into a file : result.txt
		head.header_name(headerFile, s.sequenceMatch(proteinFile, sequenceFile, &tableauOffset), headerOffset, &name, &size); 
	}
	
	sequenceFile.close();
	proteinFile.close();
	
	string p(sizet,0);
	for(int i = 0; i < sizet; i++){
		p[i] = titre[i];
	}
	
	string d(sized,0);
	for(int i = 0; i < sized; i++){
		d[i] = date[i];
	}
	
	string n(size,0);
	for(int i = 0; i < size; i++){
		n[i] = name[i];
	}

	ofstream result("./result.txt");
	if(result){															//Avec les classes je vais arranger ça en plus beau, j'ai juste la flemme de le refaire 2x
		result << "Database title : ";
		result << p << endl;
		result << "Database time : ";
		result << d << endl;
		result << "Database size : ";
		result << residu << " residues in " << nbSeq << " sequences"<< endl;
		result << "Longeset db sequence : ";
		result << lmax << endl;
		result << "\n\n" << endl;
		result << "The matching protein is : \n" << n << endl;
	}	
	
	return(0);
}

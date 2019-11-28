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
	vector<char> titre;
	vector<char> date;
	vector<char> name;
	int version, nbSeq, lmax, size, sizet, sized =0;
	int64_t residu = 0;
	index_reader(&tableau_offset, &header_offset, &version, &nbSeq, &lmax, &residu, &titre, &date, &sizet, &sized);
	//for (int i=0; i < sizeof(date); i++){
	//cout << date[i];}
	
	ifstream proteinFile("/home/student/Bureau/P00533.fasta");
	//ifstream proteinFile("/home/student/Bureau/Q9Y6V0.fasta");
	//ifstream proteinFile("/home/student/Bureau/P07327.fasta");
	header_name(searchSequence(proteinFile, &tableau_offset), header_offset, &name, &size);
	for (int i=0; i < size; i++){
	cout << name[i];}
	cout << endl;
	
	
	//cout << size >> result.txt;
	
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
	
	//cout << d[sizeof(d)-10] << endl;
	//cout << d << "oui" << endl;
	ofstream result("/home/student/Bureau/result.txt");
	if(result){//Avec les classes je vais arranger ça en plus beau, j'ai juste la flemme de le refaire 2x
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

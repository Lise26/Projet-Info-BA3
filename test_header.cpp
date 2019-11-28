#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string decToHex(int decimal){ //Convert from decimal to hex
	stringstream ss;
	ss << hex << decimal;
	string res ( ss.str() );
	return res;
}

int hexToDecimal(string hex_value){//Convert from hex to decimal
	stringstream ss;
	ss << hex_value;
	int res;
	ss >> hex >> res ;
	return res;
}

void header_name(int indice, vector<int> header_offset, vector<char> *name, int *size){ // Init values of parameters by reading the header file
	int stock = 0;			//Each byte will be stored there
	string previous = "0";			//Keep the previous byte
	string before_last = "0";			//Keep the before last byte
	ifstream f ("/home/student/Bureau/uniprot_sprot.fasta.phr");
	for(int i = header_offset[indice]; i < header_offset[indice+1];i++){
		f.seekg(i);
		f.read((char *)&stock, 1);	
		string res = decToHex(stock);
		if(before_last == "80" && previous == "1a"){ 
			if (stock <= 128){	//Read next bytes as string if current byte <= 128
				char* title = new char[stock+2];
				f.read((char *)&*title, stock+2);
				i+= (stock+2);
				if(title[0] == 's' && title[1] == 'p'){
					for(int i = 0; i < stock+2; i++){
						(*size) = i-1;
						(*name).push_back(title[i]);
					}
				}		
			}
			else if(stock > 128){	//Read next bytes as int if current byte > 128, then as string
				int byte = stock - 128;	//How many bytes it shall read for the length of the following string
				cout << "byte " << byte << endl;
				f.read((char *)&stock, byte);
				i+= byte;
				char* title = new char[stock+2];
				f.read((char *)&*title, stock+2);
				i+= (stock+2);
				if(title[0] == 's' && title[1] == 'p'){
					for(int i = 0; i < stock+2; i++){
						(*size) = i-1;
						(*name).push_back(title[i]);
					}
				}	
			}
		}
		
		before_last = previous;
		previous = res;
	}
}

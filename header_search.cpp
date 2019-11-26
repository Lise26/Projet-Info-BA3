#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string decToHex(int decimal){
	stringstream ss;
	ss << hex << decimal;
	string res ( ss.str() );
	return res;
}

int hexToDecimal(string hex_value){
	stringstream ss;
	ss << hex_value;
	int res;
	ss >> hex >> res ;
	return res;
}

void header_name(int indice, vector<int> header_offset){
	int stock = 0;
	string previous = "0";
	string before_previous = "0";
	string titre;
	ifstream f ("uniprot_sprot.fasta.phr");
	for(int i = header_offset[indice]; i < header_offset[indice+1];i++){
		f.seekg(i);
		f.read((char *)&stock, 1);	//On lit le 1er byte
		string res = decToHex(stock);
		if(before_previous == "80" && previous == "1a"){ //Si les bytes précédents sont 801a
			if (stock <= 128){	//Gère les différences de stockage (quid du  = ??)
				//cout << "stock " << stock << endl;
				char* titre = new char[stock+2];
				f.read((char *)&*titre, stock+2);
				i+= (stock+2);
				cout << titre << endl;
				//cout << titre[135] << endl;
			}
			else if(stock > 128){
				int byte = stock - 128;
				cout << "byte " << byte << endl;
				f.read((char *)&stock, byte);
				string name = decToHex(stock);
				i+= byte;
				char* titre = new char[stock+2];
				f.read((char *)&*titre, stock+2);
				i+= (stock+2);
				cout << titre << endl;
				
			}
		}
		before_previous = previous;
		previous = res;
	}
	
}

/*int main(){
	
	header_name(8,{0,183,360, 539, 718,893,1070,1249,1426,1624,1801,1978,2157,2336,2507});	
	return 0;
}*/

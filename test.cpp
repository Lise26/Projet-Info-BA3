#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main(){
	map<string,int> dicoLetters = {{" ",0},{"A",1},{"B",2},{"C",3},{"D",4},{"E",5},{"F",6},{"G",7},{"H",8},{"I",9},{"J",27},{"K",10},{"L",11},{"M",12},{"N",13},{"O",26},{"P",14},{"Q",15},{"R",16},{"S",17},{"T",18},{"U",24},{"V",19},{"W",20},{"X",21},{"Y",22},{"Z",23},{"*",25}};
	//map<string,int> dicoNumbers = {{0," "},{1,"A"},{2,"B"},{3,"C"},{4,"D"},{5,"E"},{6,"F"},{7,"G"},{8,"H"},{9,"I"},{27,"J"},{10,"K"},{11,"L"},{12,"M"},{13,"N"},{26,"O"},{14,"P"},{15,"Q"},{16,"R"},{17,"S"},{18,"T"},{24,"U"},{19,"V"},{20,"W"},{21,"X"},{22,"Y"},{23,"Z"},{25,"*"}};
	
	//ifstream proteinFile("./P00533.fasta");
	ifstream sequenceFile("./uniprot_sprot.fasta.psq");
	if(sequenceFile.is_open())
	{
		cout << "sequenceFileOpened" << endl;
		//unsigned char letter;
		//int counter = 0;
		//while(sequenceFile >> letter and counter<8){  // >> operateur d'extraction de flux (lit le fichier element par element et renvoie false quand EOF)
		//								// sequenceFile: nom du fichier, letter: variable dans laquelle on met le caractère lu
		//	counter++;
		//	cout << counter << " " << int(letter) << " " << letter << endl;		
		//}
		
		//uint8_t buffer[1024*1024];
		//cout << "---" << endl;
		//buffer[8];
		//sequenceFile.getline(buffer,8);
		//cout << buffer << endl;
		
		char letter;
		int counter = 0;
		while(sequenceFile.get(letter) and counter<20){  // >> operateur d'extraction de flux (lit le fichier element par element et renvoie false quand EOF)
														// sequenceFile: nom du fichier, letter: variable dans laquelle on met le caractère lu
			counter++;
			cout << counter << " " << int(letter) << endl; 	//cout << dicoNumbers["9"]
		}
		
		sequenceFile.close();
	}
	//proteinFile.close();
	
	
	return 0;
}

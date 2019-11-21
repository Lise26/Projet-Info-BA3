#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
	//cout << "WTF" << endl;
	//FILE * f;
	//f=fopen("uniprot_sprot.fasta.pin", "rb");
	int version = 0;
	int type =0;
	int len=0;
	int lenT = 0;
	//char titre[len], tstamp[lenT]; // len = ?, syntaxe tableau taille fixe et connue à la compilation, -> char* titre = new char[len];
	
	//char* tstamp = new char[lenT];
	//string ligne;
	//string titre, tstamp;
	ifstream f ("uniprot_sprot.fasta.pin");
	//if(f==NULL)
		//cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	//else{
	
		f.read ((char *)&version, sizeof(version));
		f.read ((char *)&type, sizeof(type));
		f.read ((char *)&len, sizeof(len));
		cout << "Hello " << len << endl;
		char* titre = new char[len/16777216];
		cout << "Hell2" << endl;
		string s(len/16777216, '.');
		for(int i = 0; i < len/16777216; i++){
			s[i] = titre[i];
		}
		f.read ((char *)&titre, len/16777216*sizeof(char));
		cout << "Hello3 " << endl;
		//getline(f, ligne);
		//f.read ((char *)&lenT, sizeof(lenT));
		//f.read ((char *)&tstamp, sizeof(tstamp));
		//f.read ((char *)&test, sizeof(test));
	//}	
	/*else{
		fread (&version,sizeof(version),1,f);
		
		fread (&type,sizeof(type),1,f);

		fread (&field,sizeof(len),1,f);
		fread (&titre,sizeof(titre),1,f);
		fread (&len,sizeof(len),1,f);
		//fread (&tstamp,sizeof(tstamp),1,f);*/
		//cout << "AVEC GETLINE : " << ligne << endl;
		//for(int i=0;i<len;i++){
		//cout << titre << endl;//}
		cout << "Version : " << version << " Type : " << type << " Len : " << len << " Titre : " << s << endl;//<< " Tlen : " << lenT << " Tstamp : " << tstamp << endl;
		//cout << "BIT PAR BIT : Version : " << version << " Type : " << type << " Len : " << len << endl;; // << " Titre : " << titre << " Tlen : " << lenT/16777216 << " Tstamp : " << tstamp << endl;;
	//}
	return 0;
}

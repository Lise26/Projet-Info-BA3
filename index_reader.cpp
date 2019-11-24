#include <fstream>
#include <iostream>
#include <string>
using namespace std;

inline void littleBigEndian (int &x) {
		x = ((x >> 24) & 0xffL) | ((x >> 8) & 0xff00L) | ((x << 8) & 0xff0000L) | ((x << 24) & 0xff000000L);
		}

int index_reader(vector<int> *tableau_offset, vector<int> *header_offset){
	int version, type, len, lenT, nbSeq, lenMax = 0;
	int64_t residu = 0;
	ifstream f ("uniprot_sprot.fasta.pin");
	
	f.read ((char *)&version, sizeof(version));
	littleBigEndian(version);
		
	f.read ((char *)&type, sizeof(type));
	littleBigEndian(type);
		
	f.read ((char *)&len, sizeof(len));
	littleBigEndian(len);
		
	char titre[len];		
	f.read ((char *)&titre, len*sizeof(char));
	string s(len,0);
	for(int i = 0; i < len; i++){
		s[i] = titre[i];
	}
		
	f.read ((char *)&lenT, sizeof(lenT));
	littleBigEndian(lenT);
		
	char tstamp[lenT];		
	f.read ((char *)&tstamp, lenT*sizeof(char));
	string p(lenT,0);
	for(int i = 0; i < lenT; i++){
		p[i] = tstamp[i];
	}
		
	f.read ((char *)&nbSeq, sizeof(nbSeq));
	littleBigEndian(nbSeq);
		
	f.read ((char *)&residu, sizeof(residu));
		
	f.read ((char *)&lenMax, sizeof(lenMax));
	littleBigEndian(lenMax);
	cout << "nbSeq=" << nbSeq << endl;
		
	int headerOff[nbSeq+1];
	//(*header_offset).push_back(1);
	cout << "avant header" << endl;
	for(int i=0; i < (nbSeq+1); i++){
		f.read ((char *)&headerOff[i], sizeof(int));
		cout << headerOff[i] << endl;
		littleBigEndian(headerOff[i]);
		cout << headerOff[i] << "avant tableauH i=" << i << endl;
		(*header_offset).push_back(headerOff[i]);
		cout << "after push" << endl;
	}
		
	int seqOff[nbSeq+1];
	for(int i=0; i < (nbSeq+1); i++){
		f.read ((char *)&seqOff[i], sizeof(int));
		littleBigEndian(seqOff[i]);
		cout << "avant tableau i=" << i << endl;
		(*tableau_offset).push_back(seqOff[i]);
		cout << "apres tableau i=" << i << endl;
	}
	
	cout << "index_reader 05" << endl;
	int ambOff[nbSeq+1];
	for(int i=0; i < (nbSeq+1); i++){
		f.read ((char *)&ambOff[i], sizeof(int));
		littleBigEndian(ambOff[i]);
	}
		
	//cout << "Version : " << version << " Type : " << type << " Len : " << len << " Titre : " << s << " Tlen : " << lenT << " Tstamp : " << p << endl;
	//cout << "Nb Sequence : " << nbSeq << " Résidu : " << residu << " Len max : " << lenMax << endl;
	cout << "fin index_reader" << endl;
	return 0;
}


//int* getseqOff() {	
	//return seqOff[nbSeq+1];
//}

//class Truc {
	//int s[5];
	//vector<int> t;
	//int* getS() { return s; }
	//vector<int> const& getT() { return t; }
//};

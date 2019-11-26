#include <fstream>
#include <iostream>
#include <string>
using namespace std;

inline void littleBigEndian (int &x) {
		x = ((x >> 24) & 0xffL) | ((x >> 8) & 0xff00L) | ((x << 8) & 0xff0000L) | ((x << 24) & 0xff000000L);
		}

vector<int> index_reader(int t){
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
		
	vector<int> header_offset;
	int headerOff[nbSeq+1];
	for(int i=0; i < (nbSeq+1); i++){
		f.read ((char *)&headerOff[i], sizeof(int));
		littleBigEndian(headerOff[i]);
		header_offset.push_back(headerOff[i]);
	}
		
	vector<int> tableau_offset;
	int seqOff[nbSeq+1];
	for(int i=0; i < (nbSeq+1); i++){
		f.read ((char *)&seqOff[i], sizeof(int));
		littleBigEndian(seqOff[i]);
		tableau_offset.push_back(seqOff[i]);
	}
	
	/*int ambOff[nbSeq+1];
	for(int i=0; i < (nbSeq+1); i++){
		f.read ((char *)&ambOff[i], sizeof(int));
		littleBigEndian(ambOff[i]);
	}*/
		
	//cout << "Version : " << version << " Type : " << type << " Len : " << len << " Titre : " << s << " Tlen : " << lenT << " Tstamp : " << p << endl;
	//cout << "Nb Sequence : " << nbSeq << " Résidu : " << residu << " Len max : " << lenMax << endl;
	if(t==0)
		return header_offset;
	else if (t==1)
		return tableau_offset;
	
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

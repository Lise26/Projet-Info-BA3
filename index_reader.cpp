#include <fstream>
#include <iostream>
#include <string>
using namespace std;

inline void littleBigEndian (int &x) {
		x = ((x >> 24) & 0xffL) | ((x >> 8) & 0xff00L) | ((x << 8) & 0xff0000L) | ((x << 24) & 0xff000000L);
		}

int index_reader(vector<int> *tableau_offset, vector<int> *header_offset, int *versiont, int *nbSeqt, int *lmaxt, int64_t *residut, vector<char> *titlet, vector<char> *datet, int *sizet, int *sized){
	int version, type, len, lenT, nbSeq, lenMax = 0;
	int64_t residu = 0;
	ifstream f ("/home/student/Bureau/uniprot_sprot.fasta.pin");
	
	f.read ((char *)&version, sizeof(version));
	littleBigEndian(version);
	(*versiont)=version;
		
	f.read ((char *)&type, sizeof(type));
	littleBigEndian(type);
		
	f.read ((char *)&len, sizeof(len));
	littleBigEndian(len);
	(*sizet) = len;
		
	char title[len];		
	f.read ((char *)&title, len*sizeof(char));
	string s(len,0);
	for(int i = 0; i < len; i++){
		s[i] = title[i];
		(*titlet).push_back(title[i]);
	}
	
	f.read ((char *)&lenT, sizeof(lenT));
	littleBigEndian(lenT);
		
	char tstamp[lenT];		
	f.read ((char *)&tstamp, lenT*sizeof(char));
	string p(lenT,0);
	for(int i = 0; i < lenT; i++){
		p[i] = tstamp[i];
		(*sized) = i - 6;
		(*datet).push_back(tstamp[i]);
	}
		
	f.read ((char *)&nbSeq, sizeof(nbSeq));
	littleBigEndian(nbSeq);
	(*nbSeqt) = nbSeq;
		
	f.read ((char *)&residu, sizeof(residu));
	(*residut) = residu;
		
	f.read ((char *)&lenMax, sizeof(lenMax));
	littleBigEndian(lenMax);
	(*lmaxt) = lenMax;
	
	int headerOff[nbSeq+1];
	for(int i=0; i < (nbSeq+1); i++){
		f.read ((char *)&headerOff[i], sizeof(int));
		littleBigEndian(headerOff[i]);
		(*header_offset).push_back(headerOff[i]);
	}
		
	int seqOff[nbSeq+1];
	for(int i=0; i < (nbSeq+1); i++){
		f.read ((char *)&seqOff[i], sizeof(int));
		littleBigEndian(seqOff[i]);
		(*tableau_offset).push_back(seqOff[i]);
	}
	return 0;
}

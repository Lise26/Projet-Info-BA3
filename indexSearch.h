#include <fstream>
#include <iostream>
#include <vector> 
#include <string>
#include <stdio.h>
using namespace std;

class indexSearch {
	vector<int> *headerOffset;
	vector<int> *seqOffset;
	
	public :
		inline void littleBigEndian (int &x);
		int indexReader(ifstream& indexFile, vector<int> *tableauOffset, vector<int> *headerOffset, int *versiont, int *nbSeqt, int *lmaxt, int64_t *residut, vector<char> *titlet, vector<char> *datet, int *sizet, int *sized);	
};

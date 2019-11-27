bool checkSequence(istream& sequenceFile, vector<char> proteinTable){
	
	char letter;
	int indiceLetter = 0;
	bool equal = true;
	//map<string,int> dicoLetters = {{" ",0},{"A",1},{"B",2},{"C",3},{"D",4},{"E",5},{"F",6},{"G",7},{"H",8},{"I",9},{"J",27},{"K",10},{"L",11},{"M",12},{"N",13},{"O",26},{"P",14},{"Q",15},{"R",16},{"S",17},{"T",18},{"U",24},{"V",19},{"W",20},{"X",21},{"Y",22},{"Z",23},{"*",25}};
	//map<int,char> dicoNumbers = {{0,' '},{1,'A'},{2,'B'},{3,'C'},{4,'D'},{5,'E'},{6,'F'},{7,'G'},{8,'H'},{9,'I'},{27,'J'},{10,'K'},{11,'L'},{12,'M'},{13,'N'},{26,'O'},{14,'P'},{15,'Q'},{16,'R'},{17,'S'},{18,'T'},{24,'U'},{19,'V'},{20,'W'},{21,'X'},{22,'Y'},{23,'Z'},{25,'*'}};
	map<int,string> dicoNumbers = {{0," "},{1,"A"},{2,"B"},{3,"C"},{4,"D"},{5,"E"},{6,"F"},{7,"G"},{8,"H"},{9,"I"},{27,"J"},{10,"K"},{11,"L"},{12,"M"},{13,"N"},{26,"O"},{14,"P"},{15,"Q"},{16,"R"},{17,"S"},{18,"T"},{24,"U"},{19,"V"},{20,"W"},{21,"X"},{22,"Y"},{23,"Z"},{25,"*"}};
	
	//sequenceFile.get(letter); 											//skip first blank char

	while(sequenceFile.get(letter) and int(letter)!=0 and equal == true){
		cout << indiceLetter << " " << dicoNumbers[int(letter)][0] << "/" << proteinTable[indiceLetter] << "/" << int(letter) << endl;
		
		if(dicoNumbers[int(letter)][0] != proteinTable[indiceLetter]){
			cout << "equal = false" << endl;
			equal=false;
	    } else {
			cout << "true" << endl;
		}
	    indiceLetter++; 
	}
	
	return equal;
}


int searchSequence(ifstream& proteinFile, vector<int> *tableau_offset){
	
	ifstream sequenceFile("./uniprot_sprot.fasta.psq");
	int indiceFINAL;
	
	if(sequenceFile.is_open())
	{
		cout << "sequenceFileOpened" << endl;
		
		vector<char> proteinTable;			
		char protLetter;
		int counter=0;
		string protLine;
		getline(proteinFile,protLine);  								//la premiere ligne est le titre de la protéine
		cout << "ligne1: " << protLine << endl;							//on lit la sequence protéine à partir de deuxieme ligne
		
		while(proteinFile >> protLetter and !proteinFile.eof()){  		//1:lit lettre dans fichier et met variable dans protLetter, 2:arrete de mettre dans le tableau quand on arrive à la fin du fichier 
			proteinTable.push_back(protLetter);
			cout << proteinTable[counter];	
			counter++;					
		}
		
		bool proteinFound = false;
		int xxx=0;
		int offset=0;
		while(!sequenceFile.eof() and proteinFound == false){
			offset = tableau_offset->at(xxx);
			cout << offset << endl;
			cout << "chk sequence " << xxx << endl;
			proteinFound = checkSequence(sequenceFile.seekg(offset), proteinTable);
			xxx++;
		}
		indiceFINAL = xxx-1;
		sequenceFile.close();
	}
	cout << indiceFINAL << endl;
	return indiceFINAL;
}

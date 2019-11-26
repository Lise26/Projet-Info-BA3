string searchHeader(int indice, vector<int> *header_offset){
	
	string title = "";
	
	ifstream headerFile("uniprot_sprot.fasta.phr");
	
	if(headerFile.is_open())
	{
		cout << "headerFileOpened" << endl;
		bool intitle = false;
		int offset = header_offset->at(indice);
		headerFile.seekg(offset);  //on se positionne au bon endroit dans le header file
		char elem;
		char lastchar;
		while (headerFile.get(elem)){   //11 = 1A
			cout << "elem" << elem << endl;
			if (int(elem)==11){
				intitle=true;  //on peut commencer à remplir le string du titre
			}
			if (int(elem)==0 and int(lastchar)==0){
				break;  //sinon on parcourt tout le fichier header
			}
			lastchar = elem;  //garder en mémoire le dernier élément
			
			if (intitle == true){
				title.push_back(elem);
			}
		}
	
	headerFile.close();
	}
	
	return title;
}

string searchHeader(int indice, vector<int> *header_offset){
	
	string title = "";
	
	ifstream headerFile("./uniprot_sprot.fasta.phr");
	
	if(headerFile.is_open())
	{
		cout << "headerFileOpened" << endl;
	
		int offset = header_offset->at(indice);
		headerFile.seekg(offset);  //on se positionne au bon endroit dans le header file
		headerFile.get();
	
	headerFile.close();
	}
	
	return title;
}

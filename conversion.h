#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class conversion {
	stringstream ss;
	
	public :
		string decToHex(int decimal);
		int hexToDecimal(string hex_value);	
};

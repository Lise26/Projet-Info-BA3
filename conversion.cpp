#include "conversion.h"

string conversion::decToHex(int decimal){ 								//Convert from decimal to hex
	ss << hex << decimal;
	string res ( ss.str() );
	return res;
}

int conversion::hexToDecimal(string hex_value){							//Convert from hex to decimal
	ss << hex_value;
	int res;
	ss >> hex >> res ;
	return res;
}

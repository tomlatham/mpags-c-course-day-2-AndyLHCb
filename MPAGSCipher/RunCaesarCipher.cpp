#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& input, const bool encrypt, const size_t key)
{
	constexpr size_t abetSize {26};
	const char abet[abetSize] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	std::string output{""};
	
	const int direction{ encrypt ? 1 : -1 };

	// ensure that the key is in the range 0 - abetSize
	const size_t tkey { key % abetSize };

	for(char c: input)
	{
		for(size_t i{0};i<abetSize;++i){
			if(abet[i]==c){
				const size_t position { i + abetSize + direction * tkey };
				output += abet[position%abetSize];			
				break;
			}
		}
	}

	return output;
}




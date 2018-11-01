#include "Crypt.hpp"

std::string crypt(const std::string input,const bool encrypt,const int key)
{
	const char abet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	std::string output{""};
	
	int direction{-1};
	if(encrypt){direction = 1;}


	for(char c: input)
	{
		for(int i{0};i<26;++i){
			if(abet[i]==c){
				int position = i + direction * key;
				position = ((position % 26) + 26) % 26;
				output += abet[position];			
			}
		}
	}

	return output;
	
}




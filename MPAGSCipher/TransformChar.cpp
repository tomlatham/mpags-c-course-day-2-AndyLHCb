#include "TransformChar.hpp"

std::string transformChar(const char in_char)
{
  /*
    This performs the relevant editting of the input chars and returns them as a string. in_char is the input char, obviously.
   */
  std::string returnStr{""};
 // Uppercase alphabetic characters
    if (std::isalpha(in_char)) {
      returnStr += std::toupper(in_char);
    }

    // Transliterate digits to English words
    switch (in_char) {
      case '0':
	returnStr += "ZERO";
	break;
      case '1':
	returnStr += "ONE";
	break;
      case '2':
	returnStr += "TWO";
	break;
      case '3':
	returnStr += "THREE";
	break;
      case '4':
	returnStr += "FOUR";
	break;
      case '5':
	returnStr += "FIVE";
	break;
      case '6':
	returnStr += "SIX";
	break;
      case '7':
	returnStr += "SEVEN";
	break;
      case '8':
	returnStr += "EIGHT";
	break;
      case '9':
	returnStr += "NINE";
	break;
    }
    return returnStr;
    //we don't add non-alphanumeric chars
}


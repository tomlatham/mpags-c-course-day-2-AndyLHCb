// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

//functions I've written
#include "TransformChar.hpp"
#include "DealingWithFiles.hpp"
#include "CommandLine.hpp"
#include "Crypt.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  bool encrypt {true};
  int key{1};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  if(processCommandLine(cmdLineArgs,
			helpRequested,
			versionRequested,
			inputFile,
			outputFile,
			encrypt,
			key))
    {return 1;}

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help          Print this help message and exit\n\n"
      << "  --version          Print version information\n\n"
      << "  -i FILE            Read text to be processed from FILE\n"
      << "                     Stdin will be used if not supplied\n\n"
      << "  -o FILE            Write processed text to FILE\n"
      << "                     Stdout will be used if not supplied\n\n"
      << "  -k KEY             Specify a key to be used for the cipher\n"
      << "                     A value 1 will be taken if not specified\n\n"
      << "--encrypt|--cipher   Specifies that the text will be encrypted\n"
      << "--decrypt|--decipher Specifies that the text will be decrypted\n\n";
    
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.2.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::string Input{in(inputFile)};//from DealingWithFiles.cpp
    for(char i:Input)
      {
	inputText += transformChar(i);//from TransformChar.cpp
      }
  }

  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
  else
  {
    while(std::cin >> inputChar)
      {
	inputText += transformChar(inputChar);//from TransformChar.cpp
      }
  }
  
  inputText = crypt(inputText,encrypt,key);

  // Output the transliterated text
  if (!outputFile.empty()) {
    out(inputText,outputFile);//from DealingWithFiles.cpp
    std::cout << "File Written" << std::endl;
  }

  else{std::cout << inputText << std::endl;}

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}

#include "CommandLine.hpp"

bool processCommandLine(
 const std::vector<std::string>& args,
 bool& helpRequested,
 bool& versionRequested,
 std::string& inputFileName,
 std::string& outputFileName,
 bool& encrypt,
 size_t& key)
{
  
  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nargs {args.size()};
  
  for (size_type i {1}; i < nargs; ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      helpRequested = true;
    }
    else if (args[i] == "--version") {
      versionRequested = true;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nargs-1) {
	std::cerr << "[error] -i requires a filename argument" << std::endl;
	// exit main with non-zero return to indicate failure
	return true;
      }
      else {
	// Got filename, so assign value and advance past it
	inputFileName = args[i+1];
	++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nargs-1) {
	std::cerr << "[error] -o requires a filename argument" << std::endl;
	// exit main with non-zero return to indicate failure
	return true;
      }
      else {
	// Got filename, so assign value and advance past it
	outputFileName = args[i+1];
	++i;
      }
    }
    else if(args[i] == "-k"){
	if (i == nargs-1){
	std::cerr << "[error] -k requires a key value" << std::endl;
	return true;				       
      }
      else {
	std::string temp{args[i+1]};
	if ( temp.front() == '-' ) {
	  std::cerr << "[error] key should be a positive integer" << std::endl;
	  return true;
	}
       	key = std::stoul(temp);
        ++i;
      }
    }
    else if(args[i] == "--encrypt" or args[i] == "--cipher")
    {encrypt = true;}
    else if(args[i] == "--decrypt" or args[i] == "--decipher")
    {encrypt = false;}


    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return true;
    }
  }
  return false;
}

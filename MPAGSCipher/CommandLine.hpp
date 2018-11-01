#ifndef COMMAND_LINE
#define COMMAND_LINE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

bool processCommandLine(
 const std::vector<std::string>& args,
 bool& helpRequested,
 bool& versionRequested,
 std::string& inputFileName,
 std::string& outputFileName,
 bool& encrypt,
 int& key);

#endif

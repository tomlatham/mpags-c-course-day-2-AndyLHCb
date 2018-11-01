#ifndef DEALING_WITH_FILES
#define DEALING_WITH_FILES

#include <fstream>
#include <string>

bool out(const std::string& filename, const std::string& output);
bool in(const std::string& filename, std::string& input);
  
#endif

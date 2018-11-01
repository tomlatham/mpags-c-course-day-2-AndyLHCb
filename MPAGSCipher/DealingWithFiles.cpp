#include "DealingWithFiles.hpp"

bool out(const std::string& filename, const std::string& output)
{
  std::ofstream out_file{filename};
  if(not out_file.good()){return false;}
  out_file << output << std::endl;
  return true;
}

bool in(const std::string& filename, std::string& input)
{
  std::ifstream in_file{filename};
  if(not in_file.good()){return false;}
  in_file >> input;
  return true;
}

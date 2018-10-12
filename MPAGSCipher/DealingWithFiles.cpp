#include "DealingWithFiles.hpp"

bool out(std::string Output, std::string Filename)
{
  std::ofstream out_file{Filename};
  if(not out_file.good()){return 1;}
  out_file << Output << std::endl;
  return 0;
}

std::string in(std::string Filename)
{
  std::ifstream in_file{Filename};
  std::string contents{""};
  if(not in_file.good()){return "ERROR BAD INPUT FILE";}
  in_file >> contents;
  return contents;
}

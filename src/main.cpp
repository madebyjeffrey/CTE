#include <fstream>
#include <iostream>
#include <string>
#include <locale>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include "process_template.h"

namespace BF = boost::filesystem;

int main(int argc, char**argv) {

  std::locale::global(std::locale("en_CA.UTF-8"));

  if (argc != 2) {
    std::cout << "CTE Template Engine" << std::endl;
    std::cout << "cte [input]" << std::endl << std::endl;

    return 0;
  }

  auto path = BF::path(argv[1]);
  //std::cerr << BF::current_path() << std::endl;

  if (!BF::exists(path)) {
    std::cerr << "File " << path << " does not exist." << std::endl;
    return 1;
  }

  BF::fstream finput;
  finput.open(path);
  read_template(finput);



}

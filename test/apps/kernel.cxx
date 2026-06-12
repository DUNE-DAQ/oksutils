/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from examples/kernel.cpp to test/apps/kernel.cxx).
 */

#include "oks/kernel.hpp"
#include "oks/class.hpp"

int main(int argc, char **argv)
{
  OksKernel k;

  if(argc != 2) return 1;

  k.load_schema(argv[1]);

  std::cout << "Schema file contains:\n";
  for(OksClass::Map::const_iterator i = k.classes().begin(); i != k.classes().end(); ++i)
    std::cout << "\t\"" << i->first << "\" class\n";

  return 0;
}

/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from examples/data.cpp to test/apps/data.cxx).
 */

#include "oks/attribute.hpp"
#include "oks/object.hpp"

int main()
{
  OksData d(new OksData::List()); /* creates list */

  d.data.LIST->push_back(new OksData((uint32_t)123456789));
  d.data.LIST->push_back(new OksData((double)123.456789));
  d.data.LIST->push_back(new OksData(boost::posix_time::second_clock::universal_time()));
  d.data.LIST->push_back(new OksData("Class-X", "Obj-1"));
  
  std::cout.precision(9); /* default is 6 */
  std::cout << d << std::endl;

  return 0;
}

/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from examples/comparator.cpp to test/apps/comparator.cxx).
 */

#include "oks/attribute.hpp"
#include "oks/query.hpp"

int main()
{
  try
    {
      const OksAttribute a("Name", OksAttribute::string_type, false, "", "unknown", "describes address", true);

      OksComparator qc(&a, new OksData("Peter"), OksQuery::equal_cmp);

      std::cout << qc << std::endl;
    }
  catch (const std::exception& ex)
    {
      std::cerr << "Caught exception:\n" << ex.what() << std::endl;
    }
 
  return 0;
}

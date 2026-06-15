//
// DUNE DAQ modification notice:
// This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
// Fork baseline commit: c2e7dfc7 (2022-03-30).
// Renamed since fork: yes (from examples/relationship.cpp to test/apps/relationship.cxx).
//

#include "oks/relationship.hpp"

int main()
{
  try
    {
      OksRelationship r(
	"consists of", /* name */
	"Element", /* class type */
	OksRelationship::Zero, /* low cc in Zero */
	OksRelationship::Many, /* high cc is Many */
	true, /* is composite */
	true, /* is exclusive */
	true, /* is dependent */
	"A structure consists of zero or many elements" /* description */
      );

      std::cout << r;
    }
  catch (const std::exception& ex)
    {
      std::cerr << "Caught exception:\n" << ex.what() << std::endl;
    }

  return 0;
}

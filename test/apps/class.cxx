//
// DUNE DAQ modification notice:
// This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
// Fork baseline commit: c2e7dfc7 (2022-03-30).
// Renamed since fork: yes (from examples/class.cpp to test/apps/class.cxx).
//

#include "oks/class.hpp"
#include "oks/attribute.hpp"
#include "oks/relationship.hpp"

int main()
{
  try
    {
      OksClass * c = new OksClass(
            "Person", /* class name */
            "Describes a person", /* description */
            false, /* is not abstract */
            0 /* no kernel */
      );
	
      OksAttribute * a = new OksAttribute(
            "Name",
            OksAttribute::string_type,
            false,
            "",
            "Unknown",
            "Describes person name",
            true
      );

      OksRelationship * r = new OksRelationship(
            "Works at",
            "Department",
            OksRelationship::Zero, OksRelationship::Many,
            false, false, false,
            "Can have many work places"
      );

      c->add(a); /* add attribute to class */
      c->add(r); /* add relationship to class */

      std::cout << "Class description is:\n" << *c << std::endl;

      OksClass::destroy(c);
    }
  catch (const std::exception & ex)
    {
      std::cerr << "Caught exception: " << ex.what() << std::endl;
    }

  return 0;
}

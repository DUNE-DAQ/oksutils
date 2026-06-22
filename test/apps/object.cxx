//
// DUNE DAQ modification notice:
// This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
// Fork baseline commit: c2e7dfc7 (2022-03-30).
// Renamed since fork: yes (from examples/object.cpp to test/apps/object.cxx).
//

#include "oks/kernel.hpp"
#include "oks/class.hpp"
#include "oks/object.hpp"

int main()
{
  try
    {
      OksKernel k;                         // create OKS kernel

      k.set_silence_mode(true);
      k.new_schema("/tmp/test.schema.xml"); // create new schema
      k.new_data("/tmp/test.data.xml");     // create new data

      // define class 'Person'
      OksClass * p = new OksClass("Person", "Describes a person", false, &k);

      // define attribute 'Name'
      OksAttribute * n = new OksAttribute("Name", OksAttribute::string_type, false, "", "Unknown", "is used to set person's name", true);

      // define attribute 'Birthday'
      OksAttribute * a = new OksAttribute("Birthday", OksAttribute::date_type, false, "", "1997-04-19", "is used to set person's birthday", true);

      // add attributes to class
      p->add(n);
      p->add(a);

      // create object
      OksObject * o = new OksObject(p, "aPerson");

      // change 'Name'
      OksData d("Peter");
      o->SetAttributeValue("Name", &d);

      std::cout << *o;
    }
  catch (const std::exception & ex)
    {
      std::cerr << "Caught exception: " << ex.what() << std::endl;
    }

  return 0;
}

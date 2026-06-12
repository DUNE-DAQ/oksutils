/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from examples/attribute.cpp to test/apps/attribute.cxx).
 */

#include "oks/attribute.hpp"

int main()
{
  try
    {
      //  create simple attribute
      OksAttribute a(
	"Address", /* name is 'Address' */
	OksAttribute::string_type, /* the type is 'string' */
	false, /* attribute is 'single value' */
	"", /* any range */
	"unknown", /* initial value */
	"describes address", /* desription */
	true /* can not be empty */
      );

      std::cout << a;


      // check multi-value attribute's  get_init_values()
      OksAttribute b(
	"Numbers",
	OksAttribute::s32_int_type,
	true, /* attribute is 'multi-value' */
	"",
	"1,2, 4, 9, 16, 25, \"36\", \'49\',\'64\',81, 100",
	"just a test",
	true
      );

      std::cout << b;


      std::list<std::string> init_vals = b.get_init_values();
  
      std::cout << "initial values of attribute \"" << b.get_name() << "\" are:\n";
  
      for(auto & i : init_vals)
        {
          std::cout << " - \'" << i << '\'' << std::endl;
        }
    }
  catch (const std::exception& ex)
    {
      std::cerr << "Caught exception:\n" << ex.what() << std::endl;
    }

  return 0;
}

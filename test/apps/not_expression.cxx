/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from examples/not_expression.cpp to test/apps/not_expression.cxx).
 */

#include "oks/attribute.hpp"
#include "oks/query.hpp"

int main()
{
  OksAttribute a(
        "age",
        OksAttribute::u16_int_type,
        false,
	"",
        "33",
        "describes age",
        true
  );
 
  OksNotExpression ne(new OksComparator(&a, new OksData((unsigned short)25), OksQuery::less_cmp));

  std::cout << ne << std::endl;
 
  return 0;
}

/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
 * Fork baseline commit: c2e7dfc7 (2022-03-30).
 * Renamed since fork: yes (from examples/and_expression.cpp to test/apps/and_expression.cxx).
 */

#include "oks/attribute.hpp"
#include "oks/query.hpp"

int main()
{
  OksAttribute a(
        "Weight",
        OksAttribute::float_type,
        false,
	"",
        "75",
        "person's weight",
        true
  );
 
  OksAndExpression and_q;

	/* Looking for 60 >= weight <= 90 */

  and_q.add(new OksComparator(&a, new OksData((float)60.0), OksQuery::greater_or_equal_cmp));
  and_q.add(new OksComparator(&a, new OksData((float)90.0), OksQuery::less_or_equal_cmp));

  std::cout << and_q << std::endl;
 
  return 0;
}

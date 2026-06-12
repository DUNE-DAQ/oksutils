/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from examples/or_expression.cpp to test/apps/or_expression.cxx).
 */

#include "oks/attribute.hpp"
#include "oks/query.hpp"

int main()
{
  OksAttribute a(
        "Heigth",
        OksAttribute::float_type,
        false,
	"",
        "1.77",
        "person's heigth",
        true
  );
 
  OksOrExpression or_q;

	/* Looking for tall (h >= 1.88) and short (h <= 1.65) */

  or_q.add(new OksComparator(&a, new OksData((float)1.65), OksQuery::greater_or_equal_cmp));
  or_q.add(new OksComparator(&a, new OksData((float)1.88), OksQuery::less_or_equal_cmp));

  std::cout << or_q << std::endl;
 
  return 0;
}

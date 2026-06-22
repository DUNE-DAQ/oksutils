//
// DUNE DAQ modification notice:
// This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
// Fork baseline commit: c2e7dfc7 (2022-03-30).
// Renamed since fork: yes (from examples/r_expression.cpp to test/apps/r_expression.cxx).
//

#include "oks/attribute.hpp"
#include "oks/relationship.hpp"
#include "oks/query.hpp"

int main()
{
  OksRelationship r(
	"has car", "Car",
	OksRelationship::Zero, OksRelationship::Many,
	true, true, false,
	"A person has zero or more cars"
  );

  OksAttribute a(
	"Type",
	OksAttribute::string_type,
	false,
	"",
	"unknown",
	"describes car type",
	true
  );

 
  OksRelationshipExpression rqe(&r, new OksComparator(&a, new OksData("BMW"), OksQuery::equal_cmp), false);

  std::cout << rqe << std::endl;
 
  return 0;
}

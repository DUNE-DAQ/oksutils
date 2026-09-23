#include "oks/attribute.hpp"
#include "oks/query.hpp"
#include "oks/relationship.hpp"

int
main()
{
  OksRelationship r("has car",
                    "Car",
                    OksRelationship::Zero,
                    OksRelationship::Many,
                    true,
                    true,
                    false,
                    "A person has zero or more cars");

  OksAttribute a("Type", OksAttribute::string_type, false, "", "unknown", "describes car type", true);

  OksRelationshipExpression rqe(&r, new OksComparator(&a, new OksData("BMW"), OksQuery::equal_cmp), false);

  std::cout << rqe << std::endl;

  return 0;
}

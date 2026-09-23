#include "oks/attribute.hpp"
#include "oks/query.hpp"

int
main()
{
  OksAttribute a("age", OksAttribute::u16_int_type, false, "", "33", "describes age", true);

  OksNotExpression ne(new OksComparator(&a, new OksData((unsigned short)25), OksQuery::less_cmp));

  std::cout << ne << std::endl;

  return 0;
}

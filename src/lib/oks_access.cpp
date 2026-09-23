
#include "oksutils/oks/access.hpp"

namespace dunedaq {
// JCF, Dec-2-2022: on Andrei Kazarov's recommendation, I stubbed out the origin AccessManager-based code

bool
oksutils::access::is_writable(const oks::OksFile& /*file*/, const std::string& /*user*/)
{
  return true;
}
}

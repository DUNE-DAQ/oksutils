/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: no.
 */


#include "oksutils/oks/access.hpp"

namespace dunedaq {
// JCF, Dec-2-2022: on Andrei Kazarov's recommendation, I stubbed out the origin AccessManager-based code

bool
oksutils::access::is_writable(const oks::OksFile& /*file*/,
                              const std::string& /*user*/)
{
  return true; 
}
}

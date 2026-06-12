/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from oks/access.h to include/oksutils/oks/access.hpp).
 */

#ifndef OKS_ACCESS_H
#define OKS_ACCESS_H

#include "oks/kernel.hpp"

namespace dunedaq {
namespace oksutils {
  namespace access
  {
    /**
     * The function tests write access to database file.
     *
     * If the file is stored on OKS server repository, it checks access
     * permissions using Access Manager service. In this case optional user
     * name can be provided instead of current user taken by default.
     *
     * Otherwise it checks file system directory permissions for current user.
     */

    bool
    is_writable(const oks::OksFile& file,
                const std::string& user = oks::OksKernel::get_user_name());
  } // namespace access
} // namespace oksutils
} // namespace dunedaq

#endif

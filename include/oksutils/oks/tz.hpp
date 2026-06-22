//
// DUNE DAQ modification notice:
// This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
// Fork baseline commit: c2e7dfc7 (2022-03-30).
// Renamed since fork: yes (from oks/tz.h to include/oksutils/oks/tz.hpp).
//

#ifndef OKS_TZ_H
#define OKS_TZ_H

#include <string>
#include <vector>

#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/ptime.hpp>

namespace oks
{
  namespace tz
  {

    /**
     * The class provides access to Boost time-zone database.
     * It relies on Boost time-zone database file installed by oksutils package
     * and pointed by BOOST_DATE_TIME_TZ_SPEC process environment variable.
     */

    class DB
    {
    public:

      /**
       * Find and read Boost time-zone database.
       */
      DB();

      /**
       *  \brief Get boost time-zone pointer from string.
       *
       *  This is a helper method for several utilities dealing with Boost time-zone database.
       *
       *  \param    region name of time zone
       *  \return   time-zone boost pointer
       *  \throw    std::exception if something goes wrong
       */
      boost::local_time::time_zone_ptr
      get_tz_ptr(const std::string& region);

      /**
       *  \brief Get known time zone regions.
       *
       *  This is a helper function for several utilities dealing with Boost time-zone database.
       *
       *  \return   vector of known regions
       *  \throw    std::exception if something goes wrong
       */
      std::vector<std::string>
      get_regions();

    private:
      boost::local_time::tz_database m_tz_db;
    };

    boost::posix_time::ptime
    str_2_posix_time(const std::string& in, boost::local_time::time_zone_ptr tz_ptr, const char * value);

    uint64_t
    posix_time_2_to_ns(boost::posix_time::ptime t);

    std::string
    posix_time_2_iso_string(boost::posix_time::ptime t);
  }
}

#endif

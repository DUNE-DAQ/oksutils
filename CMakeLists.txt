# DUNE DAQ modification notice:
# This file has been modified from the original ATLAS oks source for the DUNE DAQ project.
# Fork baseline commit: 26f3bea2 (2022-11-29).
# Renamed since fork: no.

cmake_minimum_required(VERSION 3.12)
project(oksutils VERSION 1.0.0)

find_package(daq-cmake REQUIRED)

daq_setup_environment()

find_package(oks REQUIRED)
find_package(Boost COMPONENTS date_time program_options system REQUIRED)
find_package(ers REQUIRED)
find_package(logging REQUIRED)

daq_add_library(lib/*.cpp LINK_LIBRARIES Boost::date_time oks::oks ers::ers)

daq_add_application(oks_report_equal_objects   oks_report_equal_objects.cxx   LINK_LIBRARIES oksutils Boost::program_options)
daq_add_application(oks_report_no_descriptions oks_report_no_descriptions.cxx LINK_LIBRARIES oksutils )
daq_add_application(oks_merge                  oks_merge.cxx                  LINK_LIBRARIES oksutils)
daq_add_application(oks_refresh                oks_refresh.cxx                LINK_LIBRARIES oksutils Boost::program_options)
daq_add_application(oks_diff_data              oks_diff_data.cxx              LINK_LIBRARIES oksutils)
daq_add_application(oks_diff_schema            oks_diff_schema.cxx            LINK_LIBRARIES oksutils)
daq_add_application(oks_tutorial               oks_tutorial.cxx               LINK_LIBRARIES oksutils)

daq_add_application(oksutils_alloc_test       alloc.cxx               TEST      LINK_LIBRARIES oksutils Boost::system )

# JCF: seems potentially worthwhile to build some of the other executables which are currently ignored in test/apps...

daq_install()


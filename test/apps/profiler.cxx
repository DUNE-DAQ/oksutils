/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from examples/profiler.cpp to test/apps/profiler.cxx).
 */

#include "oks/kernel.hpp"
#include "oks/class.hpp"

int main(int argc, char **argv)
{
  OksKernel k;

  if(argc != 3) return 1;

  k.set_profiling_mode(true);
  k.load_schema(argv[1]);
  k.load_data(argv[2]);

  return 0;
}

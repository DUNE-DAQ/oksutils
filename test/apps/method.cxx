/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
 * Fork baseline commit: 26f3bea2 (2022-11-29).
 * Renamed since fork: yes (from examples/method.cpp to test/apps/method.cxx).
 */

#include "oks/method.hpp"

int main()
{
  OksMethod m(
    "print",       /* name */
    "it is a test" /* description */
  );

  m.add_implementation(
    "c++",
    "void print(const char * s)",
    "std::cout << s << std::endl;"
  );

  m.add_implementation(
    "c",
    "void print(const char * s)",
    "printf(\"%s\\n\", s);"
  );

  std::cout << m;

  return 0;
}

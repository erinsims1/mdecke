/**
 * @file test_default_ctor.cpp
 *
 * Tests bigint default ctor.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <cassert>
#include "bigint.hpp"

int main() {

  {

    // setup
    bigint b;

    // test

    // verification
    assert(b == 0);

  }

  return 0;
}

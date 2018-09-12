/**
 * @file test_concat.cpp
 *
 * Tests String class operator+
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"
#include <cassert>


#include <iostream>

//===========================================================================
int main () {


    // setup
    String lhs;
    String rhs("");

    // test
    String result = lhs + rhs;   
    
    // verification
    assert(lhs == "");
    assert(rhs == "");
    assert(result == "");
    assert(result.length() == 0);

    return 0;
}


/**
 * @file main.cpp
 *
 * This is a generic C++ main file.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include "bigint.hpp"

int main(int argc, char * argv[]) {

    {
	bigint b(5);
	bigint c = b.times_10(fg
);
	c.debug_print(std::cout);
    }

    return 0;
}

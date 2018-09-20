#define BOOST_TEST_MODULE test equals
#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>
#include "complex.hpp"

namespace bu = boost::unit_test;

/** can have no variable then it will have generic sample variable */
/** zipper different things */
const complex complex_data[] = { complex(0, 0), complex(10,1) };
BOOST_DATA_TEST_CASE(equal_simple, bu::data::xrange(2) ^ bu::data::make(complex_data), num, value) {
    std::cerr << num << ": " << value << '\n';
    BOOST_TEST(value == value);
}

const complex complex_data_lhs[] = { complex(11, 1), complex(11,1), complex(11,1) };
const complex complex_data_rhs[] = { complex(11, 2), complex(12,1), complex(12,2) };
BOOST_DATA_TEST_CASE(equal_not, bu::data::make(complex_data_lhs) ^ bu::data::make(complex_data_rhs), lhs, rhs) {
    BOOST_TEST_MESSAGE(lhs << " == " << rhs);
    BOOST_TEST(!(lhs == rhs));
}

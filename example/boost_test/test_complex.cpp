#define BOOST_TEST_MODULE complex
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <iostream>

#include "complex.hpp"

namespace bu = boost::unit_test;

/** can organize into test suites first show inplace on non datasets, then on data sets and include */
#include "test_equals.datasets.hpp"
#include "test_add.datasets.hpp"

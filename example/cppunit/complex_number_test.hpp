/**
 * @file complex_number_test.hpp
 *
 * Illustrates test case.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#ifndef INCLUDED_COMPLEX_NUMBER_TEST_HPP
#define INCLUDED_COMPLEX_NUMBER_TEST_HPP

#include "complex.hpp"
#include <TestFixture.h>
/** add for suite */
#include <TestSuite.h>
#include <TestCaller.h>
/** add for more complex macros */
#include <extensions/HelperMacros.h>

class complex_number_test : public CppUnit::TestFixture {
private:
  complex * ten_one;
  complex * one_one;
  complex * eleven_two;
public:

  /** One setup for each method, may want seperate setup/teardown or several levels of setup */
  void setUp() {
    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
    ten_one = new complex(10, 1);
    one_one = new complex(1, 1);
    eleven_two = new complex(11, 2);
  }

  void tearDown() {
    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
    delete ten_one;
    delete one_one;
    delete eleven_two;
  }

  /** These should really be separate. */
  void testEquality() {
    CPPUNIT_ASSERT(*ten_one == *ten_one);
    CPPUNIT_ASSERT(!(*ten_one == *eleven_two));
    //CPPUNIT_ASSERT(false);
  }

  void testAddition() {
    CPPUNIT_ASSERT(*ten_one + *one_one == *eleven_two);
    //CPPUNIT_ASSERT(false);
  }

  /** add to show assert throw */
  void testDivideByZero() {
    // throws invalid argument
    *ten_one / complex();
  }

   /** A lot of code and common to forget to add. Error prone. */
  /*
  static CppUnit::Test * suite() {
    CppUnit::TestSuite * test_suite = new CppUnit::TestSuite( "complex_number_test" );
    test_suite->addTest( new CppUnit::TestCaller<complex_number_test>( 
								      "testEquality", 
								      &complex_number_test::testEquality ) );
    test_suite->addTest( new CppUnit::TestCaller<complex_number_test>(
								      "testAddition",
								      &complex_number_test::testAddition ) );
    return test_suite;
  }
  */

  CPPUNIT_TEST_SUITE(complex_number_test);
    CPPUNIT_TEST(testEquality);
    CPPUNIT_TEST(testAddition);
    /** specifiy it throws */
  CPPUNIT_TEST_EXCEPTION(testDivideByZero, std::invalid_argument);
  CPPUNIT_TEST_SUITE_END();

};

#endif

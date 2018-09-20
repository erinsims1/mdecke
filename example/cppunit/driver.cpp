/**
 * @file driver.cpp
 *
 * Runs complex unit tests.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <TestSuite.h>
//#include <TestCaller.h>
//#include <TestResult.h>
#include <ui/text/TestRunner.h>
//#include "complex_number_test.hpp"
#include <extensions/TestFactoryRegistry.h>

int main(int argc, char * argv[]) {

  /** Not useful, no statistics, some annoying setup.  Show setup/teardown begin called */
  //CppUnit::TestCaller<complex_number_test> test( "testEquality", 
  //					       &complex_number_test::testEquality );
  //CppUnit::TestResult result;
  //test.run( &result );

  /** What to have a collection of tests, i.e., a suite.  But what if have multiple suites
      This is also a lot of code that does not necessarily belong here. */
  //CppUnit::TestSuite suite;
  //CppUnit::TestResult result;
  //suite.addTest( new CppUnit::TestCaller<complex_number_test>(
  //							    "testEquality", 
  //							    &complex_number_test::testEquality ) );
  //suite.addTest( new CppUnit::TestCaller<complex_number_test>(
  //							    "testAddition", 
  //							    &complex_number_test::testAddition ) );
  //suite.run( &result );

  /** Combine suites.  Which would provided a better means of separating tests.  Still no statistics */
  //CppUnit::TestSuite suite;
  //CppUnit::TestResult result;
  //suite.addTest( complex_number_test::suite() );
  //suite.addTest( SurrealNumberTest::suite() );
  //suite.addTest( SurrealNumberTest::suite() );
  //suite.addTest( complex_equals_test::suite() );
  //suite.addTest( complex_add_test::suite() );
  //suite.run( &result );

  /** statistics.  However, need to have header of all tests
      and remember to edit this.  Error prone.  You gonna forget */
  //CppUnit::TextUi::TestRunner runner;
  //runner.addTest(complex_number_test::suite());
  //runner.addTest(ExampleTestCase::suite());
  //runner.run();

  /** so do not forget to add suite to runner and avoid include all test file headers */
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry & registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest(registry.makeTest());
  //runner.run();
  /** run(test path, wait)? */
  return !runner.run( "", false );
}

/**
 * @file test_driver.cpp
 *
 * Runs String unit tests.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <TestSuite.h>
#include <ui/text/TestRunner.h>
#include <extensions/TestFactoryRegistry.h>

int main(int argc, char * argv[]) {

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry & registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());

    return !runner.run( "", false );
}

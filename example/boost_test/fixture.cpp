#define BOOST_TEST_MODULE fixture
#include <boost/test/included/unit_test.hpp>
#include "complex.hpp"

struct fixture
{
    std::string s;
    fixture(std::string s = "fixture") : s(s)
	{ BOOST_TEST_MESSAGE("ctor " << s); }
    void setup()
	{ BOOST_TEST_MESSAGE("optional setup " << s); }
    void teardown()
	{ BOOST_TEST_MESSAGE("optional teardown " << s); }
    ~fixture()
    { BOOST_TEST_MESSAGE("dtor " << s); }
};

void setup() { BOOST_TEST_MESSAGE("free setup"); }
void teardown() { BOOST_TEST_MESSAGE("free teardown"); }

/** start  with original auto test and show various ways of adding fixtures 
    - auto free function
    - auto test object - no access to members
    - fixture test object
    - auto/fixture suite object 
        - auto only once construct/destruct, fixture each case construct/destruct.
	- fixture does not call setup/teardown UNLESS compiled with >= C++11
*/

// suite level
//BOOST_AUTO_TEST_SUITE(equals_suite, *boost::unit_test::fixture<fixture>(std::string("FX")))
BOOST_FIXTURE_TEST_SUITE(equals_suite, fixture)


BOOST_AUTO_TEST_CASE(equals_simple_1) {
    BOOST_TEST_MESSAGE("test 1");
    complex zero_one(0, 0);
    complex zero_two(0, 0);
   
    BOOST_TEST(zero_one == zero_two);
}

// case level
BOOST_AUTO_TEST_CASE(equals_simple_2/*, fixture*/) {
    BOOST_TEST_MESSAGE("test 2 " + s);
    complex num_one(10, 1);
    complex num_two(10, 1);
   
    BOOST_TEST(num_one == num_two);
}

// case level free functions
BOOST_AUTO_TEST_CASE(equals_not_1, *boost::unit_test::fixture(&setup, &teardown)) {
    BOOST_TEST_MESSAGE("test 3");
    complex num_one(11, 1);
    complex num_two(11, 2);
   
    BOOST_TEST(!(num_one == num_two));
}

BOOST_AUTO_TEST_CASE(equals_not_2) {
    BOOST_TEST_MESSAGE("test 4");    
    complex num_one(11, 1);
    complex num_two(12, 1);
   
    BOOST_TEST(!(num_one == num_two));
}

BOOST_AUTO_TEST_CASE(equals_not_3) {
    
    complex num_one(11, 1);
    complex num_two(12, 2);
   
    BOOST_TEST(!(num_one == num_two));
}

BOOST_AUTO_TEST_SUITE_END()

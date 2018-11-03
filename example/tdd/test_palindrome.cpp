#define BOOST_TEST_MODULE palindrome
#include <boost/test/included/unit_test.hpp>
#include "palindrome.hpp"


/**
 * In-class - write the steps.
 * Steps:
 *   1. Add a test
 *   2. Make sure fails - test harness works, not a bad test (red phase)
 *   3. Make it work
 *   4. Run tests - all should pass (green phase)
 *   5. Refactor - Code from previous step for may be inelegant
 *   6. Repeat - small steps each time.
 *
 *   May write tests that actually pass.  Important test is adding someething.
 *   In debugging, I often find holes in the testing pattern, and insert more fine-grained
 */

/** write first then start palindrome */
BOOST_AUTO_TEST_CASE(empty) {

    BOOST_TEST(is_palindrome(""));

}

/** There are tests I would write next, because */
/** generally you write one that would fail, goal is to be incremental in development and the test something new.  So fine if passes.
    but will sort of motivate that with.  Next test would be "a" */

/** fails, fix */
BOOST_AUTO_TEST_CASE(two_char_different) {

    BOOST_TEST(!is_palindrome("ab"));

}

/** oops does not work, minimal fix */
BOOST_AUTO_TEST_CASE(single_char) {

    BOOST_TEST(is_palindrome("a"));

}

/** ahh man, again */
BOOST_AUTO_TEST_CASE(two_char_same) {

    BOOST_TEST(is_palindrome("aa"));

}

/** passes */
BOOST_AUTO_TEST_CASE(three_char_is) {

    BOOST_TEST(is_palindrome("aba"));

}

BOOST_AUTO_TEST_CASE(three_char_not) {

    BOOST_TEST(!is_palindrome("abb"));

}

/** getting too long for shenanigans */
BOOST_AUTO_TEST_CASE(general_even) {

    BOOST_TEST(is_palindrome("redder"));

}

/** aa gets middle and end points, so these are they differ somewhere inside those bounds*/
BOOST_AUTO_TEST_CASE(general_even_not) {

    BOOST_TEST(!is_palindrome("radder"));

}

/** odd longer works */
BOOST_AUTO_TEST_CASE(general_odd) {

    BOOST_TEST(is_palindrome("racecar"));

}

/** Longer odd - not really high value 
https://en.wikipedia.org/wiki/Echidna
https://en.wikipedia.org/wiki/Knuckles_the_Echidna
*/
BOOST_AUTO_TEST_CASE(general_odd_not) {

    BOOST_TEST(!is_palindrome("echidna"));

}

/** Do spaces count, could also do caseing... but will stop here. */
BOOST_AUTO_TEST_CASE(sentence_is) {

    BOOST_TEST(is_palindrome("step on no pets"));

}

BOOST_AUTO_TEST_CASE(sentence_not) {

    BOOST_TEST(!is_palindrome("was it a car or a cat I saw"));

}

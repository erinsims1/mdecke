#define BOOST_TEST_MODULE test output
#include <boost/test/included/unit_test.hpp>
#include "complex.hpp"

#include <boost/test/output_test_stream.hpp>
namespace bt = boost::test_tools;

/** explicit matching or match a pattern file. */
BOOST_AUTO_TEST_CASE(output_zero) {
    
    /** automates somethings with output testing */

    bt::output_test_stream output;
    complex zero_one(0, 0);   
    output << zero_one;

    // false is so do not flush buffer
    BOOST_TEST( !output.is_empty( false ) );
    BOOST_TEST( output.check_length( 6, false ) );
    // one less function call, if reuse no need to flush, etc.
    BOOST_TEST( output.is_equal( "0 + 0i" ) );

}

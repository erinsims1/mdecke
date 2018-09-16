BOOST_AUTO_TEST_SUITE(test_equality)

BOOST_AUTO_TEST_CASE(equals) {
    String s = "abc";
    String t = "abc";

    BOOST_TEST(s == t);
}

BOOST_AUTO_TEST_CASE(not_equals) {
    String s = "abc";
    String t = "xyz";

    BOOST_TEST(!(s == t));
}

BOOST_AUTO_TEST_SUITE_END()

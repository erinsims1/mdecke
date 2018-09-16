BOOST_AUTO_TEST_SUITE(test_cstring_ctor)


BOOST_AUTO_TEST_CASE(typical) {
    String s("abc");

    BOOST_TEST(s[0] == 'a');
    BOOST_TEST(s[1] == 'b');
    BOOST_TEST(s[2] == 'c');
    BOOST_TEST(s.length() == 3);
    BOOST_TEST(s.capacity() == (STRING_SIZE - 1));
}

BOOST_AUTO_TEST_SUITE_END()

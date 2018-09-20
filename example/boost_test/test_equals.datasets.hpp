
BOOST_AUTO_TEST_SUITE(test_equals)

const complex complex_data[] = { complex(0, 0), complex(10,1) };
BOOST_DATA_TEST_CASE(equal_simple, bu::data::xrange(2) ^ bu::data::make(complex_data), num, value) {
    BOOST_TEST_MESSAGE(num << ": " << value);
    BOOST_TEST(value == value);
}

const complex complex_data_lhs[] = { complex(11, 1), complex(11,1), complex(11,1) };
const complex complex_data_rhs[] = { complex(11, 2), complex(12,1), complex(12,2) };
BOOST_DATA_TEST_CASE(equal_not, bu::data::make(complex_data_lhs) ^ bu::data::make(complex_data_rhs), lhs, rhs) {
    BOOST_TEST_MESSAGE(lhs << " == " << rhs);
    BOOST_TEST(!(lhs == rhs));
}
BOOST_AUTO_TEST_SUITE_END()

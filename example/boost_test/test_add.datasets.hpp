BOOST_AUTO_TEST_SUITE(test_add)

const complex complex_data_lhs[] = { complex(0, 0), complex(1,0), complex(0,1), complex(120, 140) };
const complex complex_data_rhs[] = { complex(0, 0), complex(2,0), complex(0,2), complex(15,10) };
const complex complex_data_result[] = { complex(0, 0), complex(3,0), complex(0,3), complex(135, 150) };
BOOST_DATA_TEST_CASE(add, 
		     bu::data::make(complex_data_lhs) ^ bu::data::make(complex_data_rhs) ^ bu::data::make(complex_data_result),
		     lhs, rhs, expected_result) {

  complex actual_result = lhs + rhs;
  BOOST_TEST_MESSAGE(lhs << " + " << rhs << " = " << actual_result);

  BOOST_TEST(actual_result == expected_result);
}

BOOST_AUTO_TEST_SUITE_END()

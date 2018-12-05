/**
 * @file test_calculator.cpp
 *
 * Show Turtle Mocking framework for calculator class
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#define BOOST_TEST_MODULE test calculator
#include <boost/test/included/unit_test.hpp>
#include <turtle/mock.hpp>

#include <iostream>

class view_t {
public:
    virtual void display(int result) = 0;
}

class calculator_t {
private:
    view_t & view;
public:
    calculator_t(view_t & view) : view(view) {}
    int add(int a, int b) { return view.display(a + b); );
};

MOCK_BASE_CLASS(mock_view, view) {
    // list methods need implemented
    MOCK_METHOD(display, 1);

};

BOOST_AUTO_TEST_CASE(zero_plus_zero_is_zero) {
    // create mock object
    mock_view view;

    // create the object under test
    calculator_t calculator(view);

    // encode expectations
    MOCK_EXPECT(view.display).once().with(0)


    // excersize object under test
    calculator.add(0,0);

}

//
// Created by PC-N-XXX on 15.03.2022.
//


#define BOOST_TEST_MODULE My first test module
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API


#include <boost/test/included/unit_test.hpp>
BOOST_AUTO_TEST_CASE(first_test_function)
{
    BOOST_TEST(true);
}
int main(int argc, char* argv[])
{
    return boost::unit_test::unit_test_main(init_unit_test, argc, argv);
}


//
// Created by Sezer Çakır on 15.03.2022.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "dynamic_array.hpp"
#include "exception.hpp"

BOOST_AUTO_TEST_CASE(first_test_function)
{
    BOOST_TEST(true);
}
BOOST_AUTO_TEST_CASE(second_test_func)
{
    BOOST_TEST(true);
}

// Test Suit
BOOST_AUTO_TEST_SUITE(TestSuitName)

// Test Cases
BOOST_AUTO_TEST_CASE(suite1_test_func)
{
    BOOST_TEST(true);
}
BOOST_AUTO_TEST_CASE(suite2_test_func)
{
    BOOST_TEST(true);
}
BOOST_AUTO_TEST_CASE(testWarn)
    {
        BOOST_TEST_WARN( 2 == 2);
    }


BOOST_AUTO_TEST_SUITE_END()

// Test Suit of Test Suit
BOOST_AUTO_TEST_SUITE(DataBaseTest)
// A Test Suit
BOOST_AUTO_TEST_SUITE(AddTests)

// Test Cases
BOOST_AUTO_TEST_CASE(addUser)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(addWrongUser)
{
    BOOST_TEST(false);
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

// Precondition, Describtion, Label Decorators
BOOST_AUTO_TEST_SUITE(suite1, *boost::unit_test::disabled())

    BOOST_AUTO_TEST_CASE(test1)
    {
        BOOST_TEST(1 != 1);
    }

    BOOST_AUTO_TEST_CASE(test2, *boost::unit_test::description("Not Equal 2s")
                                *boost::unit_test::label("given label")
                                *boost::unit_test::enabled())
    {
        BOOST_TEST(2 != 2);
    }

BOOST_AUTO_TEST_SUITE_END()


// Dependency Decorator
BOOST_AUTO_TEST_CASE(test3, *boost::unit_test::depends_on("s1/test1"))
{
    BOOST_TEST(false);
}

BOOST_AUTO_TEST_CASE(test4, *boost::unit_test::depends_on("test3"))
{
    BOOST_TEST(false);
}

BOOST_AUTO_TEST_CASE(test5, *boost::unit_test::depends_on("s1/test2"))
{
    BOOST_TEST(false);
}

BOOST_AUTO_TEST_SUITE(s1)

    BOOST_AUTO_TEST_CASE(test1)
    {
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(test2, *boost::unit_test::disabled())
    {
        BOOST_TEST(false);
    }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(Exceptions)
BOOST_AUTO_TEST_CASE(ThrowTest)
{
    DB database{"DB",2};
    BOOST_CHECK_THROW(database.resize(), my_exception);
}
BOOST_AUTO_TEST_SUITE_END()


struct Fixture {
    Fixture() : i( 0 ) { BOOST_TEST_MESSAGE( "setup fixture" ); }
    ~Fixture()         { BOOST_TEST_MESSAGE( "teardown fixture" ); }
    int i;
};

BOOST_AUTO_TEST_SUITE(suiteMain)
    BOOST_FIXTURE_TEST_SUITE(insideSuit,Fixture)

    BOOST_AUTO_TEST_CASE(case1)
    {
        BOOST_TEST(i == 0);
    }
    BOOST_AUTO_TEST_CASE(case2)
    {
        i++;
        BOOST_TEST(i == 1);
    }

    BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

struct Fixture2 {
    Fixture2() : i_2( 0 ) { BOOST_TEST_MESSAGE( "setup fixture" ); }
    ~Fixture2()         { BOOST_TEST_MESSAGE( "teardown fixture" ); }
    int i_2;
};


BOOST_FIXTURE_TEST_SUITE(suite_2)
    BOOST_AUTO_TEST_CASE(case1)
    {
        BOOST_TEST(i == 0);
        i++;
    }
    BOOST_FIXTURE_TEST_CASE(case2, Fixture)
    {
        BOOST_TEST(i == 0);
    }
BOOST_AUTO_TEST_SUITE_END()






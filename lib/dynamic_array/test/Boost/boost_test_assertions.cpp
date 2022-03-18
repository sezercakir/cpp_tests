//
// Created by Sezer Çakır on 17.03.2022.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Assertions)
{
    BOOST_TEST((3 > 0 ? true : false));
    BOOST_TEST((3 > 2 && 4 < 5));

    BOOST_TEST_REQUIRE(3 == 4, "this is critical");
}

BOOST_AUTO_TEST_CASE(Manipulators)
{
    //BOOST_TEST(4.201 == 4.200, boost::test_tools::tolerance(0.001));
//
    //// Per element operator can compare diffrent type of datas.
    //std::vector<int> v{ 1,2,3 };
    //std::list<short> l{ 1,2,3 };
    //BOOST_TEST(v == l, boost::test_tools::per_element());
//


}

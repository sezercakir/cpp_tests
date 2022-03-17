//
// Created by Sezer Çakır on 15.03.2022.
//

#include "catch.hpp"
#include "dynamic_array.hpp"

SCENARIO("Dynamic Array Add Operation Test")
{
    GIVEN("User Data and Database Initial")
    {
        data user1{"Sezer", 1};
        data user2{"Çakır",2};

        DB database{"ExampleDB",5};

        WHEN("Add Operation Called")
        {
            database.addUser(user1);
            THEN("It's expacted that last element of DB is user1")
            {
                REQUIRE(user1.getName() == database.getUsers()[database.getCount()-1].getName());
            }
        }
    }
}


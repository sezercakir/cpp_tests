//
// Created by sezercakir on 7.03.2022.
//

#include "dynamic_array.hpp"

void DB::resize ()
{
    if (users != nullptr)
        throw my_exception("Logic Error");
    int newSize = size*2;
    data* newArr = new data[newSize];
    std::copy(users, users + std::min(size, newSize), newArr);
    size = newSize;
    delete[] users;
    users = newArr;
}

void DB::addUser (const data & user)
{
    if (count == size)
        resize();
    users[count] = user;
    count++;
    if (users[count-1].getName() == "HTU")
        throw my_exception("Adding Error");
}

void DB::delete_elmnt(const std::string& n) {
    data* ptr = users;
    int j = 0;
    for (int i = 0; i < count; i++) {
        if (users[i].getName() == n){
            users[j] = ptr[j+1];
        } else{
            users[j] = ptr[j];
        }
        j++;

    }
    count--;
    delete ptr;
}
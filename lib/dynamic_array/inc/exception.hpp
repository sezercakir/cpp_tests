//
// Created by sezercakir on 7.03.2022.
//

#ifndef CPP_APP_EXCEPTION_HPP
#define CPP_APP_EXCEPTION_HPP

#include <iostream>

class my_exception: public std::exception
{
    std::string what_message;
public:
    explicit my_exception(std::string  msg) : what_message(std::move(msg)){}
    my_exception()= default;
    const char* what() const noexcept override{
        return what_message.c_str();
    }
};
#endif //CPP_APP_EXCEPTION_HPP

//
// Created by sezercakir on 7.03.2022.
//

#ifndef CPP_APP_DYNAMIC_ARRAY_HPP
#define CPP_APP_DYNAMIC_ARRAY_HPP

#include <iostream>
#include "exception.hpp"

class data{
    std::string name;
    int ID;
public:
    data(std::string n, int id) : name(std::move(n)), ID(id){}
    data(){};
    std::string getName() const { return name;}
};

class DB{
    data* users;
    int size;
    std::string name;
    int count;
public:
    DB(std::string n, int s) : name(std::move(n)), size(s){
        count = 0;
        users = new data[s];
    }

    int getSize() const {
        return size;
    }
    static  void throwExc(){
        throw std::runtime_error("ABC") ;
    }

    void resize();
    data* getUsers() const { return users;}
    int getCount() const { return count;}
    void addUser(const data& user);
    void delete_elmnt(const std::string& n);

};

#endif //CPP_APP_DYNAMIC_ARRAY_HPP

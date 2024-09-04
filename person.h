#pragma once
#include <iostream>
#include <string>
using namespace std;

class person{
    public:
        person();
        void setName(string name); // sets the name
        void setEmail(string email); // sets the email
        string getName(); // return the name
        string getEmail(); // returns the email

    protected:
        string name;
        string email;
};
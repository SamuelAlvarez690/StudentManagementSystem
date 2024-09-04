#include "person.h"

// sets the variables to blank strings
person::person(){
    name = "";
    email = "";
}

// sets the name for a person
void person::setName(string n){
  name = n;
}

//sets the email for a person
void person::setEmail(string e){
  email = e;
}

// returns the name of a person
string person::getName(){
  return name;
}

//returns the email for a person
string person::getEmail(){
  return email;
}

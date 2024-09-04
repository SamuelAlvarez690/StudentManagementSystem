#pragma once
#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class teacher : public person{
    public:
        teacher();
        void setID(int ID);
        int getID();
        void updateSubjects(string newSub);
        
    private:
        int teacherID;
        string subjectsTaught[7];
        int numSubjects;
};
#pragma once
#include <iostream>
#include <string>
#include "person.h"

using namespace std;


class student : public person{
  public:
    student();
    void setID(int ID);
    int getID();
    void updateSchedule(string newSub);
    void markAttendance(int status, string className);
    void submitAssignment(int grade, string className);
    float calculateClassGrade(string className);
    void generateAttendanceReport(int startDate, int endDate, string Class);
    ~student();
  private:
    int studentID;
    string subjectsTaken[7];
    int subjects;
    int classAttendance[7];
    int classAssignments[7];
    int **attendStatus;
    int **assignments;
    
};